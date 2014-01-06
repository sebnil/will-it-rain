<?php
ini_set('error_reporting', 'E_ALL');
ini_set('display_errors', 'On');

$url = "http://www.yr.no/sted/Sverige/V%C3%A4stra_G%C3%B6taland/G%C3%B6teborg/varsel_time_for_time.xml";

$forecastXml = new SimpleXMLElement(curl_download($url));
$times = $forecastXml->forecast->tabular;
//print_r($forecastXml);

$rain = false;
for ($i = 0; $i<10; $i++) {
    //print_r($forecastXml->forecast->tabular->time[$i]->precipitation->attributes()->value);   
    if ((float)$forecastXml->forecast->tabular->time[$i]->precipitation->attributes()->value > 0) {
        // gonna rain
        $rain = true;
        break;
    }
}
echo "rain: ";
echo $rain?1:0;



function curl_download($Url){
 
    // is cURL installed yet?
    if (!function_exists('curl_init')){
        die('Sorry cURL is not installed!');
    }
 
    // OK cool - then let's create a new cURL resource handle
    $ch = curl_init();
 
    // Now set some options (most are optional)
 
    // Set URL to download
    curl_setopt($ch, CURLOPT_URL, $Url);
 
    // Set a referer
    //curl_setopt($ch, CURLOPT_REFERER, "http://www.example.org/yay.htm");
 
    // User agent
    curl_setopt($ch, CURLOPT_USERAGENT, "MozillaXYZ/1.0");
 
    // Include header in result? (0 = yes, 1 = no)
    curl_setopt($ch, CURLOPT_HEADER, 0);
 
    // Should cURL return or print out the data? (true = return, false = print)
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
 
    // Timeout in seconds
    curl_setopt($ch, CURLOPT_TIMEOUT, 10);
 
    // Download the given URL, and return output
    $output = curl_exec($ch);
 
    // Close the cURL resource, and free system resources
    curl_close($ch);
 
    return $output;
}