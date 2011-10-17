<?php

/**
 * @file
 * User (Drupal core) configuration tasks.
 */

/**
 * Configures the roles' permissions.
 */
function _drupen_blog_user_configure() {
  module_load_include('inc', 'drupen_blog', 'includes/drupen_blog.user_permission');

  // Set the roles permissions.
  drupen_user_save_permissions_roles(drupen_blog_user_permissions());
}
