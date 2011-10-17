<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function drupen_profile_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_drupen_profile_fields
  $groups['drupen_profile-group_drupen_profile_fields'] = array(
    'group_type' => 'standard',
    'type_name' => 'drupen_profile',
    'group_name' => 'group_drupen_profile_fields',
    'label' => 'Picture and links',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-3',
        '2' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'description' => '',
      ),
    ),
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_drupen_profile_picture',
      '1' => 'field_drupen_profile_twitter',
      '2' => 'field_drupen_profile_facebook',
      '3' => 'field_drupen_profile_linkedin',
      '4' => 'field_drupen_profile_website',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Picture and links');

  return $groups;
}
