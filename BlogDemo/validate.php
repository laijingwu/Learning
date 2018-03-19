<?php

$num = validateImage("Flag=1521263757389.gif");
var_dump($num);

function validateImage($image)
{
	$res = imagecreatefromgif($image);
	// $res = imagecreatefromstring($image); // imagecreatefromgif
	$size = getimagesize($image);
	// $size = getimagesizefromstring($image); // getimagesize
	$data = [];

	for($i = 0; $i < $size[1]; $i++) {
		for($j = 0; $j < $size[0]; $j++) {
			$rgb = imagecolorat($res, $j, $i);
			$rgbarray = imagecolorsforindex($res, $rgb);

			$data[$i][$j] = 1;
			if ($rgbarray['red'] <= 51)
                $data[$i][$j] = 0;
            if (($rgbarray['red'] <= 153 || $rgbarray['blue'] <= 153) && ($rgbarray['green'] == 128 || $rgbarray['green'] == 170) )
                $data[$i][$j] = 0;
            if ($rgbarray['red'] == 255 || $rgbarray['green'] == 255 || $rgbarray['blue'] == 255)
                $data[$i][$j] = 1;
		}
	}

	$number_string = null;
	$number_data = [];

	$start = 3;
	$padd = 8;
	for ($o = 0; $o < 4; $o++) {
		$end = $start + $padd;
		for ($i = 0; $i < $size[1]; $i++) {
			$tmp = null;
			for ($j = $start; $j < $end; $j++)
				$tmp .= $data[$i][$j];
			$number_data[$o][$i] = $tmp;
		}
		earseZero($number_data[$o]);
		$number_string .= compareDigit(implode("", $number_data[$o]));

		$start += $padd + 5;
	}
	return $number_string;
}

function disp($array) {
	for ($i = 0; $i < count($array); $i++) {
		echo $array[$i];
		echo "\n";
	}
	echo "\n\n";
}

function compareDigit($numString)
{
	$keys = [
		'1' => '0111100000011000000110000001100000011000000110000001100000011000000110000001100001111110',
		'2' => '0011110001111110110011100000111000001110000011000001100000110000001100000111111011111110',
		'3' => '0011110001111110110011100000111000001100001111000000111000000110000001101110010011111000',
		'4' => '0000011000001110000111100001111000111110011011101100111011111111111111110000111000001110',
		'5' => '0011111000111110010000000111100000111100000011100000011000000010000000111110011001111100',
		'6' => '0000111100011100001100000111000001111100011101101111011011100110111101100111011000111100',
		'7' => '01111110011111100000011000000110000001100000110000001000000010000000100000011000',
		'8' => '0011110001100110011001100111011001111100001111000011111001100110110001101110011100111100',
		'9' => '0011110001110110011001101110011111100111011001100011111000001110000011100011110011100000'
	];

	$max = 0.000;
	$num = 0;
	foreach($keys as $key => $value) {
		$percent = 0.000;
		similar_text($value, $numString, $percent);
		if($percent >= $max) {
			$max = $percent;
			$num = $key;
		}
	}
	return $num;
}

function earseZero(&$array)
{
	for ($i = 0; $i < count($array); $i++) {
		if ($array[$i] == str_repeat("0", count($array[$i]))) {
			array_shift($array);
			$i--;
		} else {
			break;
		}
	}

	for ($i = count($array) - 1; $i >= 0; $i--) {
		if ($array[$i] == str_repeat("0", count($array[$i])))
			array_pop($array);
		else 
			break;
	}
}