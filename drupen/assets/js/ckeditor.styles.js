CKEDITOR.stylesSet.add('drupal',
[
  /* Block Styles */
  { name : Drupal.t('Heading 1'), element: 'h1' },
  { name : Drupal.t('Heading 2'), element: 'h2' },
  { name : Drupal.t('Heading 3'), element: 'h3' },
  { name : Drupal.t('Heading 4'), element: 'h4' },
  { name : Drupal.t('Heading 5'), element: 'h5' },
  { name : Drupal.t('Heading 6'), element: 'h6' },

  /* Inline Styles */
  { name : Drupal.t('Cited Work'), element : 'cite' },
  { name : Drupal.t('Computer Code'), element : 'code' },
  { name : Drupal.t('Deleted Text'), element : 'del' },
  { name : Drupal.t('Inserted Text'), element : 'ins' },
  { name : Drupal.t('Inline Quotation'), element : 'q' },
  { name : Drupal.t('Language: RTL'), element : 'span', attributes : { 'dir' : 'rtl' } },
  { name : Drupal.t('Language: LTR'), element : 'span', attributes : { 'dir' : 'ltr' } },
  { name : Drupal.t('Keyboard Phrase'), element : 'kbd' },
  { name : Drupal.t('Sample Text'), element : 'samp' },
  { name : Drupal.t('Typewriter'), element : 'tt' },
  { name : Drupal.t('Variable'), element : 'var' },

  /* Object Styles */
  { name : Drupal.t('Image on left'), element : 'img', attributes : { 'class' : 'float-left' } },
  { name : Drupal.t('Image on right'), element : 'img', attributes : { 'class' : 'float-right' } },
]);
