<?php

/**
 * Implementation of hook_content_default_fields().
 */
function drupen_gallery_content_default_fields() {
  $fields = array();

  // Exported field: field_drupen_photo_description
  $fields['drupen_photo-field_drupen_photo_description'] = array(
    'field_name' => 'field_drupen_photo_description',
    'type_name' => 'drupen_photo',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_drupen_photo_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Description',
      'weight' => '-7',
      'description' => t('A description of the photo. It will be show right after the photo in the gallery and in the photo page.'),
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_drupen_photo_file
  $fields['drupen_photo-field_drupen_photo_file'] = array(
    'field_name' => 'field_drupen_photo_file',
    'type_name' => 'drupen_photo',
    'display_settings' => array(
      'weight' => '-5',
      'parent' => '',
      '2' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'drupen_gallery_photo__linked_vertical',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'drupen_gallery_photo__linked_vertical',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'drupen_gallery_photo__vertical',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'resolution' => '0',
      'enforce_ratio' => 0,
      'croparea' => '560x0',
      'enforce_minimum' => 0,
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'drupen_photo/[site-date-yyyy]/[site-date-mm]',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 1,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Photo',
      'weight' => '-8',
      'description' => t('Upload the desired photo. You can futher crop the desired area of the photo to use. The photo will be scaled in the photo page to the resolution of 640 pixels of width (if the photo is in an horizontal orientation) or 480 pixels of width (if photo is in a vertical orientation).'),
      'type' => 'imagefield_crop_widget',
      'module' => 'imagefield_crop',
    ),
  );

  // Exported field: field_drupen_photo_gallery
  $fields['drupen_photo-field_drupen_photo_gallery'] = array(
    'field_name' => 'field_drupen_photo_gallery',
    'type_name' => 'drupen_photo',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_plain' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email_html' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'drupen_gallery' => 'drupen_gallery',
      'drupen_blog' => 0,
      'drupen_news' => 0,
      'drupen_photo' => 0,
      'drupen_profile' => 0,
      'page' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => t('Add photo'),
        'hover_title' => t('Add a new photo to this gallery'),
        'destination' => 'node',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 0,
      'label' => 'Photo gallery',
      'weight' => '-5',
      'description' => t('The desired gallery to put this photo. Start typing the gallery name, a list of suggestions will be shown to you.'),
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Photo');
  t('Photo gallery');

  return $fields;
}
