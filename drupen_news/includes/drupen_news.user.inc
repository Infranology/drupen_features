<?php

/**
 * @file
 * User (Drupal core) configuration tasks.
 */

/**
 * Configures the roles' permissions.
 */
function _drupen_news_user_configure() {
  module_load_include('inc', 'drupen_news', 'includes/drupen_news.user_permission');

  // Set the roles permissions.
  drupen_user_save_permissions_roles(drupen_news_user_permissions());
}
