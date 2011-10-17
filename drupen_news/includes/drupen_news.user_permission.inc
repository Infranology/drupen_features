<?php

/**
 * @file
 * Default user permissions for the module.
 */

/**
 * Returns an array of default permissions and roles.
 */
function drupen_news_user_permissions() {
  return array(
    'create drupen_news content' => array(
      'assistant',
    ),
    'delete own drupen_news content' => array(
      'assistant',
    ),
    'edit own drupen_news content' => array(
      'assistant',
    ),
  );
}
