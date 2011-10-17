<?php

/**
 * @file
 * Node and Content (CCK) configuration tasks.
 */

/**
 * Configures the variables for the core page and story content types.
 */
function _drupen_admin_content_configure() {
  $variables = drupen_admin_content_get_default_variables('page');

  // Remove the node's form from Vertical Tabs processing.
  drupen_admin_content_vertical_tabs('page', FALSE);

  // Post info.
  drupen_admin_content_post_info('page', FALSE);

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}

/**
 * Updates the theme_settings variable to show or not the post information on
 * a node type.
 *
 * @param $node_types
 *   A node type name or an array of node types names.
 *
 * @param $toogle
 *   The Boolean value to use. Defaults to TRUE.
 *
 * @param $override
 *   Override the value if node type is already set. Optional, defaults to TRUE.
 *
 * @see drupen_variable_node_types_set
 */
function drupen_admin_content_post_info($node_types, $toogle = TRUE, $override = TRUE) {
  $options = array(
    'toogle'        => $toogle,
    'key_value'     => 'toogle_node_info_',
    'override'      => $override,
  );

  drupen_variable_node_types_set($node_types, 'theme_settings', $options);
}

/**
 * Set the Service Links widget to show or not in a node type.
 *
 * @param $node_types
 *   A node type name or an array of node types names.
 *
 * @param $toogle
 *   The Boolean value to use. Defaults to TRUE.
 *
 * @param $override
 *   Override the value if node type is already set. Optional, defaults to TRUE.
 *
 * @see drupen_variable_node_types_set
 */
function drupen_admin_content_service_links($node_types, $toogle = TRUE, $override = TRUE) {
  $options = array(
    'toogle'        => $toogle,
    'use_node_type' => TRUE,
    'override'      => $override
  );

  drupen_variable_node_types_set($node_types, 'service_links_node_types', $options);
}

/**
 * Set if node type will be Vertical Tabs processed.
 *
 * @param $node_types
 *   A node type name or an array of node types names.
 *
 * @param $toogle
 *   The Boolean value to use. Defaults to TRUE.
 *
 * @param $override
 *   Override the value if node type is already set. Optional, defaults to TRUE.
 *
 * @see drupen_variable_node_types_set
 */
function drupen_admin_content_vertical_tabs($node_types, $toogle = TRUE, $override = TRUE) {
  $options = array(
    'toogle'    => $toogle,
    'key_value' => '_node_form',
    'override'  => $override
  );

  drupen_variable_node_types_set($node_types, 'vertical_tabs_forms', $options);
}

/**
 * Returns the Drüpen suggested variables for a content type:
 *
 * - Workflow: published by default, create new revision
 * - Content form: weights values for the CCK and Node Form Columns modules
 * - Comments: disabled by default, 50 per page, descending order by datetime,
 *   optional preview, anonymous must send contact details, comment form after
 *   the comments and subject field enabled
 * - Diff: show diffs inline, show changes button and revisions page enabled
 * - Private: enabled, public by default
 * - Scheduler: enabled (un)scheduled publishing. Changes published timestamp
 * - XMLSitemap: enabled, priority 0.4
 *
 * @return
 *   Array.
 */
function drupen_admin_content_get_default_variables($content_type) {
  $variables_template = array(
    'comment_anonymous_%s'        => 2,
    'comment_controls_%s'         => 3,
    'comment_default_mode_%s'     => 4,
    'comment_default_order_%s'    => 1,
    'comment_default_per_page_%s' => 50,
    'comment_form_location_%s'    => 1,
    'comment_%s'                  => 0,
    'comment_preview_%s'          => 0,
    'comment_subject_field_%s'    => 1,
    'node_options_%s'             => array(
      '0' => 'status',
      '1' => 'revision',
    ),
  );

  // Content (CCK)
  $variables_template['content_extra_weights_%s'] = drupen_admin_content_get_default_weights();

  // Date Popup Authored
  $variables_template += drupen_admin_content_date_popup_authored_variables();

  // Diff
  $variables_template['enable_revisions_page_%s'] = 1;
  $variables_template['show_diff_inline_%s']      = 1;
  $variables_template['show_preview_changes_%s']  = 1;

  // Node Form Columns
  $variables_template['nodeformscols_field_placements_%s_default'] = drupen_admin_content_get_default_nodeformcols();

  // Private
  $variables_template['private_%s'] = 1;

  // Scheduler
  $variables_template['scheduler_publish_enable_%s']   = 1;
  $variables_template['scheduler_publish_touch_%s']    = 1;
  $variables_template['scheduler_unpublish_enable_%s'] = 1;

  // XMLSitemap
  $variables_template['xmlsitemap_settings_node_%s'] = array(
    'status' => 1,
    'priority' => 0.5,
  );

  $variables = array();

  foreach ($variables_template as $name => $value) {
    $variables[sprintf($name, $content_type)] = $value;
  }

  return $variables;
}

