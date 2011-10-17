<?php

/**
 * Implementation of hook_content_default_fields().
 */
function drupen_profile_content_default_fields() {
  $fields = array();

  // Exported field: field_drupen_profile_facebook
  $fields['drupen_profile-field_drupen_profile_facebook'] = array(
    'field_name' => 'field_drupen_profile_facebook',
    'type_name' => 'drupen_profile',
    'display_settings' => array(
      'weight' => '13',
      'parent' => 'group_drupen_profile_fields',
      '2' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Facebook',
      'weight' => '13',
      'description' => t('An URL address for your Facebook page. Example: <a href="http://facebook.com/drupencms" target="_blank">http://facebook.com/drupencms</a>.'),
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_drupen_profile_linkedin
  $fields['drupen_profile-field_drupen_profile_linkedin'] = array(
    'field_name' => 'field_drupen_profile_linkedin',
    'type_name' => 'drupen_profile',
    'display_settings' => array(
      'weight' => '14',
      'parent' => 'group_drupen_profile_fields',
      '2' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'LinkedIn',
      'weight' => '14',
      'description' => t('An URL address for your LinkedIn page. Example: <a href="http://www.linkedin.com/company/infranology" target="_blank">http://www.linkedin.com/company/infranology</a>.'),
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_drupen_profile_picture
  $fields['drupen_profile-field_drupen_profile_picture'] = array(
    'field_name' => 'field_drupen_profile_picture',
    'type_name' => 'drupen_profile',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_drupen_profile_fields',
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 1,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'drupen_profile_photo__linked_vertical',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'drupen_profile_photo__linked_vertical',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'drupen_profile_photo__linked_vertical',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
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
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'drupen_profile',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Picture',
      'weight' => '11',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_drupen_profile_twitter
  $fields['drupen_profile-field_drupen_profile_twitter'] = array(
    'field_name' => 'field_drupen_profile_twitter',
    'type_name' => 'drupen_profile',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_drupen_profile_fields',
      '2' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Twitter',
      'weight' => '12',
      'description' => t('An URL address for your Twitter profile. Example: <a href="http://twitter.com/drupen" target="_blank">http://twitter.com/drupen</a>.'),
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_drupen_profile_website
  $fields['drupen_profile-field_drupen_profile_website'] = array(
    'field_name' => 'field_drupen_profile_website',
    'type_name' => 'drupen_profile',
    'display_settings' => array(
      'weight' => '15',
      'parent' => 'group_drupen_profile_fields',
      '2' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'label',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Website',
      'weight' => '15',
      'description' => t('An URL address for your website. Example: <a href="http://drupen.org" target="_blank">http://drupen.org</a>.'),
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Facebook');
  t('LinkedIn');
  t('Picture');
  t('Twitter');
  t('Website');

  return $fields;
}
