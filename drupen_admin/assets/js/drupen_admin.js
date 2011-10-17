Drupal.behaviors.drupen_admin = function(context) {
  // If node form page, make the links inside the form to open in a new window.
  var isNodeForm = (1 === $('form#node-form').length) ? true : false;

  if (isNodeForm) {
    $('form#node-form a').each(function() {
      var href = $(this).attr('href').trim();

      // URLs not starting with javascript:
      if (href != 'javascript:') {
        $(this).attr('target', 'blank');
      }
    });
  }
}
