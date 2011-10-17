<?php

/**
 * @file
 * Date API configuration tasks.
 */

/**
 * Configures the Date API module, importing date formats from the ICU data.
 */
function _drupen_date_api_configure() {
  $data = include_once './' . drupal_get_path('module', 'drupen') . '/resources/data/php_datetime_patterns.php';

  $sql = "INSERT INTO {date_format_locale} (format, type, language) VALUES ('%s', '%s', '%s')";
  foreach ($data as $language => $formats) {
    $has_language = db_result(
      db_query("SELECT COUNT(language) FROM {date_format_locale} WHERE language = '%s'", $language)
    );

    if ($has_language) {
      continue;
    }

    foreach ($formats as $type => $format) {
      db_query($sql, $format, $type, $language);
    }
  }
}
