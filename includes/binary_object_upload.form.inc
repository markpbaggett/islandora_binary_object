<?php

/**
 * @file
 * Handles the uploading of the file as part of the ingest process.
 */

/**
 * Defines a file upload form for uploading the file for storage.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_binary_object_upload_form(array $form, array &$form_state)
{
    $upload_size = min((int)ini_get('post_max_size'), (int)ini_get('upload_max_filesize'));
    $thumbnail_extensions = array('gif jpg png jpeg');

    return array(
        'file' => array(
            '#title' => t('File'),
            '#type' => 'managed_file',
            '#required' => TRUE,
            '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
            '#default_value' => isset($form_state['values']['file']) ? $form_state['values']['file'] : NULL,
            '#upload_location' => 'temporary://',
            '#upload_validators' => array(
                // Assume its specified in MB.
                'file_validate_extensions' => array(),
                'file_validate_size' => array($upload_size * 1024 * 1024),
            ),
        ),
        'supply_thumbnail' => array(
            '#type' => 'checkbox',
            '#title' => t('Upload Thumbnail'),
        ),
        'thumbnail_section' => array(
            'thumbnail_file' => array(
                '#title' => t('Thumbnail File'),
                '#type' => 'managed_file',
                '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong><br/>Allowed file types: <strong>@ext.</strong>', array('@size' => $upload_size, '@ext' => $thumbnail_extensions[0])),
                '#default_value' => isset($form_state['values']['thumbnail_file']) ? $form_state['values']['thumbnail_file'] : NULL,
                '#upload_location' => 'temporary://',
                '#upload_validators' => array(
                    'file_validate_extensions' => $thumbnail_extensions,
                    // Assume its specified in MB.
                    'file_validate_size' => array($upload_size * 1024 * 1024),
                ),
            ),
            'scale_thumbnail' => array(
                '#type' => 'checkbox',
                '#title' => t('Scale Thumbnail'),
                '#attributes' => array('checked' => 'checked'),
            ),
            '#type' => 'item',
            '#states' => array(
                'visible' => array('#edit-supply-thumbnail' => array('checked' => TRUE)),
            ),
        ),
        'supply_supplemental' => array(
            '#type' => 'checkbox',
            '#title' => t('Upload Supplemental Files'),
        ),
        'supplemental_section' => array(
            'supplemental_file' => array(
                '#title' => t('Supplemental File 1'),
                '#type' => 'managed_file',
                '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                '#default_value' => isset($form_state['values']['supplemental_file']) ? $form_state['values']['supplemental_file'] : NULL,
                '#upload_location' => 'temporary://',
                '#upload_validators' => array(
                    'file_validate_extensions' => array(),
                    'file_validate_size' => array($upload_size * 1024 * 1024),
                ),
            ),
            'supplemental_file2' => array(
                '#title' => t('Supplemental File 2'),
                '#type' => 'managed_file',
                '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                '#default_value' => isset($form_state['values']['supplemental_file2']) ? $form_state['values']['supplemental_file2'] : NULL,
                '#upload_location' => 'temporary://',
                '#upload_validators' => array(
                    'file_validate_extensions' => array(),
                    'file_validate_size' => array($upload_size * 1024 * 1024),
                ),
            ),
            'supplemental_file3' => array(
                '#title' => t('Supplemental File 3'),
                '#type' => 'managed_file',
                '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                '#default_value' => isset($form_state['values']['supplemental_file3']) ? $form_state['values']['supplemental_file3'] : NULL,
                '#upload_location' => 'temporary://',
                '#upload_validators' => array(
                    'file_validate_extensions' => array(),
                    'file_validate_size' => array($upload_size * 1024 * 1024),
                ),
            ),
            'supplemental_file4' => array(
                '#title' => t('Supplemental File 4'),
                '#type' => 'managed_file',
                '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                '#default_value' => isset($form_state['values']['supplemental_file4']) ? $form_state['values']['supplemental_file4'] : NULL,
                '#upload_location' => 'temporary://',
                '#upload_validators' => array(
                    'file_validate_extensions' => array(),
                    'file_validate_size' => array($upload_size * 1024 * 1024),
                ),
            ),
            'supplemental_file5' => array(
                '#title' => t('Supplemental File 5'),
                '#type' => 'managed_file',
                '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                '#default_value' => isset($form_state['values']['supplemental_file5']) ? $form_state['values']['supplemental_file5'] : NULL,
                '#upload_location' => 'temporary://',
                '#upload_validators' => array(
                    'file_validate_extensions' => array(),
                    'file_validate_size' => array($upload_size * 1024 * 1024),
                ),
            ),
            '#type' => 'item',
            '#states' => array(
                'visible' => array('#edit-supply-supplemental' => array('checked' => TRUE)),
            ),
            'supply_more_supplementals' => array(
                '#type' => 'checkbox',
                '#title' => t('Upload 5 More Supplemental Files'),
            ),
            'supplemental_section' => array(
                'supplemental_file6' => array(
                    '#title' => t('Supplemental File 6'),
                    '#type' => 'managed_file',
                    '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                    '#default_value' => isset($form_state['values']['supplemental_file6']) ? $form_state['values']['supplemental_file6'] : NULL,
                    '#upload_location' => 'temporary://',
                    '#upload_validators' => array(
                        'file_validate_extensions' => array(),
                        'file_validate_size' => array($upload_size * 1024 * 1024),
                    ),
                ),
                'supplemental_file7' => array(
                    '#title' => t('Supplemental File 7'),
                    '#type' => 'managed_file',
                    '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                    '#default_value' => isset($form_state['values']['supplemental_file']) ? $form_state['values']['supplemental_file2'] : NULL,
                    '#upload_location' => 'temporary://',
                    '#upload_validators' => array(
                        'file_validate_extensions' => array(),
                        'file_validate_size' => array($upload_size * 1024 * 1024),
                    ),
                ),
                'supplemental_file8' => array(
                    '#title' => t('Supplemental File 8'),
                    '#type' => 'managed_file',
                    '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                    '#default_value' => isset($form_state['values']['supplemental_file3']) ? $form_state['values']['supplemental_file3'] : NULL,
                    '#upload_location' => 'temporary://',
                    '#upload_validators' => array(
                        'file_validate_extensions' => array(),
                        'file_validate_size' => array($upload_size * 1024 * 1024),
                    ),
                ),
                'supplemental_file9' => array(
                    '#title' => t('Supplemental File 9'),
                    '#type' => 'managed_file',
                    '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                    '#default_value' => isset($form_state['values']['supplemental_file4']) ? $form_state['values']['supplemental_file4'] : NULL,
                    '#upload_location' => 'temporary://',
                    '#upload_validators' => array(
                        'file_validate_extensions' => array(),
                        'file_validate_size' => array($upload_size * 1024 * 1024),
                    ),
                ),
                'supplemental_file10' => array(
                    '#title' => t('Supplemental File 10'),
                    '#type' => 'managed_file',
                    '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                    '#default_value' => isset($form_state['values']['supplemental_file5']) ? $form_state['values']['supplemental_file5'] : NULL,
                    '#upload_location' => 'temporary://',
                    '#upload_validators' => array(
                        'file_validate_extensions' => array(),
                        'file_validate_size' => array($upload_size * 1024 * 1024),
                    ),
                ),
                '#type' => 'item',
                '#states' => array(
                    'visible' => array('#edit-supply-more-supplementals' => array('checked' => TRUE)),
                ),
                'supply_more_supplementals2' => array(
                    '#type' => 'checkbox',
                    '#title' => t('Upload 5 More Supplemental Files'),
                ),
                'supplemental_section' => array(
                    'supplemental_file11' => array(
                        '#title' => t('Supplemental File 11'),
                        '#type' => 'managed_file',
                        '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                        '#default_value' => isset($form_state['values']['supplemental_file6']) ? $form_state['values']['supplemental_file6'] : NULL,
                        '#upload_location' => 'temporary://',
                        '#upload_validators' => array(
                            'file_validate_extensions' => array(),
                            'file_validate_size' => array($upload_size * 1024 * 1024),
                        ),
                    ),
                    'supplemental_file12' => array(
                        '#title' => t('Supplemental File 12'),
                        '#type' => 'managed_file',
                        '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                        '#default_value' => isset($form_state['values']['supplemental_file']) ? $form_state['values']['supplemental_file2'] : NULL,
                        '#upload_location' => 'temporary://',
                        '#upload_validators' => array(
                            'file_validate_extensions' => array(),
                            'file_validate_size' => array($upload_size * 1024 * 1024),
                        ),
                    ),
                    'supplemental_file13' => array(
                        '#title' => t('Supplemental File 13'),
                        '#type' => 'managed_file',
                        '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                        '#default_value' => isset($form_state['values']['supplemental_file3']) ? $form_state['values']['supplemental_file3'] : NULL,
                        '#upload_location' => 'temporary://',
                        '#upload_validators' => array(
                            'file_validate_extensions' => array(),
                            'file_validate_size' => array($upload_size * 1024 * 1024),
                        ),
                    ),
                    'supplemental_file14' => array(
                        '#title' => t('Supplemental File 14'),
                        '#type' => 'managed_file',
                        '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                        '#default_value' => isset($form_state['values']['supplemental_file4']) ? $form_state['values']['supplemental_file4'] : NULL,
                        '#upload_location' => 'temporary://',
                        '#upload_validators' => array(
                            'file_validate_extensions' => array(),
                            'file_validate_size' => array($upload_size * 1024 * 1024),
                        ),
                    ),
                    'supplemental_file15' => array(
                        '#title' => t('Supplemental File 15'),
                        '#type' => 'managed_file',
                        '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                        '#default_value' => isset($form_state['values']['supplemental_file5']) ? $form_state['values']['supplemental_file5'] : NULL,
                        '#upload_location' => 'temporary://',
                        '#upload_validators' => array(
                            'file_validate_extensions' => array(),
                            'file_validate_size' => array($upload_size * 1024 * 1024),
                        ),
                    ),
                    '#type' => 'item',
                    '#states' => array(
                        'visible' => array('#edit-supply-more-supplementals2' => array('checked' => TRUE)),
                    ),
                    'supply_more_supplementals3' => array(
                        '#type' => 'checkbox',
                        '#title' => t('Upload 5 More Supplemental Files'),
                    ),
                    'supplemental_section' => array(
                        'supplemental_file16' => array(
                            '#title' => t('Supplemental File 16'),
                            '#type' => 'managed_file',
                            '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                            '#default_value' => isset($form_state['values']['supplemental_file6']) ? $form_state['values']['supplemental_file6'] : NULL,
                            '#upload_location' => 'temporary://',
                            '#upload_validators' => array(
                                'file_validate_extensions' => array(),
                                'file_validate_size' => array($upload_size * 1024 * 1024),
                            ),
                        ),
                        'supplemental_file17' => array(
                            '#title' => t('Supplemental File 17'),
                            '#type' => 'managed_file',
                            '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                            '#default_value' => isset($form_state['values']['supplemental_file']) ? $form_state['values']['supplemental_file2'] : NULL,
                            '#upload_location' => 'temporary://',
                            '#upload_validators' => array(
                                'file_validate_extensions' => array(),
                                'file_validate_size' => array($upload_size * 1024 * 1024),
                            ),
                        ),
                        'supplemental_file18' => array(
                            '#title' => t('Supplemental File 18'),
                            '#type' => 'managed_file',
                            '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                            '#default_value' => isset($form_state['values']['supplemental_file3']) ? $form_state['values']['supplemental_file3'] : NULL,
                            '#upload_location' => 'temporary://',
                            '#upload_validators' => array(
                                'file_validate_extensions' => array(),
                                'file_validate_size' => array($upload_size * 1024 * 1024),
                            ),
                        ),
                        'supplemental_file19' => array(
                            '#title' => t('Supplemental File 19'),
                            '#type' => 'managed_file',
                            '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                            '#default_value' => isset($form_state['values']['supplemental_file4']) ? $form_state['values']['supplemental_file4'] : NULL,
                            '#upload_location' => 'temporary://',
                            '#upload_validators' => array(
                                'file_validate_extensions' => array(),
                                'file_validate_size' => array($upload_size * 1024 * 1024),
                            ),
                        ),
                        'supplemental_file20' => array(
                            '#title' => t('Supplemental File 20'),
                            '#type' => 'managed_file',
                            '#description' => t('Select a file to upload.<br/>Files must be less than <strong>@size MB.</strong>', array('@size' => $upload_size)),
                            '#default_value' => isset($form_state['values']['supplemental_file5']) ? $form_state['values']['supplemental_file5'] : NULL,
                            '#upload_location' => 'temporary://',
                            '#upload_validators' => array(
                                'file_validate_extensions' => array(),
                                'file_validate_size' => array($upload_size * 1024 * 1024),
                            ),
                        ),
                        '#type' => 'item',
                        '#states' => array(
                            'visible' => array('#edit-supply-more-supplementals3' => array('checked' => TRUE)),
                        ),

                    ),

                ),
            ),
        ),
    );
}

/**
 * Validation for binary object upload form.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 */
