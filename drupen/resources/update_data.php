<?php

/**
 * @file
 * Updates the data used to configure the Date module with date patterns
 * from the ICU data.
 */

include_once __DIR__.'/includes/functions.php';

if ('cli' !== PHP_SAPI) {
    bailout('This file can only be executed in CLI mode.');
}

if ($GLOBALS['argc'] !== 3) {
    bailout(<<<MESSAGE
Usage: php update_data.php [drupal-includes-directory] [icu-data-directory]

Updates the data used to configure the Date module with date patterns from the
ICU data. You can checkout the ICU data directory via SVN:

    $ svn co http://source.icu-project.org/repos/icu/icu/trunk/source/data icu-data

MESSAGE
    );
}

// Check commands availability.
check_command('genrb');
check_command('svn');

// This define is only to not include the bootstrap.inc file.
define('LANGUAGE_RTL', 1);

// Include the Drupal locale.inc file.
$includes_dir = $GLOBALS['argv'][1];
check_dir($includes_dir);
$includes_dir = realpath($includes_dir);

if (!file_exists($includes_dir.'/locale.inc')) {
    bailout('Could not find the locale.inc file in the '.$includes_dir.' directory');
}

include_once $includes_dir.'/locale.inc';

// Verify that all required directories exist
$source = $GLOBALS['argv'][2];
check_dir($source);
$source = realpath($source);

check_dir($source.DIRECTORY_SEPARATOR.'locales');

// Get the ICU data SVN revision.
$dataRevision = svn_info($source);

// Convert the *.txt resource bundles to *.res files
$target = __DIR__;
$dataDir = $target.DIRECTORY_SEPARATOR.'data';
$localesDir = $target.DIRECTORY_SEPARATOR.'locales';

make_directory($dataDir);
make_directory($localesDir);

clear_directory($localesDir);
genrb($source.DIRECTORY_SEPARATOR.'locales', $localesDir);

// Discover the list of supported locales, which are the names of the resource
// bundles in the "locales" directory
$supportedLocales = list_files($localesDir, '.res');

sort($supportedLocales);

// Get the locales defined in Drupal.
$drupalLocales = _locale_get_predefined_list();

// Date/Time formats.
$formats = array(
    0 => 'full time',
    1 => 'long time',
    2 => 'medium time',
    3 => 'short time',
    4 => 'full date',
    5 => 'long date',
    6 => 'medium date',
    7 => 'short date',
);

$data = array();

foreach ($supportedLocales as $supportedLocale) {
    // Drupal locales are all lowercase and uses dash as separator.
    $drupalLocale = strtolower(str_replace('_', '-', $supportedLocale));

    // Skips if locale is not available in Drupal.
    if (!isset($drupalLocales[$drupalLocale])) {
        continue;
    }

    $localeBundle = load_resource_bundle($supportedLocale, $localesDir);

    foreach ($localeBundle->get('calendar') as $k => $v) {
        // We only get date/time from the Gregorian calendar.
        if ('gregorian' === $k) {
            $dateTimePatterns = $v->get('DateTimePatterns');

            // Error, the locale does not have this data.
            if (null === $dateTimePatterns) {
                continue;
            }

            $i = -1;
            $data[$drupalLocale] = array();
            foreach ($dateTimePatterns as $k2 => $v2) {
                if ($i++ >= 7) {
                    break;
                }

                $data[$drupalLocale][$formats[$i]] = $v2;
            }
        }
    }
}

// Save file with the ICU date/time patterns.
create_data_file('icu_datetime_patterns', $dataDir, $data, $dataRevision);
clear_directory($localesDir);

// Generates the PHP datetime patterns file.
$localesFormats = $data;

$data = array();
foreach ($localesFormats as $locale => $formats) {
    // The formats used by Date module uses the dash separator between date
    // and time.
    $long   = $formats['long date'] . ' - ' . $formats['long time'];
    $medium = $formats['medium date'] . ' - ' . $formats['medium time'];
    $short  = $formats['short date'] . ' - ' . $formats['short time'];

    // Transforms the patterns to the format accepted by PHP date() function.
    $data[$locale] = array(
        'long'   => format($long),
        'medium' => format($medium),
        'short'  => format($short)
    );
}

// Save file with the PHP date/time patterns.
create_data_file('php_datetime_patterns', __DIR__.'/data', $data, $dataRevision);
