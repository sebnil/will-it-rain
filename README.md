will-it-rain
============

Use SparkCore to light up a LED if you should bring an umbrella today. 

# How it works
The SparkCore is polling a php script to see if it will rain the next couple of hours. 
The php script uses a weather API from yr.no

# How to use
1. Put index.php on a web server with php5 with support for SimpleXml and Curl. Modify the code to get the right weather forecast.
2. Upload will-it-rain.cpp to your sparkcore. Modify the code to make sure it points to your weather service.
