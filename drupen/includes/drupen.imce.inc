<?php

/**
 * @file
 * IMCE configuration tasks.
 */

/**
 * Configures the IMCE module, creates the profiles 'Admin user' and
 * 'Authenticated user' and assigns the Drüpen user roles to the created
 * profiles.
 */
function _drupen_imce_configure(array $roles) {
  $admin_user = $authenticated_user = array(
    'name'        => '',
    'usertab'     => 1,
    'filesize'    => '0',
    'quota'       => '0',
    'tuquota'     => '0',
    'extensions'  => 'jpg jpeg gif png swf flv mp3 pdf docx xlsx pptm doc xls ppt odt ods odp txt rtf zip tgz tar.gz',
    'dimensions'  => '2000x2000',
    'filenum'     => '0',
    'mkdirnum'    => '0',
    'directories' => array(),
    'thumbnails'  => array(
      0 => array(
        'name' => t('Small'),
        'dimensions' => '120x120',
        'prefix' => 'small_',
        'suffix' => '',
      ),
      1 => array(
        'name' => t('Medium'),
        'dimensions' => '180x180',
        'prefix' => 'medium_',
        'suffix' => '',
      ),
      2 => array(
        'name' => t('Large'),
        'dimensions' => '240x240',
        'prefix' => 'large_',
        'suffix' => '',
      ),
      3 => array(
        'name' => t('Extra large'),
        'dimensions' => '300x300',
        'prefix' => 'xlarge_',
        'suffix' => '',
      ),
    ),
  );

  // This role can changes anything inside the 'uploads/' directories.
  $admin_user['name'] = 'Admin user';
  $admin_user['directories'] = array(
    0 => array(
      'name' => variable_get('private_download_directory', 'private'),
      'subnav' => 0,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 1,
      'resize' => 1,
      'mkdir' => 0,
      'rmdir' => 0,
    ),
    1 => array(
      'name' => 'uploads',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 1,
      'resize' => 1,
      'mkdir' => 1,
      'rmdir' => 1,
    ),
    2 => array(
      'name' => 'uploads/shared',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 1,
      'resize' => 1,
      'mkdir' => 1,
      'rmdir' => 1,
    ),
    3 => array(
      'name' => 'php: return \'uploads/users/\'.$user->name;',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 1,
      'resize' => 1,
      'mkdir' => 1,
      'rmdir' => 1,
    ),
    4 => array(
      'name' => 'imagecache',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 0,
      'thumb' => 0,
      'delete' => 0,
      'resize' => 0,
      'mkdir' => 0,
      'rmdir' => 0,
    ),
  );

  // This role can changes anything inside their 'uploads/users/uid' directory
  // and changes anything inside 'uploads/shared'. Can create up to 2 nested
  // directories.
  $authenticated_user['name'] = 'Authenticated user';
  $authenticated_user['mkdirnum'] = '2';
  $authenticated_user['directories'] = array(
    0 => array(
      'name' => variable_get('private_download_directory', 'private'),
      'subnav' => 0,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 0,
      'resize' => 1,
      'mkdir' => 0,
      'rmdir' => 0,
    ),
    1 => array(
      'name' => 'uploads',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 0,
      'thumb' => 0,
      'delete' => 0,
      'resize' => 0,
      'mkdir' => 0,
      'rmdir' => 0,
    ),
    2 => array(
      'name' => 'uploads/shared',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 1,
      'resize' => 1,
      'mkdir' => 1,
      'rmdir' => 1,
    ),
    3 => array(
      'name' => 'php: return \'uploads/users/\'.$user->name;',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 1,
      'thumb' => 1,
      'delete' => 1,
      'resize' => 1,
      'mkdir' => 1,
      'rmdir' => 1,
    ),
    4 => array(
      'name' => 'imagecache',
      'subnav' => 1,
      'browse' => 1,
      'upload' => 0,
      'thumb' => 0,
      'delete' => 0,
      'resize' => 0,
      'mkdir' => 0,
      'rmdir' => 0,
    ),
  );

  // Will not set permissions to private directory if module is not installed.
  if (!module_exists('private_download')) {
    unset($admin_user['directories'][0], $authenticated_user['directories'][0]);
  }

  // The IMCE profile with the '1' key will be our "User-1" profile. In this
  // case, the "Admin user" profile. This array MUST have numeric keys,
  // starting with 1.
  $imce_profiles = array(
    1 => $admin_user,
    2 => $authenticated_user,
  );

  $imce_roles_profiles = array(
    $roles['administrator'] => array(
      'weight' => '-10',
      'pid' => '1',
    ),
    $roles['editor'] => array(
      'weight' => '-9',
      'pid' => '1',
    ),
    $roles['assistant'] => array(
      'weight' => '-8',
      'pid' => '2',
    ),
    $roles['authenticated'] => array(
      'weight' => 11,
      'pid' => '0',
    ),
    $roles['anonymous'] => array(
      'weight' => 12,
      'pid' => '0',
    ),
  );

  variable_set('imce_profiles', $imce_profiles);
  variable_set('imce_roles_profiles', $imce_roles_profiles);
  variable_set('imce_settings_thumb_method', 'scale');
}
