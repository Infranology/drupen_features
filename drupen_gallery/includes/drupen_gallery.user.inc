<?php

/**
 * @file
 * User (Drupal core) configuration tasks.
 */

/**
 * Configures the roles' permissions.
 */
function _drupen_gallery_user_configure() {
  module_load_include('inc', 'drupen_gallery', 'includes/drupen_gallery.user_permission');

  // Set the roles permissions.
  drupen_user_save_permissions_roles(drupen_gallery_user_permissions());
}
