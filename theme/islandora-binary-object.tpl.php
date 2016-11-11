<?php

/**
 * @file
 * This is the template file for the object page for binary objects.
 *
 * Available variables:
 * - $islandora_object: The Islandora object rendered in this template file.
 * - $islandora_binary_object_info: Information about the binary object.
 * - $islandora_thumbnail_img: The thumbnail image of the binary object.
 * - $islandora_binary_object_download: Download link for the object.
 * - $description: Defined metadata descripton for the object.
 * - $parent_collections: Parent collections of the object if applicable.
 * - $metadata: Rendered metadata display for the binary object.
 *
 * @see template_preprocess_islandora_binary_object()
 * @see theme_islandora_binary_object()
 */
?>
<div class="islandora-binary-object-object islandora">
  <div class="islandora-binary-object-content-wrapper clearfix">
    <?php if (isset($islandora_binary_object_info)): ?>
      <?php print $islandora_binary_object_info; ?>
    <?php endif; ?>
    <?php if (isset($islandora_thumbnail_img)): ?>
      <div class="islandora-binary-object-content">
        <?php print $islandora_thumbnail_img; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($islandora_binary_object_download)): ?>
      <?php print $islandora_binary_object_download; ?>
    <?php endif; ?>
      <?php if (isset($islandora_supplement_download)): ?>
          <?php print $islandora_supplement_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement2_download)): ?>
          <?php print $islandora_supplement2_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement3_download)): ?>
          <?php print $islandora_supplement3_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement3_download)): ?>
          <?php print $islandora_supplement3_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement4_download)): ?>
          <?php print $islandora_supplement4_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement5_download)): ?>
          <?php print $islandora_supplement5_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement6_download)): ?>
          <?php print $islandora_supplement6_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement7_download)): ?>
          <?php print $islandora_supplement7_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement8_download)): ?>
          <?php print $islandora_supplement8_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement9_download)): ?>
          <?php print $islandora_supplement9_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement10_download)): ?>
          <?php print $islandora_supplement10_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement11_download)): ?>
          <?php print $islandora_supplement11_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement12_download)): ?>
          <?php print $islandora_supplement12_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement13_download)): ?>
          <?php print $islandora_supplement13_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement14_download)): ?>
          <?php print $islandora_supplement14_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement15_download)): ?>
          <?php print $islandora_supplement15_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement16_download)): ?>
          <?php print $islandora_supplement16_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement17_download)): ?>
          <?php print $islandora_supplement17_download; ?>
      <?php endif; ?>
    <?php if (isset($islandora_supplement18_download)): ?>
        <?php print $islandora_supplement18_download; ?>
    <?php endif; ?>
      <?php if (isset($islandora_supplement19_download)): ?>
          <?php print $islandora_supplement19_download; ?>
      <?php endif; ?>
      <?php if (isset($islandora_supplement20_download)): ?>
          <?php print $islandora_supplement20_download; ?>
      <?php endif; ?>
  </div>
  <div class="islandora-binary-object-metadata">
    <?php print $description; ?>
    <?php if ($parent_collections): ?>
      <div>
        <h2><?php print t('In collections'); ?></h2>
        <ul>
          <?php foreach ($parent_collections as $collection): ?>
            <li><?php print l($collection->label, "islandora/object/{$collection->id}"); ?></li>
          <?php endforeach; ?>
        </ul>
      </div>
    <?php endif; ?>
    <?php print $metadata; ?>
  </div>
</div>
