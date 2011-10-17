<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function drupen_profile_imagecache_default_presets() {
  $items = array(
    'drupen_profile_photo' => array(
      'presetname' => 'drupen_profile_photo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '240',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
    'drupen_profile_photo_vertical' => array(
      'presetname' => 'drupen_profile_photo_vertical',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '180',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
    'drupen_profile_square' => array(
      'presetname' => 'drupen_profile_square',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100',
            'height' => '',
            'upscale' => 1,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '80',
            'height' => '80',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function drupen_profile_node_info() {
  $items = array(
    'drupen_profile' => array(
      'name' => t('Profile'),
      'module' => 'features',
      'description' => t('The profile lets users describe themselves. Authorship\'s information is displayed using data available in the user profile.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('About'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function drupen_profile_views_api() {
  return array(
    'api' => '2',
  );
}
