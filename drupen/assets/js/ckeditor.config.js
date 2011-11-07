CKEDITOR.editorConfig = function(config) {
  config.indentClasses  = ['indent-1', 'indent-2', 'indent-3', 'indent-4'];
  config.justifyClasses = ['text-left', 'text-center', 'text-right', 'text-justify'];

  // The minimum editor width, in pixels, when resizing it with the resize handle.
  config.resize_minWidth = 450;

  // Protect PHP code tags (<?...?>) so CKEditor will not break them when
  // switching from Source to WYSIWYG.
  config.protectedSource.push(/<\?[\s\S]*?\?>/g); // PHP Code
  config.protectedSource.push(/<code>[\s\S]*?<\/code>/gi); // Code tags
};
