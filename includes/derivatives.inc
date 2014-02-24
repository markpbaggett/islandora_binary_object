<?php

/**
 * @file
 * Function deriving the default thumbnail for file storage of blobs.
 */

/**
 * Sets the default thumbnail when no other thumbnail has been set.
 *
 * @param AbstractObject $object
 *   An AbstractObject representing a Fedora object.
 * @param bool $force
 *   Whether derivative generation is being forced or not.
 *
 * @return array
 *   An array describing the outcome of the thumbnail creation.
 *
 * @see hook_islandora_derivative()
 */
function islandora_binary_object_create_thumbnail(AbstractObject $object, $force = FALSE) {
  if ($force || !isset($object['TN'])) {
    try {
      $module_path = drupal_get_path('module', 'islandora_file_storage');
      $ingest = !isset($object['TN']);
      if ($ingest) {
        $ds = $object->constructDatastream('TN', 'M');
        $ds->label = t('Thumbnail');
      }
      else {
        $ds = $object['TN'];
      }
      $ds->mimetype = 'image/png';
      $ds->setContentFromFile("$module_path/images/file_storage_thumb.png", FALSE);
      if ($ingest) {
        $object->ingestDatastream($ds);
      }
      return array(
        'success' => TRUE,
        'messages' => array(
          array(
            'message' => t('The TN datastream was added successfully for @pid!'),
            'message_sub' => array('@pid' => $object->id),
            'type' => 'dsm',
          ),
        ),
      );
    }
    catch (exception $e) {
      $message = $e->getMessage();
      return array(
        'success' => FALSE,
        'messages' => array(
          array(
            'message' => $message,
            'type' => 'watchdog',
            'severity' => WATCHDOG_ERROR,
          ),
        ),
      );
    }
  }
}
