# Should I bring an umbrella?
http://sebastiannilsson.com/en/blogg/will-it-rain/

Living in Göteborg, Sweden means that many mornings you ask yourself the question "do I need an umbrella today?". To outsource more small decisions to computers I programmed a microprocessor that respond with activating a led if an umbrella is recommended.

![Spark Core as Umbrella reminder](http://sebastiannilsson.com/wp-content/uploads/2014/01/2014-01-06-11.11.08-300x224.jpg)

The idea is very simple. The microprocessor reads the weather forecast from yr.no for the next 10 hours (which is about the time I expect to be away from home). If any of these hours include rain (more than a few mm) then light the led. Unlit led obviously means no rain.

## How it works
### Hardware
Spark Core
Breadboard
Light Emitting Diode
Resistor
Usb cable for power supply

### Server: Weather forecast with php and yr.no
  1. I run a php script which gets the next forecast from yr.no. It is published at http://sebastiannilsson.com/will-it-rain/and is relatively easy to use.
  2. Find the city that you want the forecast for and copy the URL. 
      - For example, in Gothenburg it is http://www.yr.no/sted/Sverige/V%C3%A4stra_G%C3%B6taland/G%C3%B6teborg/
      - Kolbäck is http://www.yr.no/sted/Sverige/V%C3%A4stmanland/Kolb%C3%A4ck/
  3. Go to https://sebastiannilsson.com/will-it-rain/index.php?debug=1&threshold=0.2&yr_url=<URL HERE>
      - For example: Forecast for Gothenburg with a threshold for rain in 0.5 mm looks like this:
https://sebastiannilsson.com/will-it-rain/index.php?debug=1&threshold=0.5&yr_url=http://www.yr.no/sted/Sverige/V%C3%A4stra_G%C3%B6taland/G%C3%B6teborg/

### Client: Code running on the microprocessor

  1. Spark Core is a microprocessor that connects to Wifi. You upload your code to it over their cloud service.
  2. Get a Spark Core or similar and connect it to wifi.
  3. Copy my code for the Spark Core. The only needed change is the variable for the url.
  4. Upload

 
## Support my creation of open source software:
[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=sebnil&url=https://github.com/sebnil/will-it-rain)

<a href='https://ko-fi.com/A0A2HYRH' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi2.png?v=0' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>