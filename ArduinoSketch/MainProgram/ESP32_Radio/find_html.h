#include <Ethernet.h>

// config.html file in raw data format for PROGMEM
//
const char find_html[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html>
<head>
    <title>EDISON Radio</title>
    

  <title>EDISON Radio</title>
  <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
  <link rel="stylesheet" type="text/css" href="radio.css">
  <link rel="Shortcut Icon" type="image/ico" href="favicon.ico">


    <style type="text/css">           /* optimized with csstidy */
        html {  /* This is the groundplane */
            font-family : serif;
            height : 100%;
            font-size: 16px;
            color : DarkSlateGray;
            background-color : navy;
            margin : 0;
            padding : 0;
        }

        #preloaded-images{
            display: none;
        }
        #dialog {
            display: none;
        }
        #content {
            min-height : 540px;
            min-width : 725px;
            overflow : hidden;
            background-color : lightskyblue;
            margin : 0;
            padding : 5px;
        }
        #tab-content1 {
            font-size: 15px;
            display : block;
            padding : 5px 0;
            max-width: 100%;
            height: 440px;
        }
        #tab-content2 {
            display : none;
            margin : 20px;
        }
        #tab-content3 {
            display : none;
            margin : 20px;
        }
        #tab-content4 {
            display : none;
            margin : 20px;
        }
        #tab-content5 {
            display : none;
            margin : 20px;
        }
        .button {
            width : 80px;
            height : 30px;
            background-color : #128F76;
            border : none;
            color : #FFF;
            text-align : center;
            text-decoration : none;
            display : inline-block;
            font-size : 16px;
            cursor : pointer;
            border-radius : 5px;
            margin : 4px 2px;
        }
        .buttonblue {
            background-color : blue;
            width : 120px;
        }
        .buttongreen {
            background-color : #128F76;
            width : 120px;
        }
        #label-logo {
            margin-left : 20px;
            border-color: black;
            border-style: solid;
            border-width: 2px;
            display : inline-block;
            background-image : url(SD/unknown.jpg);
            width : 96px;
            height : 96px;
            margin-top: 5px;
        }
        canvas {
            left : 0;
            margin-left : 0;
            display : inline-block;
            width : 96px;
            height : 96px;
            border : #000 solid 2px;
        }
        .jsgrid-header-cell {
            padding : 0.1em !important ;
        }
        .jsgrid-cell {
            overflow : hidden !important ;
            white-space : nowrap !important ;
            padding : 0.1em 0.2em !important ;
        }
        .ui-widget-header {
            background : #11e9e9 !important ;
        }
        .ui-dialog .ui-dialog-buttonpane {
            margin-top : 0 !important ;
            border-width : 0 !important ;
            padding : 0 0 0 1em !important ;
        }
        .ui-dialog .ui-dialog-content {
            margin-top : 0.3em !important ;
            padding : 0.1em !important ;
        }
        .boxstyle {
            height : 36px;
            padding-top : 0;
            padding-left : 5px;
            padding-bottom : 0;
            background-color: white;
            font-size : 16px;
            line-height : normal;
            border-color: black;
            border-style: solid;
            border-width: thin;
            border-radius : 5px;
        }
        .sdr_lbl_left {
            display: inline-block;
            float: left;
            text-align:right;
            height: 25px;
            width: 100px;
            padding-top: 0px;
            padding-right: 5px;
            padding-bottom: 0px;
        }
        .sdr_lbl_right {
            display: inline-block;
            float: left;
            text-align:right;
            height: 25px;
            width: 45px;
            padding-top: 0px;
            padding-left: 5px;
            padding-bottom: 0px;
        }
        .sdr_lbl_measure {
            display: inline-block;
            float: left;
            text-align:left;
            height: 25px;
            width: 40px;
            padding-top: 0px;
            padding-bottom: 0px;
        }
        #preloaded-images{
            display: none;
        }
        #dialog {
            display: none;
        }
    </style>
</head>

<script>



loadJSON('https://de1.api.radio-browser.info/json/countries', gotCountries, 'jsonp')


// ----------------------------------- TAB RADIO ------------------------------------

var _num = 0


// ----------------------------------- TAB CONFIG ------------------------------------
// load json is nodig mark
function loadJSON (path, success, error) {
  console.log(path)
  var xhr = new XMLHttpRequest()
  xhr.onreadystatechange = function () {
    if (xhr.readyState === 4) {
      if (xhr.status === 200) {
        success(JSON.parse(xhr.responseText))
      } else {
        error(xhr)
      }
    }
  }
  xhr.open('GET', path, true)
  xhr.send()
}

function selectcountry (presctrl) { // tab Radio: preset, select a station
  loadJSON('https://de1.api.radio-browser.info/json/stations/bycountry/' + presctrl.value, gotStations, 'jsonp')
}

function gotCountries (data) { // fill select countries
  var select = document.getElementById('country')
  var opt
  select.options.length = 1
  for (var i = 0; i < data.length; i++) {
    if (i < 2) continue
    opt = document.createElement('OPTION')
    opt.text = data[i].name
    select.add(opt)
  }
  console.log(data.uuid)
}

