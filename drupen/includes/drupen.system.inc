<?php

/**
 * @file
 * System (Drupal core) configuration tasks.
 */

/**
 * Configures the System (Drupal core) module.
 */
function _drupen_system_configure() {
  $variables = array(
    'file_directory_path' => 'sites/default/files',
    'transliteration_file_lowercase' => 1,
    'transliteration_file_uploads' => 1,
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}
