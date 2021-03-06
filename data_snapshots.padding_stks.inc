<?php

/**
 * The code in general assumes that every STK array will have the same rough count
 * of values (ie 12 for Monthly & 52 or 53 for weekly). These functions determine
 * where there are missing values and adds in placeholder values where appropriate.
 */
function _data_snapshots_pad_snapshots($dsmn, $ptks, &$stks) {
  $PAD_VALUE = NULL;
  $frequency = _data_snapshots_get_data_source_frequency($dsmn);
  $callback = '_data_snapshots_pad_' . $frequency;
  $callback($ptks, $stks, $PAD_VALUE);
}

function _data_snapshots_pad_Custom($ptks, &$stks, $PAD_VALUE) {
  $expected_length = 0;
  for ($i = 0; $i < count($ptks); $i++) {
    $test_length = count($stks[$ptks[$i]]);
    if ($test_length > $expected_length) {
      $expected_length = $test_length;
    }
  }

  for ($i = 0; $i < count($ptks); $i++) {
    $ptk = $ptks[$i];

    while (count($stks[$ptk]) < $expected_length) {
      array_push($stks[$ptk], $PAD_VALUE);
    }
  }
}

function _data_snapshots_pad_Monthly($ptks, &$stks, $PAD_VALUE) {
  $MONTH_LENGTH = 12;
  $EXPECTED_MONTH_VALUES = array('01-00', '02-00', '03-00', '04-00', '05-00', '06-00', '07-00', '08-00', '09-00', '10-00', '11-00', '12-00');

  for ($i = 0; $i < count($ptks); $i++) {
    if (count($stks[$ptks[$i]]) == $MONTH_LENGTH) {
      continue;
    }

    // pad the front
    $front_value = $stks[$ptks[$i]][0];
    if ($front_value != $EXPECTED_MONTH_VALUES[0]) {
      $front_value_index = 0;
      for ($j = 1; $j < count($EXPECTED_MONTH_VALUES); $j++) {
        if ($EXPECTED_MONTH_VALUES[$j] == $front_value) {
          $front_value_index = $j;
          break;
        }
      }

      for ($j = 0; $j < $front_value_index; $j++) {
        array_unshift($stks[$ptks[$i]], $PAD_VALUE);
      }
    }

    if (count($stks[$ptks[$i]]) == $MONTH_LENGTH) {
      continue;
    }

    //pad the back
    while (count($stks[$ptks[$i]]) != $MONTH_LENGTH) {
      array_push($stks[$ptks[$i]], $PAD_VALUE);
    }
  }
}

function _data_snapshots_pad_Weekly($ptks, &$stks, $PAD_VALUE) {
  $DATE_INTERVAL = date_interval_create_from_date_string('7 days');
  for ($i = 0; $i < count($ptks); $i++) {
    $ptk = $ptks[$i];

    // pad the front
    $base_date = date_create($ptk . '-' . $stks[$ptk][0]);
    $test_date = date_sub($base_date, $DATE_INTERVAL);
    if (date_format($test_date, 'Y') == $ptk) {
      while (TRUE) {
        array_unshift($stks[$ptk], $PAD_VALUE);
        $test_date = date_sub($test_date, $DATE_INTERVAL);
        if (date_format($test_date, 'Y') != $ptk) {
          break;
        }
      }
    }

    //pad the back
    $base_date = date_create($ptk . '-' . $stks[$ptk][count($stks[$ptk]) - 1]);
    $test_date = date_add($base_date, $DATE_INTERVAL);
    if (date_format($test_date, 'Y') == $ptk) {
      while (TRUE) {
        array_push($stks[$ptk], $PAD_VALUE);
        $test_date = date_add($test_date, $DATE_INTERVAL);
        if (date_format($test_date, 'Y') != $ptk) {
          break;
        }
      }
    }
  }
}

function _data_snapshots_pad_Bimonthly($ptks, &$stks, $PAD_VALUE) {
  $MONTHS = array('01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12');
  $EXPECTED_SNAPSHOTS = 2;
  for ($i = 0; $i < count($ptks); $i++) {
    $ptk = $ptks[$i];

    // pad the front
    $base_date = date_create($ptk . '-' . $stks[$ptk][0]);
    $offset = array_search(date_format($base_date, 'm'), $MONTHS) * $EXPECTED_SNAPSHOTS;
    if (!(count($stks[$ptk]) > 1) || date_format(date_create($ptk . '-' . $stks[$ptk][0]), 'm') != date_format(date_create($ptk . '-' . $stks[$ptk][1]), 'm')) {
      $offset--;
    }
    for (; $offset > 0; $offset--) {
        array_unshift($stks[$ptk], $PAD_VALUE);
    }

    //pad the back
    $count = count($stks[$ptk]);
    $base_date = date_create($ptk . '-' . $stks[$ptk][$count - 1]);
    $offset = (count($MONTHS) - array_search(date_format($base_date, 'm'), $MONTHS) - 1) * $EXPECTED_SNAPSHOTS;
    if (count($stks[$ptk]) > 1 && date_format(date_create($ptk . '-' . $stks[$ptk][$count - 1]), 'm') != date_format(date_create($ptk . '-' . $stks[$ptk][$count - 2]), 'm')) {
      $offset--;
    }
    for (; $offset > 0; $offset--) {
        $stks[$ptk][] = $PAD_VALUE;
    }
  }
}

function _data_snapshots_pad_Annual($ptks, &$stks, $PAD_VALUE) {
  // nothing needs to happen here. There will never be stks.
  // This function was just created to avoid the need for additional logic
}