function gotStations (data) { // fill select stations
  var select = document.getElementById('stations')
  var opt
  select.options.length = 1
  for (var i = 0; i < data.length; i++) {
    opt = document.createElement('OPTION')
    opt.text = data[i].name
    opt.value = i
    select.add(opt)
  }
  countryallstations = data
}

function selectstation () { // select a station
  var e = document.getElementById('stations')
  var value = e.options[e.selectedIndex].value
  var sturl = countryallstations[value].url
  console.log(value)
  console.log(sturl)
  var f = document.getElementById('streamurl')
  f.value = sturl
  var g = document.getElementById('favicon')
  var favi = countryallstations[value].favicon
  g.value = favi
  var h = document.getElementById('homepageurl')
  h.value = countryallstations[value].homepage
  scaleCanvasImage(favi)
  var j = document.getElementById('stationname')
  j.value = countryallstations[value].name
}

function teststreamurl () { // Search: button play - enter a url to play from
  var theUrl = '/?stationURL=' + streamurl.value + '&version=' + Math.random()
  var xhr = new XMLHttpRequest()
  xhr.onreadystatechange = function () {
    if (xhr.readyState === XMLHttpRequest.DONE) {}
  }
  xhr.open('GET', theUrl, true)
  xhr.send()
}

function scaleCanvasImage (url) {
  var canvas = document.getElementById('canvas')
  var ctx = canvas.getContext('2d')
  var src
  ctx.beginPath()
  ctx.rect(0, 0, canvas.width, canvas.height)
  ctx.fillStyle = 'white'
  ctx.fill()
  var co = 'https://cors-anywhere.herokuapp.com/'
  src = co + url
  var imgObj = new Image()
  imgObj.onload = function () {
    var imgWidth = imgObj.width
    var imgHeight = imgObj.height
    var scaleX = 1
    var scaleY = 1
    if (imgWidth > canvas.width) scaleX = canvas.width / imgWidth
    if (imgHeight > canvas.height) scaleY = canvas.height / imgHeight
    var scale = scaleY
    if (scaleX < scaleY) scale = scaleX
    if (scale < 1) {
      imgHeight = imgHeight * scale
      imgWidth = imgWidth * scale
    }
    var dx = (canvas.width - imgWidth) / 2
    var dy = (canvas.height - imgHeight) / 2
    ctx.drawImage(imgObj, 0, 0, imgObj.width, imgObj.height, dx, dy, imgWidth, imgHeight)
  }
  imgObj.crossOrigin = 'anonymous'
  imgObj.src = src
}

function refreshCanvas () {
  var g = document.getElementById('favicon')
  scaleCanvasImage(g.value)
  console.log('refresh')
}

function downloadCanvasImage () {
  var filename
  var sn = document.getElementById('stationname')
  if (sn.value !== '') filename = sn.value + '.jpg'
  else filename = 'myimage.jpg'
  var lnk = document.createElement('a')
  var e // create an 'off-screen' anchor tag
  lnk.download = filename // the key here is to set the download attribute of the a tag
  lnk.href = canvas.toDataURL('image/jpeg')
  if (document.createEvent) { // create a 'fake' click-event to trigger the download
    e = document.createEvent('MouseEvents')
    e.initMouseEvent('click', true, true, window, 0, 0, 0, 0, 0, false, false, false, false, 0, null)
    lnk.dispatchEvent(e)
  } else if (lnk.fireEvent) {
    lnk.fireEvent('onclick')
  }
}
// -------------------------------------- TAB Info ---------------------------------------

   function httpGet ( theReq )
   {
   // var g = document.getElementById('streamurl')
   
   // var theUrl = "/?" + theReq + "urllogo=" + station.value + "namepref=" + station.value + "&version=" + Math.random() ;
    var theUrl =   "/?" + theReq + "&version=" + Math.random() ;
    
    var xhr = new XMLHttpRequest() ;
    xhr.onreadystatechange = function() {
      if ( xhr.readyState == XMLHttpRequest.DONE )
      {
        resultstr.value = xhr.responseText ;
      }
    }
    xhr.open ( "GET", theUrl ) ;
    xhr.send() ;
   }
   
   function setstat(nbr)
   {
     var theUrl = "/?setmem=" + 
                   nbr + "__" + stationname.value + 
                   "_url_=" + streamurl.value + 
                   "_icon_=" + favicon.value + 
                   "&version=" + Math.random() ;
     
     
     
     
     var xhr = new XMLHttpRequest() ;
     xhr.onreadystatechange = function() {
       if ( xhr.readyState == XMLHttpRequest.DONE )
       {
         resultstr.value = xhr.responseText ;
       }
     }
     xhr.open ( "GET", theUrl, false ) ;
     xhr.send() ;
   }
</script>

