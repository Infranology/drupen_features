<?php

/**
 * @file
 * User (Drupal core) configuration tasks.
 */

/**
 * Configures the roles' permissions.
 */
function _drupen_admin_user_configure() {
  module_load_include('inc', 'drupen_admin', 'includes/drupen_admin.user_permission');

  // Set the roles permissions.
  drupen_user_save_permissions_roles(drupen_admin_user_permissions());
}
