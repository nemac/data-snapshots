<?php

/**
 * Implements hook_field_group_info().
 */
function data_snapshots_field_group_info() {

  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_climategov_metadata|node|data_snapshot|form';
  $field_group->group_name = 'group_climategov_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dss_tabs';
  $field_group->data = array(
    'label' => 'Climate.gov Metadata',
    'weight' => '3',
    'children' => array(
      0 => 'path',
      1 => 'redirect',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_climategov_metadata|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasnapshot_edit_info|node|data_snapshot|form';
  $field_group->group_name = 'group_datasnapshot_edit_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dss_tabs';
  $field_group->data = array(
    'label' => 'Editable Information',
    'weight' => '1',
    'children' => array(
      0 => 'title',
      1 => 'body',
      2 => 'field_ds_relnds',
      3 => 'field_ds_dloads',
      4 => 'field_ds_disimg',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_datasnapshot_edit_info|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datasnapshot_image_meta|node|data_snapshot|form';
  $field_group->group_name = 'group_datasnapshot_image_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dss_tabs';
  $field_group->data = array(
    'label' => 'Image Metadata',
    'weight' => '2',
    'children' => array(
      0 => 'field_ds_ptk',
      1 => 'field_ds_stk',
      2 => 'field_ds_dtgen',
      3 => 'field_ds_dsds_mn',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_datasnapshot_image_meta|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dss_tabs|node|data_snapshot|form';
  $field_group->group_name = 'group_dss_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data Snapshot Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_climategov_metadata',
      1 => 'group_datasnapshot_image_meta',
      2 => 'group_datasnapshot_edit_info',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dss_tabs|node|data_snapshot|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dss_share|node|data_snapshot|full';
  $field_group->group_name = 'group_dss_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sharing',
    'weight' => '20',
    'children' => array(
      0 => 'add_this',
      1 => 'data_snapshot_permalink',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Share',
      'instance_settings' => array(
        'classes' => 'group-dss-share field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_share|node|data_snapshot|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dss_sliders|node|data_snapshot|full';
  $field_group->group_name = 'group_dss_sliders';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sliders',
    'weight' => '5',
    'children' => array(
      0 => 'field_ds_stk',
      1 => 'field_ds_ptk',
      2 => 'field_ds_dloads',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'group-dss-sliders field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sliders|node|data_snapshot|full'] = $field_group;

  //
  // Data Source Groups
  //

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_source_content|node|data_snapshot_data_source|full';
  $field_group->group_name = 'group_data_source_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'data source content',
    'weight' => '3',
    'children' => array(
      0 => 'field_dssds_colors',
      1 => 'field_dssds_data_format',
      2 => 'field_dssds_data_matter',
      3 => 'field_dssds_additional_info',
      4 => 'field_dssds_framing_q_answer',
      5 => 'field_dssds_framing_question',
      6 => 'field_dssds_processing_steps',
      7 => 'field_dssds_references',
      8 => 'field_dssds_secondary_q_answ',
      9 => 'field_dssds_secondary_questi',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'data source content',
      'instance_settings' => array(
        'classes' => 'group-data-source-content field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_source_content|node|data_snapshot_data_source|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_source_metadata|node|data_snapshot_data_source|full';
  $field_group->group_name = 'group_data_source_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'data source metadata',
    'weight' => '2',
    'children' => array(
      0 => 'field_dssds_catalog_url',
      1 => 'field_dssds_data_access_url',
      2 => 'field_dssds_data_provider',
      3 => 'field_dssds_data_product',
      4 => 'field_dssds_reviewer',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'data source metadata',
      'instance_settings' => array(
        'classes' => 'group-data-source-metadata field-group-div full-image-sidebar',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_source_metadata|node|data_snapshot_data_source|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ds_representative_image|node|data_snapshot_data_source|full';
  $field_group->group_name = 'group_ds_representative_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'data source representative image',
    'weight' => '1',
    'children' => array(
      0 => 'field_dssds_representative_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'data source representative image',
      'instance_settings' => array(
        'classes' => 'group-ds-representative-image field-group-div full-image',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ds_representative_image|node|data_snapshot_data_source|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dssds_metadata|node|data_snapshot_data_source|form';
  $field_group->group_name = 'group_dssds_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dssds_tabs';
  $field_group->data = array(
    'label' => 'Data Source Metadata',
    'weight' => '1',
    'children' => array(
      0 => 'field_dssds_catalog_url',
      1 => 'field_dssds_image_frequency',
      2 => 'field_dssds_data_product',
      3 => 'field_dssds_themes',
      4 => 'field_dssds_url_pattern',
      5 => 'field_weight',
      6 => 'field_dssds_map_scope',
      7 => 'title',
      8 => 'field_dssds_representative_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dssds_metadata|node|data_snapshot_data_source|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dssds_people|node|data_snapshot_data_source|form';
  $field_group->group_name = 'group_dssds_people';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dssds_tabs';
  $field_group->data = array(
    'label' => 'People Involved',
    'weight' => '6',
    'children' => array(
      0 => 'field_dssds_description_auth',
      1 => 'field_dssds_reviewer',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dssds_people|node|data_snapshot_data_source|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dssds_processing|node|data_snapshot_data_source|form';
  $field_group->group_name = 'group_dssds_processing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dssds_tabs';
  $field_group->data = array(
    'label' => 'Processing Environment',
    'weight' => '3',
    'children' => array(
      0 => 'field_dssds_processing_steps',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dssds_processing|node|data_snapshot_data_source|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dssds_provider|node|data_snapshot_data_source|form';
  $field_group->group_name = 'group_dssds_provider';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dssds_tabs';
  $field_group->data = array(
    'label' => 'Data Provider',
    'weight' => '4',
    'children' => array(
      0 => 'field_dssds_data_access_url',
      1 => 'field_dssds_data_format',
      2 => 'field_dssds_data_provider',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dssds_provider|node|data_snapshot_data_source|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dssds_tabs|node|data_snapshot_data_source|form';
  $field_group->group_name = 'group_dssds_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_dssds_metadata',
      1 => 'group_dssds_people',
      2 => 'group_dssds_processing',
      3 => 'group_dssds_provider',
      4 => 'group_dssds_text',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dssds_tabs|node|data_snapshot_data_source|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dssds_text|node|data_snapshot_data_source|form';
  $field_group->group_name = 'group_dssds_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'data_snapshot_data_source';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dssds_tabs';
  $field_group->data = array(
    'label' => 'Editable Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_dssds_colors',
      1 => 'field_dssds_data_matter',
      2 => 'field_dssds_additional_info',
      3 => 'field_dssds_framing_q_answer',
      4 => 'field_dssds_framing_question',
      5 => 'field_dssds_references',
      6 => 'field_dssds_secondary_q_answ',
      7 => 'field_dssds_secondary_questi',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dssds_text|node|data_snapshot_data_source|form'] = $field_group;

  return $export;
}
