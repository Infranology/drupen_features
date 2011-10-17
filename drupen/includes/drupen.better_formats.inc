<?php

/**
 * @file
 * Better Formats configuration tasks.
 */

/**
 * Configures the Better Formats module. It will setup the module to allow the
 * 'administrator', 'editor' and 'assistant' roles to use (by default) the
 * Authoring HTML input format for node editing and the Full HTML for block
 * editing.
 *
 * @param $roles
 *   An associative array of role name => rid for the roles 'administrator',
 *   'editor' and 'assistant' e.g.:
 *
 *   array(
 *     'administrator' => 3,
 *     'editor'        => 4,
 *     'assistant'     => 5,
 *   );
 *
 *   The entries for the authenticated and anonymous are added by default.
 */
function _drupen_better_formats_configure(array $roles) {
  // Anonymous and authenticated user.
  $roles['authenticated'] = DRUPAL_AUTHENTICATED_RID;
  $roles['anonymous'] = DRUPAL_ANONYMOUS_RID;

  // Input formats ids.
  // TODO: update authoring_html_filter_format_id to the new variable once Authoring HTML got published.
  $full_html_format = db_result(db_query("SELECT format FROM {filter_formats} WHERE name = 'Full HTML'"));
  $authoring_html_format = variable_get('authoring_html_format', 0);

  // Formats by type and roles.
  // Roles 'administrator', 'editor' and 'assistant' can use the Authoring HTML
  // for nodes and Full HTML for blocks.
  $formats_roles = array(
    'node' => array(
      'administrator' => $authoring_html_format,
      'editor'        => $authoring_html_format,
      'assistant'     => $authoring_html_format,
    ),
    'block' => array(
      'administrator' => $full_html_format,
      'editor'        => $full_html_format,
      'assistant'     => $full_html_format,
    )
  );

  // Better Formats.
  $better_formats_default = (Boolean) db_result(
    db_query('SELECT COUNT(format) FROM {better_formats_defaults} WHERE format <> 0')
  );

  // Only configures if the Better Formats table have the default configuration data.
  if (!$better_formats_default) {
    db_query('DELETE FROM {better_formats_defaults}');

    $weight = -25;
    foreach ($roles as $role => $rid) {
      $sql = "INSERT INTO {better_formats_defaults} (rid, type, format, type_weight, weight) VALUES (%d, '%s', %d, 1, %d)";

      $node_format = isset($formats_roles['node'][$role]) ? $formats_roles['node'][$role] : 0;
      $comment_format = isset($formats_roles['comment'][$role]) ? $formats_roles['comment'][$role] : 0;
      $block_format = isset($formats_roles['block'][$role]) ? $formats_roles['block'][$role] : 0;

      db_query($sql, $rid, 'node', $node_format, $weight);
      db_query($sql, $rid, 'comment', $comment_format, $weight);
      db_query($sql, $rid, 'block', $block_format, $weight);

      $weight++;
    }
  }
}
