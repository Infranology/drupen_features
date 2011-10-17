<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function drupen_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drupen_blog_author';
  $context->description = t('Drüpen Blog > Author blog entries');
  $context->tag = 'Drüpen Blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'drupen_profile' => 'drupen_profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-drupen_blog_listing-block_2' => array(
          'module' => 'views',
          'delta' => 'drupen_blog_listing-block_2',
          'region' => 'content_bottom',
          'weight' => -20,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Drüpen Blog');
  t('Drüpen Blog > Author blog entries');
  $export['drupen_blog_author'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'drupen_blog_entry';
  $context->description = t('Drüpen Blog > Entry blocks');
  $context->tag = 'Drüpen Blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'drupen_blog' => 'drupen_blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-drupen_profile_author-block_1' => array(
          'module' => 'views',
          'delta' => 'drupen_profile_author-block_1',
          'region' => 'right',
          'weight' => -20,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Drüpen Blog');
  t('Drüpen Blog > Entry blocks');
  $export['drupen_blog_entry'] = $context;

  return $export;
}
