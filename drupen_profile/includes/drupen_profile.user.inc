<?php

/**
 * @file
 * User (Drupal core) configuration tasks.
 */

/**
 * Configures the roles' permissions.
 */
function _drupen_profile_user_configure() {
  module_load_include('inc', 'drupen_profile', 'includes/drupen_profile.user_permission');

  // Set the roles permissions.
  drupen_user_save_permissions_roles(drupen_profile_user_permissions());
}
