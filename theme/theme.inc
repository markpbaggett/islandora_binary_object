<?php
/**
 * @file
 * Handles the display of binary objects.
 */

/**
 * Implements hook_preprocess_theme().
 */
function template_preprocess_islandora_binary_object(array &$variables) {
  module_load_include('inc', 'islandora', 'includes/metadata');
  drupal_add_js('misc/form.js');
  drupal_add_js('misc/collapse.js');

  $islandora_object = $variables['islandora_object'];

  if (isset($islandora_object['OBJ']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['OBJ'])) {
    $mime_detect = new MimeDetect();
    $extension = $mime_detect->getExtension($islandora_object['OBJ']->mimetype);

    $variables['islandora_binary_object_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
      '@extension' => $extension,
      '@size' => format_size($islandora_object['OBJ']->size),
    ));

    $display['download'] = array(
      '#type' => 'item',
      '#title' => t('Download'),
      '#markup' => l(t('@label', array('@label' => $islandora_object['OBJ']->label)), "islandora/object/$islandora_object->id/datastream/OBJ/download"),
    );
    $variables['islandora_binary_object_download'] = drupal_render($display['download']);
  }

  // Thumbnail.
  if (isset($islandora_object['TN']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['TN'])) {
    $thumbnail_size_url = url("islandora/object/{$islandora_object->id}/datastream/TN/view");
    $params = array(
      'title' => $islandora_object->label,
      'path' => $thumbnail_size_url,
    );
    $variables['islandora_thumbnail_img'] = theme('image', $params);
  }
  // Supplemental Files
    if (isset($islandora_object['SUPPLEMENT']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT']->mimetype);

        $variables['islandora_supplement_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT']->size),
        ));

        $display['download_supplement'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT/download"),
        );
        $variables['islandora_supplement_download'] = drupal_render($display['download_supplement']);
    }
    if (isset($islandora_object['SUPPLEMENT2']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT2'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT2']->mimetype);

        $variables['islandora_supplement2_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT2']->size),
        ));

        $display['download_supplement2'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT2']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT2/download"),
        );
        $variables['islandora_supplement2_download'] = drupal_render($display['download_supplement2']);
    }
    if (isset($islandora_object['SUPPLEMENT3']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT3'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT3']->mimetype);

        $variables['islandora_supplement3_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT3']->size),
        ));

        $display['download_supplement3'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT3']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT3/download"),
        );
        $variables['islandora_supplement3_download'] = drupal_render($display['download_supplement3']);
    }
    if (isset($islandora_object['SUPPLEMENT4']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT4'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT4']->mimetype);

        $variables['islandora_supplement4_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT4']->size),
        ));

        $display['download_supplement4'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT4']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT4/download"),
        );
        $variables['islandora_supplement4_download'] = drupal_render($display['download_supplement4']);
    }
    if (isset($islandora_object['SUPPLEMENT5']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT5'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT5']->mimetype);

        $variables['islandora_supplement5_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT5']->size),
        ));

        $display['download_supplement5'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT5']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT5/download"),
        );
        $variables['islandora_supplement5_download'] = drupal_render($display['download_supplement5']);
    }
    if (isset($islandora_object['SUPPLEMENT6']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT6'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT6']->mimetype);

        $variables['islandora_supplement6_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT6']->size),
        ));

        $display['download_supplement6'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT6']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT6/download"),
        );
        $variables['islandora_supplement6_download'] = drupal_render($display['download_supplement6']);
    }
    if (isset($islandora_object['SUPPLEMENT7']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT7'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT7']->mimetype);

        $variables['islandora_supplement7_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT7']->size),
        ));

        $display['download_supplement7'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT7']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT7/download"),
        );
        $variables['islandora_supplement7_download'] = drupal_render($display['download_supplement7']);
    }
    if (isset($islandora_object['SUPPLEMENT8']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT8'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT8']->mimetype);

        $variables['islandora_supplement8_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT8']->size),
        ));

        $display['download_supplement8'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT8']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT8/download"),
        );
        $variables['islandora_supplement8_download'] = drupal_render($display['download_supplement8']);
    }
    if (isset($islandora_object['SUPPLEMENT9']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT9'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT9']->mimetype);

        $variables['islandora_supplement9_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT9']->size),
        ));

        $display['download_supplement9'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT9']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT9/download"),
        );
        $variables['islandora_supplement9_download'] = drupal_render($display['download_supplement9']);
    }
    if (isset($islandora_object['SUPPLEMENT10']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT10'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT10']->mimetype);

        $variables['islandora_supplement10_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT10']->size),
        ));

        $display['download_supplement10'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT10']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT10/download"),
        );
        $variables['islandora_supplement10_download'] = drupal_render($display['download_supplement10']);
    }
    if (isset($islandora_object['SUPPLEMENT11']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT11'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT11']->mimetype);

        $variables['islandora_supplement11_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT11']->size),
        ));

        $display['download_supplement11'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT11']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT11/download"),
        );
        $variables['islandora_supplement11_download'] = drupal_render($display['download_supplement11']);
    }
    if (isset($islandora_object['SUPPLEMENT12']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT12'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT12']->mimetype);

        $variables['islandora_supplement12_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT12']->size),
        ));

        $display['download_supplement12'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT12']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT12/download"),
        );
        $variables['islandora_supplement12_download'] = drupal_render($display['download_supplement12']);
    }
    if (isset($islandora_object['SUPPLEMENT13']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT13'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT13']->mimetype);

        $variables['islandora_supplement13_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT13']->size),
        ));

        $display['download_supplement13'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT13']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT13/download"),
        );
        $variables['islandora_supplement13_download'] = drupal_render($display['download_supplement13']);
    }
    if (isset($islandora_object['SUPPLEMENT14']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT14'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT14']->mimetype);

        $variables['islandora_supplement14_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT14']->size),
        ));

        $display['download_supplement14'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT14']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT14/download"),
        );
        $variables['islandora_supplement14_download'] = drupal_render($display['download_supplement14']);
    }
    if (isset($islandora_object['SUPPLEMENT15']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT15'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT15']->mimetype);

        $variables['islandora_supplement15_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT15']->size),
        ));

        $display['download_supplement15'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT15']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT15/download"),
        );
        $variables['islandora_supplement15_download'] = drupal_render($display['download_supplement15']);
    }
    if (isset($islandora_object['SUPPLEMENT16']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT16'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT16']->mimetype);

        $variables['islandora_supplement16_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT16']->size),
        ));

        $display['download_supplement16'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT16']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT16/download"),
        );
        $variables['islandora_supplement16_download'] = drupal_render($display['download_supplement16']);
    }
    if (isset($islandora_object['SUPPLEMENT17']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT17'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT17']->mimetype);

        $variables['islandora_supplement17_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT17']->size),
        ));

        $display['download_supplement17'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT17']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT17/download"),
        );
        $variables['islandora_supplement17_download'] = drupal_render($display['download_supplement17']);
    }
    if (isset($islandora_object['SUPPLEMENT18']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT18'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT18']->mimetype);

        $variables['islandora_supplement18_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT18']->size),
        ));

        $display['download_supplement18'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT18']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT18/download"),
        );
        $variables['islandora_supplement18_download'] = drupal_render($display['download_supplement18']);
    }
    if (isset($islandora_object['SUPPLEMENT19']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT19'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT19']->mimetype);

        $variables['islandora_supplement19_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT19']->size),
        ));

        $display['download_supplement19'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT19']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT19/download"),
        );
        $variables['islandora_supplement19_download'] = drupal_render($display['download_supplement19']);
    }
    if (isset($islandora_object['SUPPLEMENT20']) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $islandora_object['SUPPLEMENT20'])) {
        $mime_detect = new MimeDetect();
        $extension = $mime_detect->getExtension($islandora_object['SUPPLEMENT20']->mimetype);

        $variables['islandora_supplement20_info'] = t('This is a downloadable object of filetype @extension and size @size.', array(
            '@extension' => $extension,
            '@size' => format_size($islandora_object['SUPPLEMENT20']->size),
        ));

        $display['download_supplement20'] = array(
            '#type' => 'item',
            '#title' => t('Download Supplemental File'),
            '#markup' => l(t('@label', array('@label' => $islandora_object['SUPPLEMENT20']->label)), "islandora/object/$islandora_object->id/datastream/SUPPLEMENT20/download"),
        );
        $variables['islandora_supplement20_download'] = drupal_render($display['download_supplement20']);
    }
  $variables['parent_collections'] = islandora_get_parents_from_rels_ext($islandora_object);
  $variables['metadata'] = islandora_retrieve_metadata_markup($islandora_object);
  $variables['description'] = islandora_retrieve_description_markup($islandora_object);
}
