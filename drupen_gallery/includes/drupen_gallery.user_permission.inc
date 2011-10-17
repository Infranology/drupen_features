<?php

/**
 * @file
 * Default user permissions for the module.
 */

/**
 * Returns an array of default permissions and roles.
 */
function drupen_gallery_user_permissions() {
  return array(
    'create drupen_gallery content' => array(
      'assistant',
    ),
    'create drupen_photo content' => array(
      'assistant',
    ),
    'delete own drupen_gallery content' => array(
      'assistant',
    ),
    'delete own drupen_photo content' => array(
      'assistant',
    ),
    'edit own drupen_gallery content' => array(
      'assistant',
    ),
    'edit own drupen_photo content' => array(
      'assistant',
    ),
  );
}