<body id="BODY">
  <ul>
   <li><a class="pull-left" href="#">EDISON Radio</a></li>
   <li><a class="pull-left" href="/index.html">Control</a></li>
   <li><a class="pull-left" href="/config.html">Config</a></li>
   <li><a class="pull-left" href="/mp3play.html">MP3 player</a></li>
   <li><a class="pull-left" href="/about.html">About</a></li>
   <li><a class="pull-left active" href="/find.html">Find</a></li>
  </ul>
  <br><br><br>
  <center>
   <h1>** EDISON Radio **</h1>


  <hr>


  <!--==============================================================================================-->
  <div id="Search">
      <div style="height: 30px;">
        This service is provided by
        <a target="_blank" href="http://www.radio-browser.info/gui/#/">Community Radio Browser</a>
      </div>
      <div style="display: flex;">
        <div style="flex: 0 0 calc(100% - 66px);">
          <select class="boxstyle" style="width: 75%;" onchange="selectcountry(this)" id="country">
            <option value="-1">Select a country here</option>
          </select>
          <select class="boxstyle" style="width: 75%; margin-top: 5px;" onchange="selectstation(this)" id="stations">
            <option value="-1">Select a station here</option>
          </select>
        </div>
      </div>
      <hr>
      <div style="display: flex;">
        <div style="font-size: 50px; text-align: center; flex: 1;">
          <canvas id="canvas" width="96" height="96" class="playable-canvas"></canvas>
        </div>
      </div>
      <hr>
      
      <div style="display: flex;">
        <div style="flex: 0 0 calc(100% - 66px); height: 66px;"><br>
          <a>Prefered Name</a><br>
          <input type="text" class="boxstyle" style="width: calc(75% - 8px);"
            id="stationname" placeholder="Prefered Name">
        </div>
        <div style="padding-left: 2px; height: 66px;">
          <img src="SD/png/Button_Ready_Blue.png" alt=">>"
            onmousedown="this.src='SD/png/Button_Ready_Yellow.png'"
            onmouseup="this.src='SD/png/Button_Ready_Blue.png'"
            onclick=""/>
        </div>
      </div>

      
      <div style="display: flex;">
        <div style="flex: 0 0 calc(100% - 66px); height: 66px;"><br>
          <a>StreamURL</a><br>
          <input type="text" class="boxstyle" style="width: calc(75% - 8px);"
            id="streamurl" placeholder="StreamURL">
        </div>
        <div style="padding-left: 2px; height: 66px;">
          <img src="SD/png/Button_Ready_Blue.png" alt=">>"
            onmousedown="this.src='SD/png/Button_Ready_Yellow.png'"
            onmouseup="this.src='SD/png/Button_Ready_Blue.png'"
            onclick="teststreamurl()"/>
        </div>
      </div>
      <div style="display: flex;">
        <div style="flex: 0 0 calc(100% - 66px); height: 66px;">
         <a>HomepageUrl</a><br>
          <input type="text" class="boxstyle" style=" width: calc(75% - 8px);"
          id="homepageurl" placeholder="HomepageURL"></input>
     
        </div>
        <div style="flex: 1; padding-left: 2px; height: 66px;">
          <img src="SD/png/Button_Ready_Blue.png" alt=">>"
            onmousedown="this.src='SD/png/Button_Ready_Yellow.png'"
            onmouseup="this.src='SD/png/Button_Ready_Blue.png'"
            onclick="window.open(homepageurl.value, '_blank')"/>
        </div>
      </div>
      <div style="display: flex;">
        <div style="flex: 0 0 calc(100% - 66px); height: 66px;">
         <a>LogoUrl</a><br>         
          <input type="text" class="boxstyle" style="width: calc(75% - 8px);" onclick="refreshCanvas()"
            id="favicon" placeholder="Favicon">
        </div>
        <div style="flex: 1;  padding-left: 2px; height: 66px;">
          <img src="SD/png/Button_Ready_Blue.png" alt=">>"
            onmousedown="this.src='SD/png/Button_Ready_Yellow.png'"
            onmouseup="this.src='SD/png/Button_Ready_Blue.png'"
            onclick="window.open(favicon.value, '_blank')"/>
        </div>
      </div>
      <hr>
      <a>Save station as preset:</a><br>
   <button class="button" onclick="setstat(0)">0</button>
   <button class="button" onclick="setstat(1)">1</button>
   <button class="button" onclick="setstat(2)">2</button>
   <button class="button" onclick="setstat(3)">3</button>
   <button class="button" onclick="setstat(4)">4</button>
   <button class="button" onclick="setstat(5)">5</button>
   <button class="button" onclick="setstat(6)">6</button>
   <button class="button" onclick="setstat(7)">7</button>
    <input type="text" width="600px" size="120" id="resultstr" placeholder="Waiting for a command...."><br> 
      <div style="display: flex;">
      
            <form method="post" accept-charset="utf-8" name="form1">
              <input name="hidden_data" id="hidden_data" type="hidden"/>
            </form>
          </div>
        </div>
      </div>
  </div>
  
</div>
</body>
</html>

)=====" ; 
