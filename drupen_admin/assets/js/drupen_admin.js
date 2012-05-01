Drupal.behaviors.drupen_admin = function(context) {
  // If node form page, make the links inside the form to open in a new window.
  var isNodeForm = (1 === $('form#node-form').length) ? true : false;

  if (isNodeForm) {
    $('form#node-form a').each(function() {
      var id = $(this).attr('id').trim();
      var href = $(this).attr('href').trim();

      // Won't open a new window for the switch editor link.
      if  (id === 'switch_edit-body') {
        return;
      }

      // URLs not starting with javascript:
      if (href !== 'javascript:') {
        $(this).attr('target', 'blank');
      }
    });
  }
}
