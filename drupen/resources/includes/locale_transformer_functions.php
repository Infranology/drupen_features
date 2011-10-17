<?php

/**
 * @file
 * This file contains functions from the Symfony Locale component that are
 * released under the MIT license.
 *
 * Contains functions to transform the ICU date/time patterns to the format
 * accepted in the PHP date() function.
 *
 * The functions were ported from the Symfony\Component\Locale\Stub\DateFormat\FullTransformer
 * class.
 *
 * @link https://github.com/symfony/Locale/blob/v2.0.4/Stub/DateFormat/FullTransformer.php The Symfony Locale FullTransformer class
 * @link http://php.net/date The PHP date() function
 * @link http://userguide.icu-project.org/formatparse/datetime ICU Formatting Dates and Times
 */

// Builds the RegExp. We only supports chars related to date and time found
// in the parsed DateTimePatterns of the ICU locales data files.
$quoteMatch = "'(?:[^']+|'')*'";
$implementedChars = 'acdHhKkMmsyz';
$implementedCharsMatch = buildCharsMatch($implementedChars);
$regExp = "/($quoteMatch|$implementedCharsMatch)/";

$replaceChars = array(
    // Year
    'yy'   => 'y', // 09
    'y'    => 'Y', // 2009
    'yyyy' => 'Y', // 2009

    // Month
    'M'     => 'm', // 09
    'MM'    => 'm', // 09
    'MMM'   => 'M', // Sept, we don't have equivalent in date(), then we use the short format (Sep)
    'MMMM'  => 'F', // September
    'MMMMM' => 'M', // S, we don't have equivalent in date(), then, we use the short format (Sep)

    // Day
    'd'     => 'j', // 1 - 31
    'dd'    => 'd', // 01 - 31 (w/ leading zero)

    // Day of week (only the "fi" locale uses it, not really sure if "l" is equivalent)
    // Stand alone day of week, example at: http://icu-project.org/apiref/icu4c/classSimpleDateFormat.html
    'c'     => 'l',
    'cc'    => 'l',
    'ccc'   => 'l',
    'cccc'  => 'l',

    // Hour
    'h'     => 'g', // 1 - 12 (hour in am/pm)
    'hh'    => 'h', // 01 - 12 (hour in am/pm, w/ leading zero)
    'H'     => 'G', // 0 - 23
    'HH'    => 'H', // 00 - 23 (w/ leading zero)

    // Minute
    'm'     => 'i', // 0 - 59, without leading zero (we don't have equivalente in date(), then, we use with leading zero)
    'mm'    => 'i', // 00 - 59, (w/ leading zero)

    // Second
    's'     => 's', // 0 - 59, without leading zero (we don't have equivalente in date(), then, we use with leading zero)
    'ss'    => 's', // 00 - 59, (w/ leading zero)

    // AM/PM
    'a'     => 'a', // Lowercase AM/PM marker

    // Timezone
    'z'     => 'T', // Timezone abbreviation
    'zz'    => 'T', // Timezone abbreviation
    'zzz'   => 'T', // Timezone abbreviation
    'zzzz'  => 'e', // Timezone identifier
);

function format($pattern)
{
    global $regExp;

    $formatted = preg_replace_callback($regExp, function($matches) {
        return formatReplace($matches[0]);
    }, $pattern);

    return $formatted;
}

function formatReplace($dateChars)
{
    global $replaceChars;

    if (!isset($replaceChars[$dateChars])) {
        // If quoted strings, escapes every char.
        if (0 === strpos($dateChars, "'")) {
            $dateChars = str_replace("'", '', $dateChars);

            // See: http://www.php.net/manual/en/function.mb-split.php#99851
            $dateChars = preg_split('/(?<!^)(?!$)/u', $dateChars);

            return '\\' . implode('\\', $dateChars);
        } else {
            return $dateChars;
        }
    }

    return $replaceChars[$dateChars];
}

function buildCharsMatch($specialChars)
{
    $specialCharsArray = str_split($specialChars);

    $specialCharsMatch = implode('|', array_map(function($char) {
        return $char.'+';
    }, $specialCharsArray));

    return $specialCharsMatch;
}
