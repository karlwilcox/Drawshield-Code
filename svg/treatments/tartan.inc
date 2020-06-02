<?php

$tartanPattern = [];

foreach ($children as $child) {
    if ($child->nodeName == 'colour') {
        $hex = rgb($child->getAttribute('keyterm'));
        $mod = $child->firstChild;
        $size = $mod->getAttribute('value');
        $tartanPattern[] = array($hex, $size);
    }
}

$threadScale = 2;
// calculate the repeated area size

$numThreads = count($tartanPattern);
if (!$numThreads) { // something wrong, no colours
    $tartanPattern = [
        ['#0f0f0f', 25],
        ['#f0f0f0', 25],
    ];
    $numThreads = 2;
    $messages->addMessage('parser',"Tartan requires colours and thread counts");
}

$repeatCount = 0;
for ($k = 0; $k < $numThreads; $k++) {
    $repeatCount += $tartanPattern[$k][1] * $threadScale;
}
if ($reverse)  $repeatCount *= 2;

$svg = "<g>\n";

$y = 0;
for ($k = 0; $k < $numThreads; $k++) {
    $x = 0;
    $ySize = $tartanPattern[$k][1] * $threadScale;
    for ($j = 0; $j < $numThreads; $j++ ) {
        $xSize = $tartanPattern[$j][1] * $threadScale;
        $svg .= "<rect x=\"$x\" y=\"$y\" width=\"$xSize\" height=\"$ySize\" fill=\"" . mixRGB($tartanPattern[$k][0], $tartanPattern[$j][0]) . "\" />\n";
        $x += $xSize;
    }
    // $y += $ySize;
    if ($reverse) {
        for ($j = $numThreads - 1; $j >= 0; $j--) {
            $xSize = $tartanPattern[$j][1] * $threadScale;
            $svg .= "<rect x=\"$x\" y=\"$y\" width=\"$xSize\" height=\"$ySize\" fill=\"" . mixRGB($tartanPattern[$k][0], $tartanPattern[$j][0]) . "\" />\n";
            $x += $xSize;
        }
    }
    $y += $ySize;
}
if ($reverse) {
    for ($k = $numThreads - 1; $k >= 0 ; $k--) {
        $x = 0;
        $ySize = $tartanPattern[$k][1] * $threadScale;
        for ($j = 0; $j < $numThreads; $j++ ) {
            $xSize = $tartanPattern[$j][1] * $threadScale;
            $svg .= "<rect x=\"$x\" y=\"$y\" width=\"$xSize\" height=\"$ySize\" fill=\"" . mixRGB($tartanPattern[$k][0], $tartanPattern[$j][0]) . "\" />\n";
            $x += $xSize;
        }
        // $y += $ySize;
        if ($reverse) {
            for ($j = $numThreads - 1; $j >= 0; $j--) {
                $xSize = $tartanPattern[$j][1] * $threadScale;
                $svg .= "<rect x=\"$x\" y=\"$y\" width=\"$xSize\" height=\"$ySize\" fill=\"" . mixRGB($tartanPattern[$k][0], $tartanPattern[$j][0]) . "\" />\n";
                $x += $xSize;
            }
        }
        $y += $ySize;
    }
}
$svg .= "</g>\n";

$treatment_data['height'] = $repeatCount;
$treatment_data['width'] = $repeatCount;
$treatment_data['pattern'] = $svg;
