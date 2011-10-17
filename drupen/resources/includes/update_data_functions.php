<?php

/**
 * @file
 * This file contains functions from the Symfony Locale component that are
 * released under the MIT license.
 *
 * @link https://github.com/symfony/Locale/blob/v2.0.4/Resources/data/update-data.php Original file
 */

function bailout($message)
{
    exit($message."\n");
}

function check_dir($source)
{
    if (!file_exists($source)) {
        bailout('The directory '.$source.' does not exist');
    }

    if (!is_dir($source)) {
        bailout('The file '.$source.' is not a directory');
    }
}

function check_command($command)
{
    exec('which '.$command, $output, $result);

    if ($result !== 0) {
        bailout('The command "'.$command.'" is not installed');
    }
}

function clear_directory($directory)
{
    $iterator = new \DirectoryIterator($directory);

    foreach ($iterator as $file) {
        if (!$file->isDot()) {
            if ($file->isDir()) {
                clear_directory($file->getPathname());
            } else {
                unlink($file->getPathname());
            }
        }
    }
}

function make_directory($directory)
{
    if (!file_exists($directory)) {
        mkdir($directory);
    }

    if (!is_dir($directory)) {
        bailout('The file '.$directory.' already exists but is no directory');
    }
}

function list_files($directory, $extension)
{
    $files = array();
    $iterator = new \DirectoryIterator($directory);

    foreach ($iterator as $file) {
        if (!$file->isDot() && substr($file->getFilename(), -strlen($extension)) === $extension) {
            $files[] = substr($file->getFilename(), 0, -strlen($extension));
        }
    }

    return $files;
}

function genrb($source, $target)
{
    exec('genrb -d '.$target.' '.$source.DIRECTORY_SEPARATOR.'*.txt', $output, $result);

    if ($result !== 0) {
        bailout('genrb failed');
    }
}

function load_resource_bundle($locale, $directory)
{
    $bundle = \ResourceBundle::create($locale, $directory);

    if (null === $bundle) {
        bailout('The resource bundle for locale '.$locale.' could not be loaded from directory '.$directory);
    }

    return $bundle;
}
