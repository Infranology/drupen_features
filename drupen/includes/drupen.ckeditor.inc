<?php

/**
 * @file
 * CKEditor configuration tasks.
 */

/**
 * Configures the CKEditor. It will create two CKEditor profiles:
 *
 * - CKEditor Global Profile: set the editor to show only in the node "Body"
 *   textareas and the role precedence.
 * - Default: set the roles that can use the profile and the overall settings
 *   for the editor (stylesheets, toolbar, plugins). Users can not customize
 *   the editor appearance.
 *
 * This function should be called only during installation since it deletes
 * anything in the ckeditor_role and ckeditor_settings tables.
 */
function _drupen_ckeditor_configure() {
  db_query("DELETE FROM {ckeditor_role}");
  db_query("DELETE FROM {ckeditor_settings}");

  $rids = _drupen_ckeditor_get_roles_rids();
  foreach ($rids as $rid) {
    db_query("INSERT INTO {ckeditor_role} (name, rid) VALUES ('%s', %d)", 'Default', $rid);
  }

  $settings_definitions = _drupen_ckeditor_settings_definitions();
  _drupen_ckeditor_settings_insert($settings_definitions);
}

/**
 * Returns an array of roles rid in order of importance (administrator > editor > assistant).
 *
 * @return
 *   An array of roles rid
 */
function _drupen_ckeditor_get_roles_rids() {
  // The roles created in drupen_install().
  // TODO: temporaly created by features in drupen.features.user_role.inc
  $result = db_query("SELECT rid, name FROM {role} WHERE name IN ('administrator', 'assistant', 'editor')");

  $roles = array();
  while ($role = db_fetch_object($result)) {
    $roles[$role->name] = $role->rid;
  }

  return array(
    $roles['administrator'],
    $roles['editor'],
    $roles['assistant'],
  );
}

/**
 * Persist an array with CKEditor settings in the ckeditor_settings tables with
 * SQL INSERT.
 *
 * @param $settings_definitions
 *   An associative array in the form 'profile_name' => 'settings'. See
 *   _drupen_ckeditor_settings_definitions() for an example of array.
 */
function _drupen_ckeditor_settings_insert($settings_definitions) {
  foreach ($settings_definitions as $name => $settings) {
    db_query("INSERT INTO {ckeditor_settings} (name, settings) VALUES ('%s', '%s')", $name, serialize($settings));
  }
}

/**
 * Updates a CKEditor profile with an array of settings with SQL UPDATE.
 *
 * @param $settings_definitions
 *   An associative array in the form 'profile_name' => 'settings'. See
 *   _drupen_ckeditor_settings_definitions() for an example of array.
 */
function _drupen_ckeditor_settings_update($settings_definitions) {
  foreach ($settings_definitions as $name => $settings) {
    db_query("UPDATE {ckeditor_settings} SET settings = '%s' WHERE name = '%s'", serialize($settings), $name);
  }
}

/**
 * Helper function, just update the CKEditor Global profile settings.
 *
 * @return
 *   An array with the format that hook_update_N() uses to show the results
 *   of an update task.
 */
function _drupen_ckeditor_global_settings_update() {
  $settings_definitions = _drupen_ckeditor_settings_definitions();

  unset($settings_definitions['Default']);
  _drupen_ckeditor_settings_update($settings_definitions);

  return array(
    array(
      'success' => TRUE,
      'query' => 'Updated the CKEditor Default profile.'
    )
  );
}

/**
 * Helper function, just update the CKEditor Default profile settings.
 *
 * @return
 *   An array with the format that hook_update_N() uses to show the results
 *   of an update task.
 */
function _drupen_ckeditor_default_settings_update() {
  $settings_definitions = _drupen_ckeditor_settings_definitions();

  unset($settings_definitions['CKEditor Global Profile']);
  _drupen_ckeditor_settings_update($settings_definitions);

  return array(
    array(
      'success' => TRUE,
      'query' => 'Updated the CKEditor Default profile.'
    )
  );
}

/**
 * Returns an associative array of 'profile_name' => 'settings' for the
 * CKEditor configuration.
 *
 * @return
 *   An associative array of 'profile_name' => 'settings'
 */
