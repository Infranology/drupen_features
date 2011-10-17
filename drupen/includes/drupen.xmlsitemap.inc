<?php

/**
 * @file
 * XMLSitemap configuration tasks.
 */

/**
 * Configures the XMLSitemap module.
 */
function _drupen_xmlsitemap_configure() {
  $variables = array(
    'xmlsitemap_batch_limit' => 100,
    'xmlsitemap_chunk_size' => 'auto',
    'xmlsitemap_developer_mode' => 0,
    'xmlsitemap_frontpage_changefreq' => 86400,
    'xmlsitemap_frontpage_priority' => '1.0',
    'xmlsitemap_lastmod_format' => 'c',
    'xmlsitemap_max_chunks' => 0,
    'xmlsitemap_max_filesize' => 0,
    'xmlsitemap_minimum_lifetime' => 86400,
    'xmlsitemap_path' => 'xmlsitemap',
    'xmlsitemap_prefetch_aliases' => 1,
    'xmlsitemap_settings_menu_link_primary-links' => array(
      'status' => 1,
      'priority' => 0.6,
    ),
    'xmlsitemap_xsl' => 1,
  );

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}