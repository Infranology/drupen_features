<?php

/**
 * @file
 * Default user permissions for the module.
 */

/**
 * Returns an array of default permissions and roles.
 */
function drupen_user_permissions() {
  return array(
    'access administration pages' => array(
      'assistant',
      'editor',
    ),
    'access ckeditor' => array(
      'assistant',
      'editor',
    ),
    'access ckeditor link' => array(
      'assistant',
      'editor',
    ),
    'access comments' => array(
      'anonymous user',
      'authenticated user',
    ),
    'access content' => array(
      'anonymous user',
      'authenticated user',
    ),
    'access private content' => array(
      'assistant',
      'editor',
    ),
    'access private download directory' => array(
      'assistant',
      'editor',
    ),
    'access service links' => array(
      'anonymous user',
      'authenticated user',
    ),
    'access user profiles' => array(
      'assistant',
      'editor',
    ),
    'administer blocks' => array(
      'editor',
    ),
    'administer comments' => array(
      'editor',
    ),
    'administer files' => array(
      'editor',
    ),
    'administer menu' => array(
      'editor',
    ),
    'administer nodes' => array(
      'editor',
    ),
    'administer taxonomy' => array(
      'editor',
    ),
    'administer url aliases' => array(
      'editor',
    ),
    'collapse format fieldset by default' => array(
      'assistant',
      'editor',
    ),
    'collapsible format selection' => array(
      'assistant',
      'editor',
    ),
    'create page content' => array(
      'assistant',
    ),
    'create story content' => array(
      'assistant',
    ),
    'create url aliases' => array(
      'assistant',
      'editor',
    ),
    'delete own page content' => array(
      'assistant',
    ),
    'delete own story content' => array(
      'assistant',
    ),
    'edit meta tags' => array(
      'assistant',
      'editor',
    ),
    'edit own page content' => array(
      'assistant',
    ),
    'edit own story content' => array(
      'assistant',
    ),
    'edit private content' => array(
      'assistant',
      'editor',
    ),
    'mark content as private' => array(
      'assistant',
      'editor',
    ),
    'post comments' => array(
      'anonymous user',
      'authenticated user',
    ),
    'post comments without approval' => array(
      'authenticated user',
    ),
    'revert revisions' => array(
      'assistant',
    ),
    'schedule (un),publishing of nodes' => array(
      'assistant',
      'editor',
    ),
    'search by category' => array(
      'anonymous user',
      'authenticated user',
    ),
    'search by node type' => array(
      'assistant',
      'editor',
    ),
    'search content' => array(
      'anonymous user',
      'authenticated user',
    ),
    'show format selection for blocks' => array(
      'assistant',
      'editor',
    ),
    'show format selection for comments' => array(
      'assistant',
      'editor',
    ),
    'show format selection for nodes' => array(
      'assistant',
      'editor',
    ),
    'show format tips' => array(
      'assistant',
      'editor',
    ),
    'show more format tips link' => array(
      'assistant',
      'editor',
    ),
    'subscribe to comments' => array(
      'anonymous user',
      'authenticated user',
    ),
    'use admin toolbar' => array(
      'assistant',
      'editor',
    ),
    'use advanced search' => array(
      'anonymous user',
      'authenticated user',
    ),
    'use gravatar' => array(
      'anonymous user',
      'authenticated user',
    ),
    'use keyword search' => array(
      'anonymous user',
      'authenticated user',
    ),
    'view revisions' => array(
      'assistant',
    ),
  );
}