function _drupen_ckeditor_settings_definitions() {
  $rids = _drupen_ckeditor_get_roles_rids();

  $global = array(
    'rank' => $rids,
    'excl_mode' => '1',
    'excl' => 'node/*/*.edit-body',
    'simple_incl' => '',
    'ckeditor_path' => '%b/' . libraries_get_path('ckeditor', FALSE),
    'ckeditor_local_path' => '',
    'show_fieldnamehint' => 'f',
    'excl_regex' => '#(?:^.*@node/.*/.*\.edit-body$)#',
    'simple_incl_regex' => '',
  );

  $default = array(
    'allow_user_conf' => 'f',
    'filters' => array(
      'ckeditor_link/0' => 0,
      'ckeditor_swf/0' => 0,
      'filter/3' => 0,
      'filter/0' => 0,
      'htmlpurifier/0' => 0,
      'htmlpurifier/1' => 0,
    ),
    'ss' => '2',
    'min_rows' => '1',
    'excl_mode' => '0',
    'excl' => '',
    'simple_incl' => '',
    'default' => 't',
    'show_toggle' => 't',
    'popup' => 'f',
    'skin' => 'kama',
    'uicolor' => 'default',
    'uicolor_textarea' => '<p>Click on the <strong>UI Color Picker</strong> button to set your color preferences.</p>',
    'uicolor_user' => 'default',
    'toolbar' => "[
  ['Maximize', 'ShowBlocks'],
  ['Cut','Copy','Paste','PasteText','PasteFromWord','-'],
  ['Undo','Redo','Find','Replace','-','SelectAll','RemoveFormat'],
  '/',
  ['Format','Styles'],
  ['TextColor','BGColor'],
  ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
  ['NumberedList','BulletedList'],
  ['JustifyLeft','JustifyCenter','JustifyRight','JustifyBlock','-','BidiRtl','BidiLtr','-','Outdent','Indent','Blockquote'],
  '/',
  ['MediaEmbed','Image','IMCE','Flash'],
  ['Table','SpecialChar','HorizontalRule','Iframe'],
  ['Link','Unlink','Anchor'],
  ['DrupalBreak'],
  ['Source']
]",
    'expand' => 't',
    'width' => '100%',
    'lang' => 'en',
    'auto_lang' => 't',
    'language_direction' => 'default',
    'enter_mode' => 'p',
    'shift_enter_mode' => 'br',
    'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
    'custom_formatting' => 'f',
    'formatting' =>
    array(
      'custom_formatting_options' =>
      array(
        'indent' => 'indent',
        'breakBeforeOpen' => 'breakBeforeOpen',
        'breakAfterOpen' => 'breakAfterOpen',
        'breakAfterClose' => 'breakAfterClose',
        'breakBeforeClose' => 0,
        'pre_indent' => 0,
      ),
    ),
    'css_mode' => 'self',
    'css_path' => '%h' . drupal_get_path('module', 'drupen') . '/assets/css/drupen-ckeditor.css',
    'css_style' => 'self',
    'styles_path' => '%h' . drupal_get_path('module', 'drupen') . '/assets/js/ckeditor.styles.js',
    'filebrowser' => 'imce',
    'filebrowser_image' => '',
    'filebrowser_flash' => '',
    'UserFilesPath' => '%b%f/',
    'UserFilesAbsolutePath' => '%d%b%f/',
    'ckeditor_load_method' => 'ckeditor.js',
    'ckeditor_load_time_out' => '0',
    'forcePasteAsPlainText' => 'f',
    'html_entities' => 't',
    'scayt_autoStartup' => 'f',
    'config_js_mode' => 'self',
    'config_js_path' => '%h' . drupal_get_path('module', 'drupen') . '/assets/js/ckeditor.config.js',
    'js_conf' => '',
    'loadPlugins' => array(
      'ckeditor_link' => array(
        'name' => 'drupal_path',
        'desc' => 'Support for CKEditor Link module',
        'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_link') . '/plugins/link/',
        'default' => 't',
      ),
      'ckeditor_swf' => array(
        'name' => 'swf',
        'desc' => 'Support for CKEditor SWF module',
        'path' => '%base_path%' . drupal_get_path('module', 'ckeditor_swf') . '/plugins/swf/',
        'default' => 't',
      ),
      'drupalbreaks' => array(
        'name' => 'drupalbreaks',
        'desc' => 'Plugin for inserting Drupal teaser and page breaks. <i>(buttons: DrupalBreak, DrupalPageBreak)</i>',
        'path' => '%base_path%%plugin_dir%/drupalbreaks/',
        'default' => 'f'
      ),
      'imce' => array(
        'name' => 'imce',
        'desc' => 'Plugin for inserting files from imce without image dialog <i>(buttons: IMCE)</i>',
        'path' => '%base_path%%plugin_dir%/imce/',
        'default' => 'f',
      ),
      'mediaembed' => array(
        'name' => 'mediaembed',
        'desc' => 'Plugin for inserting Drupal embeded media <i>(buttons: MediaEmbed)</i>',
        'path' => '%base_path%%plugin_dir%/mediaembed/',
        'default' => 'f',
      ),
      'tableresize' => array(
        'name' => 'tableresize',
        'desc' => 'Tableresize plugin',
        'path' => '%base_path%%editor_path%plugins/tableresize/',
        'default' => 't'
      ),
    ),
    'excl_regex' => '',
    'simple_incl_regex' => '',
  );

  return array(
    'CKEditor Global Profile' => $global,
    'Default' => $default
  );
}
