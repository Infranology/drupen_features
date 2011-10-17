<?php

/**
 * @file
 * Service Links configuration tasks.
 */

/**
 * Configures the Service Links module.
 */
function _drupen_service_links_configure() {
  $variables = array(
    'service_links_in_links'   => SERVICE_LINKS_IN_BOTH,
    'service_links_style'      => SERVICE_LINKS_STYLE_IMAGE,
    'service_links_path_icons' => drupal_get_path('module', 'service_links') . '/images',
    'service_links_hide_if_unpublished' => TRUE,
    'service_links_show' => array(
      'facebook_like'         => 1,
      'facebook_widget'       => 1,
      'google_plus_one'       => 1,
      'twitter_widget'        => 1,
    ),
    'service_links_weight' => array(
      'facebook_widget'       => -10,
      'facebook_like'         => -9,
      'twitter_widget'        => -8,
      'google_plus_one'       => -7,
    ),
    'service_links_fl_width'  => 80,  // Facebook Like width.
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}