function islandora_binary_object_upload_form_validate(array $form, array &$form_state)
{
    if ($form_state['values']['supply_thumbnail'] &&
        !$form_state['values']['thumbnail_file']
    ) {
        form_set_error('thumbnail_file', t('If you select "Upload Thumbnail" please supply a file.'));
    }
}

/**
 * Adds the uploaded file into the ingestable objects 'OBJ' datastream.
 *
 * May also populate the TN datastream.
 *
 * @param array $form
 *   The Drupal form.
 * @param array $form_state
 *   The Drupal form state.
 */
function islandora_binary_object_upload_form_submit(array $form, array &$form_state)
{
    module_load_include('inc', 'islandora', 'includes/utilities');
    $object = islandora_ingest_form_get_object($form_state);

    if (!isset($object['OBJ'])) {
        $datastream = $object->constructDatastream('OBJ', 'M');
    } else {
        $datastream = $object['OBJ'];
    }
    $file = file_load($form_state['values']['file']);
    $datastream->setContentFromFile($file->uri, FALSE);
    if ($datastream->label != $file->filename) {
        $datastream->label = $file->filename;
    }
    if ($datastream->mimetype != $file->filemime) {
        $datastream->mimetype = $file->filemime;
    }

    if (!isset($object['OBJ'])) {
        $object->ingestDatastream($datastream);
    }

    if ($form_state['values']['supply_thumbnail']) {
        $thumbnail_file = file_load($form_state['values']['thumbnail_file']);
        if ($form_state['values']['scale_thumbnail']) {
            islandora_scale_thumbnail($thumbnail_file, 200, 200);
        }

        if (empty($object['TN'])) {
            $tn = $object->constructDatastream('TN', 'M');
            $object->ingestDatastream($tn);
        } else {
            $tn = $object['TN'];
        }
        $tn->setContentFromFile($thumbnail_file->uri, FALSE);
        if ($tn->label != $thumbnail_file->filename) {
            $tn->label = $thumbnail_file->filename;
        }
        if ($tn->mimetype != $thumbnail_file->filemime) {
            $tn->mimetype = $thumbnail_file->filemime;
        }
    }
    if ($form_state['values']['supply_supplemental']) {
        $supplemental_file = file_load($form_state['values']['supplemental_file']);
        $supplemental_file2 = file_load($form_state['values']['supplemental_file2']);
        if (empty($object['SUPPLEMENT'])) {
            $supplement = $object->constructDatastream('SUPPLEMENT', 'M');
            $object->ingestDatastream($supplement);
        } else {
            $supplement = $object['SUPPLEMENT'];
        }
        $supplement->setContentFromFile($supplemental_file->uri, FALSE);
        if ($supplement->label != $supplemental_file->filename) {
            $supplement->label = $supplemental_file->filename;
        }
        if ($supplement->mimetype != $supplemental_file->filemime) {
            $supplement->mimetype = $supplemental_file->filemime;
        }
        if (empty($object['SUPPLEMENT2'])) {
            $supplement = $object->constructDatastream('SUPPLEMENT2', 'M');
            $object->ingestDatastream($supplement);
        } else {
            $supplement = $object['SUPPLEMENT2'];
        }
        $supplement->setContentFromFile($supplemental_file2->uri, FALSE);
        if ($supplement->label != $supplemental_file2->filename) {
            $supplement->label = $supplemental_file2->filename;
        }
        if ($supplement->mimetype != $supplemental_file2->filemime) {
            $supplement->mimetype = $supplemental_file2->filemime;
        }
    }
}
