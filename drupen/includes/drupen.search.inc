<?php

/**
 * @file
 * Search (Drupal core) configuration tasks.
 */

/**
 * Configures the Search (Drupal core) module.
 */
function _drupen_search_configure() {
  $variables = array(
    'node_rank_comments' => 8,
    'node_rank_recent' => 7,
    'node_rank_relevance' => 9
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}
