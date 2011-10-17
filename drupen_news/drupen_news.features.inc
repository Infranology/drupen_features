<?php

/**
 * Implementation of hook_node_info().
 */
function drupen_news_node_info() {
  $items = array(
    'drupen_news' => array(
      'name' => t('News'),
      'module' => 'features',
      'description' => t('<em>News</em> is the communication of selected information on current events which is presented to the site audience.'),
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
function drupen_news_views_api() {
  return array(
    'api' => '2',
  );
}
