## Should I bring an umbrella?
http://sebastiannilsson.com/en/blogg/will-it-rain/

Living in Göteborg, Sweden means that many mornings you ask yourself the question "do I need an umbrella today?". To outsource more small decisions to computers I programmed a microprocessor that respond with activating a led if an umbrella is recommended.

![Spark Core as Umbrella reminder](http://sebastiannilsson.com/wp-content/uploads/2014/01/2014-01-06-11.11.08-300x224.jpg)

The idea is very simple. The microprocessor reads the weather forecast from yr.no for the next 10 hours (which is about the time I expect to be away from home). If any of these hours include rain (more than a few mm) then light the led. Unlit led obviously means no rain.

### How it works

#### Hardware
Spark Core
Breadboard
Light Emitting Diode
Resistor
Usb cable for power supply

#### Weather forecast with php and yr.no

I run a php script which gets the next forecast from yr.no. It is published at http://sebastiannilsson.com/will-it-rain/and is relatively easy to use.

Find the city that you want the forecast for and copy the URL. For example, in Gothenburg is the http://www.yr.no/sted/Sverige/Västmanland/Kolbäck/or Kolbäck http://www.yr.no/sted/Sweden/the stra_GÃ ¶ taland/Gothenburg/
Go to http://sebastiannilsson.com/will-it-rain/index.php?debug = 1&threshold = 0.1&yr_url =<URL HERE>
Example: Forecast for Gothenburg with a threshold for rain in 0.5 mm looks like this:
http://sebastiannilsson.com/will-it-rain/index.php?debug=1&threshold=0.5&yr_url=http://www.yr.no/sted/Sverige/V%C3%A4stra_G%C3%B6taland/G%C3%B6teborg/

#### Code on the microprocessor

Spark Core is a microprocessor that connects to Wifi. You upload your code to it over their cloud service.

Get a Spark Core or similar and connect it to wifi.
Copy my code for the Spark Core. The only needed change is the variable for the url.
Upload
