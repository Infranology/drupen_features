<?php

/**
 * @file
 * Private Download configuration tasks.
 */

/**
 * Configures the Private Download module only if enabled. This module is not
 * enabled when the server software is not Apache, since it relies on
 * .htaccess URL rewriting.
 */
function _drupen_private_download_configure() {
  if (!module_exists('private_download')) {
    return;
  }

  $directory = file_directory_path() . '/private';
  file_check_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

  // Grab the system settings form for the private download module and use the
  // default .htaccess file contents from there.
  $filename = $directory . '/.htaccess';
  $form = private_download_admin_form();
  $htaccess = $form['private_download_htaccess']['#default_value'];

  if (!private_download_write($filename, $htaccess)) {
    drupal_set_message(t('Unable to write data to file: !filename', array('!filename' => $filename)), 'error', FALSE);
  }
}
