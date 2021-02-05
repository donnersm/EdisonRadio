// about.html file in raw data format for PROGMEM
//
#define about_html_version 170626
const char about_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
 <head>
  <title>About EDISON Radio</title>
  <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
  <link rel="Shortcut Icon" type="image/ico" href="favicon.ico">
  <link rel="stylesheet" type="text/css" href="radio.css">
 </head>
 <body>
  <ul>
   <li><a class="pull-left" href="#">EDISON Radio</a></li>
   <li><a class="pull-left" href="/index.html">Control</a></li>
   <li><a class="pull-left" href="/config.html">Config</a></li>
   <li><a class="pull-left" href="/mp3play.html">MP3 player</a></li>
   <li><a class="pull-left active" href="/about.html">About</a></li>
      <li><a class="pull-left" href="/find.html">Find</a></li>
  </ul>
  <br><br><br>
  <center>
   <h1>** EDISON Radio **</h1>
 
	
	
	<p>EDISON Radio -- Webradio receiver for ESP32, 1.8" color display and VS1053 MP3 module.<br>
	This project is documented at my website<a target="blank" href="www.theelectronicengineer.nl">The Electronic Engineer</a>.</p>
	<p>Original Author: Ed Smallenburg (ed@smallenburg.nl)<br>
	Webinterface design: <a target="blank" href="http://www.sanderjochems.nl/">Sander Jochems</a><br>
	App (Android): <a target="blank" href="https://play.google.com/store/apps/details?id=com.thunkable.android.sander542jochems.ESP_Radio">Sander Jochems</a><br>
	Date: June 2017</p>
 <p> Firmware and webinterface modified by Mark Donners</p>
  </center>
  
 </body>
</html>
)=====" ;
