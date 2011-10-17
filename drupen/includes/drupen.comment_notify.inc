<?php

/**
 * @file
 * Comment notify configuration tasks.
 */

/**
 * Configures the Comment notify module.
 */
function _drupen_comment_notify_configure() {
  drupal_load('module', 'comment_notify');

  $variables = array(
    'comment_notify_default_anon_mailalert'       => COMMENT_NOTIFY_COMMENT,
    'comment_notify_default_registered_mailalert' => COMMENT_NOTIFY_COMMENT,
    'node_notify_default_mailalert'               => TRUE,
    'comment_notify_available_alerts' => array(
      COMMENT_NOTIFY_NODE     => COMMENT_NOTIFY_DISABLED,
      COMMENT_NOTIFY_COMMENT  => COMMENT_NOTIFY_COMMENT,
    ),
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }

  // Set the comments notifications settings for each user.
  $result = db_query('SELECT uid FROM {users} WHERE uid NOT IN (SELECT uid FROM {comment_notify_user_settings}) AND uid > 0');
  while ($uid = db_result($result)) {
    db_query('INSERT INTO {comment_notify_user_settings} VALUES (%d, %d, %d)', $uid, $variables['node_notify_default_mailalert'], COMMENT_NOTIFY_COMMENT);
  }
}
