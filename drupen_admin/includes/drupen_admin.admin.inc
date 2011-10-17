<?php

/**
 * @file
 * Admin configuration tasks.
 */

/**
 * Configures the Admin module.
 */
function _drupen_admin_admin_configure() {
  $admin_variable = array(
    'layout'   => 'vertical',
    'position' => 'nw',
    'behavior' => 'df',
    'blocks' => array(
      'locale-0'          => -10,
      'admin-create'      => -9,
      'admin-menu'        => -8,
      'admin-account'     => -7,
      'search-0'          => -6,
      'user-3'            => -5, // User who's online
      'admin-devel'       => -4,
      'context_ui-devel'  => -3,
      'context_ui-editor' => -2,
    )
  );

  variable_set('admin_toolbar', $admin_variable);
}
