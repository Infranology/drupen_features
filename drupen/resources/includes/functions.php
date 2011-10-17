<?php

include_once __DIR__.'/update_data_functions.php';
include_once __DIR__.'/locale_transformer_functions.php';

function create_data_file($filename, $target, $data, $dataRevision) {
    $template = <<<TEMPLATE
<?php

/*
 * Based on ICU data, SVN r%s.
 */

return %s;

TEMPLATE;

  $data = var_export($data, true);
  $data = preg_replace('/array \(/', 'array(', $data);
  $data = preg_replace('/\n {1,10}array\(/', 'array(', $data);
  $data = sprintf($template, $dataRevision, $data);

  file_put_contents($target.DIRECTORY_SEPARATOR.$filename.'.php', $data);
}

function svn_info($target)
{
    exec('svn info '.$target, $output, $result);

    if ($result !== 0) {
        bailout('genrb failed');
    }

    foreach ($output as $data) {
        if (1 === preg_match('/Revision: (?P<revision>[0-9]{1,9})/', $data, $matches)) {
            if (isset($matches['revision'])) {
                return $matches['revision'];
            } else {
                bailout('Failed to retrieve the SVN revision.');
            }
        }
    }
}

function print_check($format, $original, $converted) {
    $ret  = '%s: ' . PHP_EOL;
    $ret .= '  original:      %s' . PHP_EOL;
    $ret .= '  converted:     %s' . PHP_EOL;
    $ret .= '  date() output: %s' . PHP_EOL;
    $ret .= PHP_EOL;

    return sprintf($ret, $format, $original, $converted, date($converted));
}
