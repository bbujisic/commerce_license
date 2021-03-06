<?php

/**
 * @file
 * Provides Views integration.
 */

class CommerceLicenseViewsController extends EntityDefaultViewsController {

  /**
   * Overrides EntityDefaultViewsController::views_data().
   */
  public function views_data() {
    $data = parent::views_data();
    $data['commerce_license']['access_details'] = array(
      'title' => t('Access details'),
      'help' => t('The access details of an activated license.'),
      'field' => array(
        'handler' => 'commerce_license_handler_field_access_details',
        'click sortable' => FALSE,
        'type' => 'commerce_license',
        'real field' => 'entity object',
      ),
    );

    // Make the log handler match the one in Commerce Order.
    $data['commerce_license_revision']['log']['field']['handler'] = 'views_handler_field_xss';
    unset($data['commerce_license_revision']['log']['argument']);
    unset($data['commerce_license_revision']['log']['sort']);

    return $data;
  }
}
