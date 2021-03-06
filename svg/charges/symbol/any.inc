<?php
/**
 * Drawshield PHP Source File
 *
 * Description...
 *
 * @author Karl R. Wilcox <karl@karlwilcox.com>
 * @copyright Karl R. Wilcox 2014
 * @license http://www.apache.org/licenses/LICENSE-2.0
 * Date: 11/09/14
 * Time: 23:00
 */

$item = strtolower(getModifierValueByKeyterm($node,'value'));
if ( $item == 'sulfur' ) {
  $charge['file'] = '../alchemical/sulphur.svg';
} elseif ( file_exists( $folder . '../alchemical/' . $item . '.svg')) {
  $charge['file'] = "../alchemical/$item.svg";
} elseif ( file_exists( $folder . '../astronomical/' . $item . '.svg')) {
  $charge['file'] = "../astronomical/$item.svg";
} elseif ( file_exists( $folder . '../zodiac/' . $item . '.svg')) {
  $charge['file'] = "../zodiac/$item.svg";
} else {
  $charge['file'] = "../alchemical/fire.svg";
  $messages->addMessage('warning',"No symbol for $item (using fire)");
}

