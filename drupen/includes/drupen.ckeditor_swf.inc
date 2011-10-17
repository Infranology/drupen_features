<?php

/**
 * @file
 * CKEditor SWF configuration tasks.
 */

/**
 * Configures the CKEditor SWF module.
 */
function _drupen_ckeditor_swf_configure() {
  $variables = array(
    // This is a result of the parsed code bellow ('ckeditor_swf_players_php').
    'ckeditor_swf_players' => array(
      'audio/mpeg' => array(
        'path'          => libraries_get_path('players') . '/audio-player/player.swf',
        'offsetHeight'  => 0,
        'fileName'      => 'soundFile',
        'defaultWidth'  => 290,
        'defaultHeight' => 24,
      ),
    ),

    // This is presented in the module's admin settings page.
    'ckeditor_swf_players_php' => "return array(
  'audio/mpeg' => array(
    'path'          => libraries_get_path('players') . '/audio-player/player.swf',
    'offsetHeight'  => 0,
    'fileName'      => 'soundFile',
    'defaultWidth'  => 290,
    'defaultHeight' => 24,
  ),
);"
  );

  // getID3() variable, without it, the player will not be loaded.
  if (module_exists('getid3')) {
    $variables['getid3_path'] = libraries_get_path('getid3') . '/getid3';
  }

  foreach ($variables as $name => $value) {
    variable_set($name, $value);
  }
}
