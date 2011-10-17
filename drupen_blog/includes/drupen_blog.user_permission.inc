<?php

/**
 * @file
 * Default user permissions for the module.
 */

/**
 * Returns an array of default permissions and roles.
 */
function drupen_blog_user_permissions() {
  return array(
    'create drupen_blog content' => array(
      'assistant',
    ),
    'delete own drupen_blog content' => array(
      'assistant',
    ),
    'edit own drupen_blog content' => array(
      'assistant',
    ),
  );
}
