<?php

/**
 * @file
 * Date Popup configuration tasks.
 */

/**
 * Configures the Date Popup module.
 */
function _drupen_admin_date_popup_configure() {
  $variables = array(
    'date_popup_css_file' => drupen_base_path() . drupal_get_path('module', 'date_popup') . '/themes/datepicker.css',
    'date_popup_timepicker' => 'default',
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}
