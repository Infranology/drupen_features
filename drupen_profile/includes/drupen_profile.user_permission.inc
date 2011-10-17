<?php

/**
 * @file
 * Default user permissions for the module.
 */

/**
 * Returns an array of default permissions and roles.
 */
function drupen_profile_user_permissions() {
  return array(
    'execute Change the author of a post (node_assign_owner_action)' => array(
      'editor',
    ),
    'execute Delete node (views_bulk_operations_delete_node_action)' => array(
      'assistant',
      'editor',
    ),
    'execute Make post sticky (node_make_sticky_action)' => array(
      'editor',
    ),
    'execute Make post unsticky (node_make_unsticky_action)' => array(
      'editor',
    ),
    'execute Mark as private (private_node_mark_private)' => array(
      'assistant',
      'editor',
    ),
    'execute Mark as public (private_node_mark_public)' => array(
      'assistant',
      'editor',
    ),
    'execute Promote post to front page (node_promote_action)' => array(
      'editor',
    ),
    'execute Publish post (node_publish_action)' => array(
      'assistant',
      'editor',
    ),
    'execute Remove post from front page (node_unpromote_action)' => array(
      'editor',
    ),
    'execute Unpublish post (node_unpublish_action)' => array(
      'assistant',
      'editor',
    ),
    'create drupen_profile content' => array(
      'assistant',
    ),
    'delete own drupen_profile content' => array(
      'assistant',
    ),
    'edit own drupen_profile content' => array(
      'assistant',
    ),
  );
}
