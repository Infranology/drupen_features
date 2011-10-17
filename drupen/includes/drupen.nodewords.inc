<?php

/**
 * @file
 * Nodewords configuration tasks.
 */

/**
 * Configures the Nodewords module.
 */
function _drupen_nodewords_configure() {
  // Sets the default values for the meta tags.
  db_query('DELETE FROM {nodewords} WHERE id = 0');

  $default = array('value' => '');

  $copyright = array('value' => '[site-date-yyyy], [site-name]');

  $robots = array(
    'index_follow' => 'index,follow',
    'value' => array(
      'noarchive' => 0,
      'noodp'     => 0,
      'nosnippet' => 0,
      'noydir'    => 0
    )
  );

  $location = array(
    'latitude'  => '',
    'longitude' => ''
  );

  $nodewords_settings = array(
    array(1, 0, 'abstract', $default),
    array(1, 0, 'canonical', $default),
    array(1, 0, 'copyright', $copyright),
    array(1, 0, 'description', $default),
    array(1, 0, 'keywords', $default),
    array(1, 0, 'revisit-after', $default),
    array(1, 0, 'robots', $robots),
    array(1, 0, 'dc.contributor', $default),
    array(1, 0, 'dc.creator', $default),
    array(1, 0, 'dc.date', $default),
    array(1, 0, 'dc.publisher', $default),
    array(1, 0, 'dc.title', $default),
    array(1, 0, 'location', $location),
    array(1, 0, 'shorturl', $default)
  );

  // Inserts the default values for the above meta tags.
  $sql = "INSERT INTO {nodewords} (type, id, name, content) VALUES ('%d', '%d', '%s', '%s')";
  foreach ($nodewords_settings as $settings) {
    db_query($sql, $settings[0], $settings[1], $settings[2], serialize($settings[3]));
  }

  // Creates the default custom pages meta tags.
  $custom_pages = array(
    'drupen_nodewords_custom_page_verification_meta_tags' => array(
      'name'    => t('Verification meta tags'),
      'path'    => '<front>',
      'weight'  => -10,
      'enabled' => TRUE,
    ),
  );

  foreach ($custom_pages as $name => $data) {
    if (!variable_get($name, FALSE)) {
      db_query(
        "INSERT INTO {nodewords_custom} (name, path, weight, enabled) VALUES ('%s', '%s', %d, %d)",
        $data['name'], $data['path'], $data['weight'], $data['enabled']
      );

      variable_set($name, db_last_insert_id('nodewords_custom', 'pid'));
    }
  }

  // Nodewords UI configuration.
  $variables = array(
    // Enabled meta tags.
    'nodewords_head' => array(
      'abstract'                => 'abstract',
      'copyright'               => 'copyright',
      'description'             => 'description',
      'keywords'                => 'keywords',
      'location'                => 'location',
      'robots'                  => 'robots',
      'shorturl'                => 'shorturl',
      'alexa_verification_code' => 'alexa_verification_code',
      'bing_webmaster_center'   => 'bing_webmaster_center',
      'google_webmaster_tools'  => 'google_webmaster_tools',
      'yahoo_site_explorer'     => 'yahoo_site_explorer',
      'yandex_webmaster_tools'  => 'yandex_webmaster_tools',
      'canonical'               => 0,
      'revisit-after'           => 0,
      'dc.contributor'          => 0,
      'dc.creator'              => 0,
      'dc.date'                 => 0,
      'dc.description'          => 0,
      'dc.publisher'            => 0,
      'dc.title'                => 0,
    ),

    // Meta tags enabled on admin settings pages.
    'nodewords_admin_edit' => array(
      'alexa_verification_code' => 'alexa_verification_code',
      'bing_webmaster_center'   => 'bing_webmaster_center',
      'google_webmaster_tools'  => 'google_webmaster_tools',
      'yahoo_site_explorer'     => 'yahoo_site_explorer',
      'yandex_webmaster_tools'  => 'yandex_webmaster_tools',
      'abstract'                => 0,
      'canonical'               => 0,
      'copyright'               => 0,
      'description'             => 0,
      'keywords'                => 0,
      'revisit-after'           => 0,
      'robots'                  => 0,
      'dc.contributor'          => 0,
      'dc.creator'              => 0,
      'dc.date'                 => 0,
      'dc.description'          => 0,
      'dc.publisher'            => 0,
      'dc.title'                => 0,
      'location'                => 0,
      'shorturl'                => 0,
    ),

    // Meta tags enabled on other edit forms.
    'nodewords_ui_edit' => array(
      'description'    => 'description',
      'keywords'       => 'keywords',
      'location'       => 'location',
      'shorturl'       => 'shorturl',
      'abstract'       => 0,
      'canonical'      => 0,
      'copyright'      => 0,
      'revisit-after'  => 0,
      'robots'         => 0,
      'dc.contributor' => 0,
      'dc.creator'     => 0,
      'dc.date'        => 0,
      'dc.description' => 0,
      'dc.title'       => 0,
    ),

    // Default values for meta tags in admin pages.
    'nodewords_admin_use_default_value_abstract'       => 'empty',
    'nodewords_admin_use_default_value_canonical'      => 'empty',
    'nodewords_admin_use_default_value_copyright'      => 'empty',
    'nodewords_admin_use_default_value_description'    => 'empty',
    'nodewords_admin_use_default_value_keywords'       => 'empty',
    'nodewords_admin_use_default_value_revisit-after'  => 'empty',
    'nodewords_admin_use_default_value_robots'         => 'empty',
    'nodewords_admin_use_default_value_dc.contributor' => 'empty',
    'nodewords_admin_use_default_value_dc.creator'     => 'empty',
    'nodewords_admin_use_default_value_dc.date'        => 'empty',
    'nodewords_admin_use_default_value_dc.description' => 'empty',
    'nodewords_admin_use_default_value_dc.publisher'   => 'empty',
    'nodewords_admin_use_default_value_dc.title'       => 'empty',
    'nodewords_admin_use_default_value_location'       => 'empty',
    'nodewords_admin_use_default_value_shorturl'       => 'empty',

    // Verification meta tags, available to set in admin settings pages.
    'nodewords_admin_use_default_value_alexa_verification_code' => 'empty',
    'nodewords_admin_use_default_value_bing_webmaster_center'   => 'empty',
    'nodewords_admin_use_default_value_google_webmaster_tools'  => 'empty',
    'nodewords_admin_use_default_value_yahoo_site_explorer'     => 'empty',
    'nodewords_admin_use_default_value_yandex_webmaster_tools'  => 'empty',

    // Default values for meta tags in other edit form.
    // Copyright and Robots always uses the configured default values.
    'nodewords_ui_use_default_value_abstract'       => 'empty',
    'nodewords_ui_use_default_value_canonical'      => 'empty',
    'nodewords_ui_use_default_value_copyright'      => 'always',
    'nodewords_ui_use_default_value_description'    => 'empty',
    'nodewords_ui_use_default_value_keywords'       => 'empty',
    'nodewords_ui_use_default_value_revisit-after'  => 'empty',
    'nodewords_ui_use_default_value_robots'         => 'always',
    'nodewords_ui_use_default_value_dc.contributor' => 'empty',
    'nodewords_ui_use_default_value_dc.creator'     => 'empty',
    'nodewords_ui_use_default_value_dc.date'        => 'empty',
    'nodewords_ui_use_default_value_dc.description' => 'empty',
    'nodewords_ui_use_default_value_dc.title'       => 'empty',
    'nodewords_ui_use_default_value_location'       => 'empty',
    'nodewords_ui_use_default_value_shorturl'       => 'empty',

    // Creation options.
    'nodewords_list_repeat'   => 0,
    'nodewords_enable_tokens' => TRUE,
    'nodewords_max_size'      => 120,
    'nodewords_base_url'      => '',
    'nodewords_list_robots_index_follow' => 'index,follow',
    'nodewords_list_robots_value' => array(
      'noarchive' => 0,
      'noodp'     => 0,
      'nosnippet' => 0,
      'noydir'    => 0,
    ),
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}