/**
 * Returns an array of variables for the Date Popup Authored module. The
 * variable 'date_popup_authored_format_%s' will use the short date format
 * for the site default language.
 *
 * @return
 *   Returns an array of variables for the Date Popup Authored module.
 */
function drupen_admin_content_date_popup_authored_variables() {
  return array(
    'date_popup_authored_enabled_%s' => TRUE,
    'date_popup_authored_format_%s'  => drupen_language_date_format(),
  );
}

/**
 * Returns an array of suggested fieldsets and weights for the node's form
 * configuration.
 *
 * @return
 *   The configuration array for the node's form.
 */
function drupen_admin_content_get_default_weights() {
  return array(
    'title'                => -10,
    'body_field'           => -9,
    'attachments'          => -8,
    'language'             => -7,
    'translation'          => -6,
    'taxonomy'             => -5,
    'options'              => -4,
    'revision_information' => -3,
    'privacy_settings'     => -2,
    'scheduler_settings'   => -1,
    'author'               => 0,
    'book'                 => 1,
    'menu'                 => 2,
    'comment_settings'     => 3,
    'path'                 => 4,
    'path_redirect'        => 5,
    'og_nodeapi'           => 6,
    'nodewords'            => 7,
    'xmlsitemap'           => 8,
  );
}

/**
 * Returns an array of suggested regions and weights for the node nodeformcols
 * configuration.
 *
 * Note: We just ommit the has_required and the title attributes. Their
 * absence does not affects anything in the form displaying.
 *
 * @return
 *   The configuration array for the node nodeformcols.
 */
function drupen_admin_content_get_default_nodeformcols() {
  $main = array(
    'title' => array(
      'region' => 'main',
      'weight' => -10,
    ),

    'body_field' => array(
      'region' => 'main',
      'weight' => -9,
    ),

    'attachments' => array(
      'region'    => 'main',
      'weight'    => -8,
      'collapsed' => 0,
    ),

    'buttons' => array(
      'region'       => 'main',
      'weight'       => 100,
    ),
  );

  $right = array(
    'language' => array(
      'region'    => 'right',
      'weight'    => -8,
      'collapsed' => 0,
    ),

    'translation' => array(
      'region'    => 'right',
      'weight'    => -7,
      'collapsed' => 1,
    ),

    'taxonomy' => array(
      'region'    => 'right',
      'weight'    => -6,
      'collapsed' => 0,
    ),

    'options' => array(
      'region'    => 'right',
      'weight'    => -5,
      'collapsed' => 0,
    ),

    'revision_information' => array(
      'region'    => 'right',
      'weight'    => -4,
      'collapsed' => 0,
    ),

    'privacy_settings' => array(
      'region'    => 'right',
      'weight'    => -3,
      'collapsed' => 1,
    ),

    'scheduler_settings' => array(
      'region'    => 'right',
      'weight'    => -2,
      'collapsed' => 1,
    ),

    'author' => array(
      'region'    => 'right',
      'weight'    => -1,
      'collapsed' => 1,
    ),

    'book' => array(
      'region'    => 'right',
      'weight'    => 0,
      'collapsed' => 1,
    ),

    'menu' => array(
      'region'    => 'right',
      'weight'    => 1,
      'collapsed' => 1,
    ),

    'comment_settings' => array(
      'region'    => 'right',
      'weight'    => 2,
      'collapsed' => 1,
    ),

    'path' => array(
      'region'    => 'right',
      'weight'    => 3,
      'collapsed' => 1,
    ),

    'path_redirect' => array(
      'region'    => 'right',
      'weight'    => 4,
      'collapsed' => 1,
    ),

    'og_nodeapi' => array(
      'region'    => 'right',
      'weight'    => 5,
      'collapsed' => 1,
    ),

    'nodewords' => array(
      'region'    => 'right',
      'weight'    => 7,
      'collapsed' => 1,
    ),

    'xmlsitemap' => array(
      'region'    => 'right',
      'weight'    => 8,
      'collapsed' => 1,
    ),
  );

  return array_merge($main, $right);
}
