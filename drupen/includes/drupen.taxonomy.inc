<?php

/**
 * @file
 * Taxonomy (Drupal core) configuration tasks.
 */

/**
 * Configures the default vocabularies. Creates a free tagging vocabulary.
 */
function _drupen_taxonomy_configure() {
  $vocabularies = array(
    'drupen_tag' => array(
      'name' => t('Tags'),
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_drupen_tag',
      'weight' => '-9',
      'nodes' => array(
        'page' => 'page',
      ),
    ),
  );

  $xmlsitemaps = array(
    'drupen_tag' => array(
      'status' => '1',
      'priority' => '0.2',
    )
  );

  drupen_taxonomy_save_vocabulary($vocabularies, $xmlsitemaps);
}
