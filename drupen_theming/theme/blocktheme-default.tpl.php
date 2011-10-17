<?php

/**
 * @file blocktheme-default.tpl.php
 *
 * Theme implementation to display a blocktheme block. This template file is
 * based on block.tpl.php from the Zen Ninesixty theme.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $block->content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: This is a numeric id connected to each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: A set of CSS classes for the DIV wrapping the block.
 *   Possible values are: block-MODULE, region-odd, region-even, odd, even,
 *   region-count-X, and count-X.
 *
 * Helper variables:
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see drupen_theming_blocktheme_classes()
 */

if (!isset($blocktheme_vars)) {
  $blocktheme_vars = array();
}

if (!isset($blocktheme_child_vars)) {
  $blocktheme_child_vars = array();
}

// Classes variables.
$block_classes = drupen_theming_blocktheme_classes('block_classes', $blocktheme_vars, $blocktheme_child_vars);
$title_classes = drupen_theming_blocktheme_classes('title_classes', $blocktheme_vars, $blocktheme_child_vars);
$content_classes = drupen_theming_blocktheme_classes('content_classes', $blocktheme_vars, $blocktheme_child_vars);

// The $class variable is available in Zen based themes.
$block_classes = isset($classes) ?
  $classes . $block_classes :
  $block_classes;

?>
<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="<?php print $block_classes; ?>"><div class="block-inner">

  <?php if ($block->subject): ?>
    <h2 class="title<?php print $title_classes; ?>"><?php print $block->subject; ?></h2>
  <?php endif; ?>

  <div class="content<?php print $content_classes; ?>">
    <?php print $block->content; ?>
  </div>

  <?php // Available in Zen based themes. ?>
  <?php if (isset($edit_links)): ?>
    <?php print $edit_links; ?>
  <?php endif; ?>

</div></div> <!-- /block-inner, /block -->
