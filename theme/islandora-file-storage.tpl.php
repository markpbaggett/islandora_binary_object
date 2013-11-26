<?php

/**
 * @file
 * This is the template file for the object page for file storage objects.
 *
 * Available variables:
 * - $islandora_object: The Islandora object rendered in this template file.
 * - $islandora_file_storage_info: Information about the file storage object.
 * - $islandora_thumbnail_img: The thumbnail image of the file storage object.
 * - $islandora_File_storage_download: Download link for the object.
 * - $description: Defined metadata descripton for the object.
 * - $parent_collections: Parent collections of the object if applicable.
 * - $metadata: Rendered metadata display for the file storage object.
 *
 * @see template_preprocess_islandora_file_storage()
 * @see theme_islandora_file_storage()
 */
?>

<div class="islandora-file-storage-object islandora">
  <div class="islandora-file-storage-content-wrapper clearfix">
    <?php if (isset($islandora_file_storage_info)): ?>
      <?php print $islandora_file_storage_info; ?>
    <?php endif; ?>
    <?php if (isset($islandora_thumbnail_img)): ?>
      <div class="islandora-file-storage-content">
        <?php print $islandora_thumbnail_img; ?>
      </div>
    <?php endif; ?>
    <?php if (isset($islandora_file_storage_download)): ?>
      <?php print $islandora_file_storage_download; ?>
    <?php endif; ?>
  </div>
  <div class="islandora-file-storage-metadata">
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
