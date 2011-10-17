<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function drupen_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_node_info().
 */
function drupen_blog_node_info() {
  $items = array(
    'drupen_blog' => array(
      'name' => t('Blog entry'),
      'module' => 'features',
      'description' => t('A <em>blog entry</em> is a single post to an online journal, or <em>blog</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function drupen_blog_views_api() {
  return array(
    'api' => '2',
  );
}
