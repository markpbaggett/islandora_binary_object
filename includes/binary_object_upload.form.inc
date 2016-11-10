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
                    '#default_value' => isset($form_state['values']['supplemental_file7']) ? $form_state['values']['supplemental_file7'] : NULL,
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
                    '#default_value' => isset($form_state['values']['supplemental_file8']) ? $form_state['values']['supplemental_file8'] : NULL,
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
                    '#default_value' => isset($form_state['values']['supplemental_file9']) ? $form_state['values']['supplemental_file9'] : NULL,
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
                    '#default_value' => isset($form_state['values']['supplemental_file10']) ? $form_state['values']['supplemental_file10'] : NULL,
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
                        '#default_value' => isset($form_state['values']['supplemental_file11']) ? $form_state['values']['supplemental_file11'] : NULL,
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
                        '#default_value' => isset($form_state['values']['supplemental_file12']) ? $form_state['values']['supplemental_file12'] : NULL,
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
                        '#default_value' => isset($form_state['values']['supplemental_file13']) ? $form_state['values']['supplemental_file13'] : NULL,
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
                        '#default_value' => isset($form_state['values']['supplemental_file14']) ? $form_state['values']['supplemental_file14'] : NULL,
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
                        '#default_value' => isset($form_state['values']['supplemental_file15']) ? $form_state['values']['supplemental_file15'] : NULL,
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
                            '#default_value' => isset($form_state['values']['supplemental_file16']) ? $form_state['values']['supplemental_file16'] : NULL,
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
                            '#default_value' => isset($form_state['values']['supplemental_file17']) ? $form_state['values']['supplemental_file17'] : NULL,
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
                            '#default_value' => isset($form_state['values']['supplemental_file18']) ? $form_state['values']['supplemental_file18'] : NULL,
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
                            '#default_value' => isset($form_state['values']['supplemental_file19']) ? $form_state['values']['supplemental_file19'] : NULL,
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
                            '#default_value' => isset($form_state['values']['supplemental_file20']) ? $form_state['values']['supplemental_file20'] : NULL,
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
                        'supply_more_supplementals4' => array(
                            '#title' => t('Upload More Supplemental Files'),
                            '#markup' => t('<p>Need to upload more files? Contact the <a href="mailto:">Trace Administrator</a>.'),
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
        if ($form_state['values']['supplemental_file']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file']);
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
        }
        if ($form_state['values']['supplemental_file2']) {
            $supplemental_file2 = file_load($form_state['values']['supplemental_file2']);
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
        if ($form_state['values']['supplemental_file3']) {
            $supplemental_file3 = file_load($form_state['values']['supplemental_file3']);
            if (empty($object['SUPPLEMENT3'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT3', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT3'];
            }
            $supplement->setContentFromFile($supplemental_file3->uri, FALSE);
            if ($supplement->label != $supplemental_file3->filename) {
                $supplement->label = $supplemental_file3->filename;
            }
            if ($supplement->mimetype != $supplemental_file3->filemime) {
                $supplement->mimetype = $supplemental_file3->filemime;
            }
        }
        if ($form_state['values']['supplemental_file4']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file4']);
            if (empty($object['SUPPLEMENT4'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT4', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT4'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file5']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file5']);
            if (empty($object['SUPPLEMENT5'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT5', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT5'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
    }
    if ($form_state['values']['supply_more_supplementals']) {
        if ($form_state['values']['supplemental_file6']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file6']);
            if (empty($object['SUPPLEMENT6'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT6', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT6'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file7']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file7']);
            if (empty($object['SUPPLEMENT7'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT7', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT7'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file2->filemime) {
                $supplement->mimetype = $supplemental_file2->filemime;
            }
        }
        if ($form_state['values']['supplemental_file8']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file8']);
            if (empty($object['SUPPLEMENT8'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT8', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT8'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file9']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file9']);
            if (empty($object['SUPPLEMENT9'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT9', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT4'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file10']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file10']);
            if (empty($object['SUPPLEMENT10'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT10', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT5'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
    }
    if ($form_state['values']['supply_more_supplementals2']) {
        if ($form_state['values']['supplemental_file11']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file11']);
            if (empty($object['SUPPLEMENT11'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT11', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT11'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file12']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file12']);
            if (empty($object['SUPPLEMENT12'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT12', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT12'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file13']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file13']);
            if (empty($object['SUPPLEMENT13'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT13', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT13'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file14']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file14']);
            if (empty($object['SUPPLEMENT14'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT14', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT14'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file15']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file15']);
            if (empty($object['SUPPLEMENT15'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT15', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT15'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
    }
    if ($form_state['values']['supply_more_supplementals3']) {
        if ($form_state['values']['supplemental_file16']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file16']);
            if (empty($object['SUPPLEMENT16'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT16', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT16'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file17']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file17']);
            if (empty($object['SUPPLEMENT17'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT17', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT17'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file18']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file18']);
            if (empty($object['SUPPLEMENT18'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT18', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT18'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file19']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file19']);
            if (empty($object['SUPPLEMENT19'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT19', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT19'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
        if ($form_state['values']['supplemental_file20']) {
            $supplemental_file = file_load($form_state['values']['supplemental_file20']);
            if (empty($object['SUPPLEMENT20'])) {
                $supplement = $object->constructDatastream('SUPPLEMENT20', 'M');
                $object->ingestDatastream($supplement);
            } else {
                $supplement = $object['SUPPLEMENT20'];
            }
            $supplement->setContentFromFile($supplemental_file->uri, FALSE);
            if ($supplement->label != $supplemental_file->filename) {
                $supplement->label = $supplemental_file->filename;
            }
            if ($supplement->mimetype != $supplemental_file->filemime) {
                $supplement->mimetype = $supplemental_file->filemime;
            }
        }
    }
}
