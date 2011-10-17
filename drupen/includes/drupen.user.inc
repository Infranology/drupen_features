<?php

/**
 * @file
 * User (Drupal core) configuration tasks.
 */

/**
 * Creates the roles 'administrator', 'editor' and 'assistant'. Also configures
 * the Admin role module if available, setting 'administrator' as the
 * administrator role and updates the permissions.
 */
function _drupen_user_configure() {
  module_load_include('inc', 'drupen', 'includes/drupen.user_permission');

  // Roles.
  $roles = array(
    'administrator' => variable_get('drupen_role_administrator_rid', 0),
    'editor'        => variable_get('drupen_role_editor_rid', 0),
    'assistant'     => variable_get('drupen_role_assistant_rid', 0),
  );

  foreach ($roles as $role => $rid) {
    if (0 !== $rid) {
      continue;
    }

    $rid = db_result(db_query("SELECT rid FROM {role} WHERE name = '%s'", $role));

    if ($rid === FALSE) {
      db_query("INSERT INTO {role} (name) VALUES ('%s')", $role);
      $rid = db_last_insert_id('role', 'rid');
    }

    // The Admin Role creates the 'administrator' role during installation. If
    // reaching this point, the role or roles could be already set but don't
    // had the variable set in the drupen_role_rolename_rid variable.
    variable_set('drupen_role_' . $role . '_rid', $rid);
    $roles[$role] = $rid;
  }

  // Set the roles permissions.
  drupen_user_save_permissions_roles(drupen_user_permissions());

  // Set "administrator" as an adminrole and update permissions.
  if (module_exists('adminrole')) {
    variable_set('user_admin_role', $roles['administrator']);
    adminrole_update_permissions();
  }

  // Set the "administrator" (uid 1) an "admnistrator" (only to make Better
  // Formats works to this user too).
  $has_role = db_result(db_query('SELECT uid FROM {users_roles} WHERE uid = %d AND rid = %d', 1, $roles['administrator']));

  if (FALSE === $has_role) {
    db_query('INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)', 1, $roles['administrator']);
  }

  return $roles;
}
