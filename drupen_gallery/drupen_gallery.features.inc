<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function drupen_gallery_imagecache_default_presets() {
  $items = array(
    'drupen_gallery_photo' => array(
      'presetname' => 'drupen_gallery_photo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '640',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'drupen_gallery_photo_vertical' => array(
      'presetname' => 'drupen_gallery_photo_vertical',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '480',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'drupen_gallery_square' => array(
      'presetname' => 'drupen_gallery_square',
      'actions' => array(
        '0' => array(
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
    'drupen_gallery_thumb' => array(
      'presetname' => 'drupen_gallery_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '140',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'drupen_gallery_thumb_vertical' => array(
      'presetname' => 'drupen_gallery_thumb_vertical',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '105',
            'height' => '',
            'upscale' => 0,
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
function drupen_gallery_node_info() {
  $items = array(
    'drupen_gallery' => array(
      'name' => t('Photo gallery'),
      'module' => 'features',
      'description' => t('A <em>photo gallery</em> allows the grouping of photos. Photos are displayed as thumbnails and when clicked, a larger version is shown.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'drupen_photo' => array(
      'name' => t('Photo'),
      'module' => 'features',
      'description' => t('A individual <em>photo</em> in a <em>photo gallery</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function drupen_gallery_views_api() {
  return array(
    'api' => '2',
  );
}
