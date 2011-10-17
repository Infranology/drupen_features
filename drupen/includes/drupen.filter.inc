<?php

/**
 * @file
 * Filter and input formats configuration tasks.
 */

/**
 * Configures the input formats:
 *
 * - Give usage the roles 'administrator', 'editor' and 'assistant' to the
 *   Authoring HTML and Full HTML input formats
 * - Removes the auto paragraph and breaks converter filter from the Full HTML
 *   input format
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
function _drupen_filter_configure(array $roles) {
  $full_html_format = db_result(db_query("SELECT format FROM {filter_formats} WHERE name = 'Full HTML'"));
  $authoring_html_format = variable_get('authoring_html_format', 0);

  // Input formats. Allows the roles to use the Full HTML and Authoring HTML.
  $filter_format_roles = implode(',', array_values($roles));
  db_query("UPDATE {filter_formats} SET roles = ',%s,' WHERE format = %d AND roles = ''", $filter_format_roles, $full_html_format);
  db_query("UPDATE {filter_formats} SET roles = ',%s,' WHERE format = %d", $filter_format_roles, $authoring_html_format);

  // Removes the auto paragraph and breaks converter from Full HTML.
  db_query('DELETE FROM {filters} WHERE format = %d AND delta = 1', $full_html_format);
}
