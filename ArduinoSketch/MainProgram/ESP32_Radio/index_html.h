// index.html file in raw data format for PROGMEM
//
#define index_html_version 180102
const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<style type="text/css">
canvas {
            left : 0;
            margin-left : 0;
            display : inline-block;
            width : 96px;
            height : 96px;
            border : #000 solid 2px;
        }

.sdr_lbl_left {            display: inline-block;
            float: left;
            text-align:right;
            height: 25px;
            width: 100px;
            padding-top: 0px;
            padding-right: 5px;
            padding-bottom: 0px;
}
.sdr_lbl_measure {            display: inline-block;
            float: left;
            text-align:left;
            height: 25px;
            width: 40px;
            padding-top: 0px;
            padding-bottom: 0px;
}
.sdr_lbl_right {            display: inline-block;
            float: left;
            text-align:right;
            height: 25px;
            width: 45px;
            padding-top: 0px;
            padding-left: 5px;
            padding-bottom: 0px;
}








/*Chrome*/
@media screen and (-webkit-min-device-pixel-ratio:0) {
    input[type='range'] {
      overflow: hidden;
      width:80px;
      -webkit-appearance: none;
      background-color: black;
   }
    
    input[type='range']::-webkit-slider-runnable-track {
      height: 10px;
      -webkit-appearance: none;
      color: pink;
      margin-top: -1px;
    }
    
    input[type='range']::-webkit-slider-thumb {  /** knopje van de slider */
      width: 10px;
      -webkit-appearance: none;
      height: 10px;
      cursor: ew-resize;
  
      background: blue;
      box-shadow: -80px 0 0 80px orange;
    /** */
    

}
/** FF*/
input[type="range"]::-moz-range-progress {
  background-color: red; 
}
input[type="range"]::-moz-range-track {  
  background-color: white;
}
/* IE*/
input[type="range"]::-ms-fill-lower {
  background-color: yellow; 
}
input[type="range"]::-ms-fill-upper {  
  background-color: green;
}



.tableslider {
  border-top-width: 1px;
  border-right-width: 1px;
  border-bottom-width: 1px;
  border-left-width: 1px;
  border-top-color: red;
  border-right-color: red;
  border-bottom-color: red;
  border-left-color: red;
  border-radius: 15px;
}
</style>
<html>
<head>
 <title>EDISON Radio</title>
  <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
  <link rel="stylesheet" type="text/css" href="radio.css">
  <link rel="Shortcut Icon" type="image/ico" href="favicon.ico">
</head>
<body>
  <ul> 
   <li><a class="pull-left" href="#">Edison Radio</a></li>
   <li><a class="pull-left active" href="/index.html">Control</a></li>
   <li><a class="pull-left" href="/config.html">Config</a></li>
   <li><a class="pull-left" href="/mp3play.html">MP3 player</a></li>
   <li><a class="pull-left" href="/about.html">About</a></li>
   <li><a class="pull-left" href="/find.html">Find</a></li>
 
  </ul>
  <br><br><br>
  <center>
   <h1>EDISON Radio</h1>
   <button class="button" onclick="httpGet('downpreset=1')">PREV</button>
   <button class="button" onclick="httpGet('uppreset=1')">NEXT</button>
   <button class="button" onclick="httpGet('downvolume=2')">VOL-</button>
   <button class="button" onclick="httpGet('upvolume=2')">VOL+</button>
   <button class="button" onclick="httpGet('mute')">(un)MUTE</button>
   <button class="button" onclick="httpGet('stop')">(un)STOP</button>
   <button class="button" onclick="httpGet('status')">STATUS</button>
   


  <table border="0" cellpadding="0" cellspacing="0" style="width:500px">
     
 
     
     
        
    
    <tr>
     <td colspan="3"><center>

     </center></td>
    </tr>
    <tr>
     <td width="40%" align="center"></td>
  
     <td  rowspan="2" align="center" valign="bottom"><center>
             <div style="display: flex;">
        <div style="font-size: 50px; text-align: center; flex: 1;">
          <canvas id="canvas" width="96" height="96" class="playable-canvas"></canvas>
        </div>
      </div> 
     </center>       
     </td>
     <td width="40%" align="center"></td>
     <br><br>
    </tr>
    <tr>
     <td width="40%" height="52" align="center">
     </td>
        <td width="40%" align="center"></td>
     <br><br>
    </tr>
    <tr>
      <td colspan="3" align="center"><p>&nbsp;
        </p>
        <label for="preset"><big>Preset:</big></label><br>
          <select name="preset" class="select selectw" id="preset" onChange="handlepreset(this)">
            <option value="-1">Select a preset here</option>
          </select>
      </p></td>
    </tr>
    <tr>
     <td colspan="3" align="center"><center>
     <br>
      <input type="text" size="50%" id="station" placeholder="Enter a station/file here....">
   <button class="button" onclick="setstat()">PLAY</button>
   </center> </td>
    </tr>
       <tr>
     <td colspan="3"><center>
     <br>
         <br>
   <input type="text" width="600px" size="72" id="resultstr" placeholder="Waiting for a command...."><br>
   </center> </td>
    </tr>
</table>
   
      <hr>
  <div style="display: flex;">
        <div style="flex: 0 0 calc(100% - 66px); height: 66px;">
          <p><a>LogoUrl</a><br>         
            <input type="text" class="boxstyle" style="width:25%;" onclick=""
            id="favicon" placeholder="Favicon" name="favicon">
          </p>
          <div style="width: 380px; height: 140px; ">
            <center>

<table    cellpadding="0" cellspacing="0" class="table"  >
  <tr>
    <td>
                  <label class="sdr_lbl_left">Treble Gain:</label>
              <div class="slidecontainer" style="float: left; width 180px; height: 25px;">
                <input type="range" min="0" max="15" value="8" id="TrebleGain" onmouseup="slider_TG_mouseUp()" oninput="slider_TG_change()">
              </div>
              <label id="label_TG_value" class="sdr_lbl_right">000,0</label>
              <label class="sdr_lbl_measure"> dB</label>
              <label class="sdr_lbl_left">Treble Freq:</label>
              <div class="slidecontainer" style="float: left; height: 25px;">
                <input type="range" min="1" max="15" value="8" id="TrebleFreq" onmouseup="slider_TF_mouseUp()" oninput="slider_TF_change()">
              </div>
              <label id="label_TF_value" class="sdr_lbl_right">00</label>
              <label class="sdr_lbl_measure"> KHz</label>
              <label class="sdr_lbl_left">Bass Gain:</label>
              <div class="slidecontainer" style="float: left; height: 25px;">
                <input type="range" min="0" max="15" value="8" id="BassGain" onmouseup="slider_BG_mouseUp()" oninput="slider_BG_change()">
              </div>
              <label id="label_BG_value" class="sdr_lbl_right">+00</label>
              <label class="sdr_lbl_measure"> dB</label>
              
              <label class="sdr_lbl_left">Bass Freq:</label>
              <div class="slidecontainer" style="float: left; height: 25px;">
                <input type="range" min="2" max="15" value="6" id="BassFreq" onmouseup="slider_BF_mouseUp()" oninput="slider_BF_change()">
              </div>
              <label  id="label_BF_value" class="sdr_lbl_right">000</label>
              <label class="sdr_lbl_measure">Hz</label>
            
              <label class="sdr_lbl_left">Volume</label>
              <div class="slidecontainer" style="float: left; height: 25px;">
                <input  type="range" min="0" max="120" value="80"  step="2" id="VolGain" onmouseup="slider_VOL_mouseUp()" oninput="slider_VOL_change()">
              </div>
              <label id="label_VOL_value" class="sdr_lbl_right">100</label>
              <label class="sdr_lbl_measure"> %</label>
              
    </td>
  </tr>
</table>

            </center>
          </div>
          <p>&nbsp;</p>
        </div>
  </div>
</center>

<p>&nbsp;</p>
<p>&nbsp;</p>
 <p>&nbsp;</p>
<p>&nbsp; </p>
<script>
var trebleDB = ['-12,0', '-10,5', ' -9,0', ' -7,5', ' -6,0', ' -4,5', ' -3,0', ' -1,5',
  '  0,0', ' +1,5', ' +3,0', ' +4,5', ' +6,0', ' +7,5', ' +9,0', '+10,5']
  var trebleVal = [8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7]
   function httpGet ( theReq )
   {
    var theUrl = "/?" + theReq + "&version=" + Math.random() ;
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
  
   
   function httpGeticon ( theReq )
   {
    var theUrl = "/?iconid=" + preset.value + "&version=" + Math.random() ;
    var xhr = new XMLHttpRequest() ;
    xhr.onreadystatechange = function() {
      if ( xhr.readyState == XMLHttpRequest.DONE );
      {
       resultstr.value = xhr.responseText ;

     //  var g = document.getElementById('favicon');
       var favi = xhr.responseText;
       if ( favi==""){favi="http://www.judoles.nl/Projecten/Logo200.png" }
       else {
     //  g.value = favi;
       }
       scaleCanvasImage(favi);

       
      }
    }
    xhr.open ( "GET", theUrl ) ;
    xhr.send() ;
   }

   
   function handlepreset ( presctrl )
   {
     httpGet ( "preset=" + presctrl.value ) ;
     httpGeticon("unknown");
   }
/*
   function handletone ( tonectrl )
   {
     var theUrl = "/?" + tonectrl.id + "=" + tonectrl.value +
                  "&version=" + Math.random() ;
     var xhr = new XMLHttpRequest() ;
   console.log("request=%s",theUrl)
     xhr.onreadystatechange = function() {
       if ( xhr.readyState == XMLHttpRequest.DONE )
       {
         resultstr.value = xhr.responseText ;
          
       }
     }
     xhr.open ( "GET", theUrl, false ) ;
     xhr.send() ;
   }
*/
   function setstat()
   {
     var theUrl = "/?station=" + station.value + "&version=" + Math.random() ;
     var xhr = new XMLHttpRequest() ;
     xhr.onreadystatechange = function() {
       if ( xhr.readyState == XMLHttpRequest.DONE )
       {
         resultstr.value = xhr.responseText ;
       }
     }
     xhr.open ( "GET", theUrl, false ) ;
     xhr.send() ;

    //   var g = document.getElementById('favicon');
       var favi = "http://www.judoles.nl/Projecten/Logo200.png";
      // g.value = favi;
       scaleCanvasImage(favi);




     

   }

   function selectItemByValue(elmnt, value)
   {// if (elemnt=="tonehf")elmnt = "label_TF_value";
     var sel = document.getElementById(elmnt) ;
   console.log("received element: %s with value: %s",elmnt,value)
     for(var i=0; i < sel.options.length; i++)
     {
       if(sel.options[i].value == value)
         sel.selectedIndex = i;
     }
   }
   
   // Request current status.
   function myRefresh()
   {
    httpGet ('status') ;
    setTimeout(myRefresh,5000) ;
   }

   // Fill preset list initially
   //
   function onloadfunc()
   {
     var i, sel, opt, lines, parts ;
     var tmppre,tmppre2;
     var theUrl = "/?settings" + "&version=" + Math.random() ;
     var xhr = new XMLHttpRequest() ;
     var piclink;
     xhr.onreadystatechange = function() {
       if ( xhr.readyState == XMLHttpRequest.DONE )
       {
         lines = xhr.responseText.split ( "\n" ) ;
         for ( i = 0 ; i < ( lines.length-1 ) ; i++ )
         {
           sel = document.getElementById ( "preset" ) ;
           parts = lines[i].split ( "=" ) ;
           if ( parts[0].indexOf ( "preset_" ) == 0 )
           {console.log ("from mem: preset: %s value: %s",parts[0],parts[1])
             opt = document.createElement ( "OPTION" ) ;
             opt.value = parts[0].substring ( 7 ) ;
             opt.text = parts[1] ;
             sel.add( opt ) ;
           }
           if ( ( parts[0].indexOf ( "tone" ) == 0 ) ||
                ( parts[0] == "preset" ) )
           { if (parts[0]=="preset"){
            console.log("gevonden");
             tmppre=parts[0];
             tmppre2=parts[1];
             }
            // selectItemByValue ( parts[0], parts[1] ) ;
             setSlider(parts[0], parts[1]);
           }
     //  var g = document.getElementById('favicon');
       
       
           if((parts[0].indexOf ( "favicon" ) == 0))
           {
           // resultstr.value = parts[1] ;
          //  favicon.value = parts[1] ;
            piclink= parts[1];
           }
         }
         setTimeout(myRefresh,5000) ;
         
       }
       sel = document.getElementById ( "preset" ) ;
       sel.value=parseInt(tmppre2);
       console.log("key:%s",sel.value);
     }
     xhr.open ( "GET", theUrl, false ) ;
     xhr.send() ;
    // refreshCanvas();
     scaleCanvasImage(piclink);
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
 //src = co + 'http://www.judoles.nl/Projecten/Logo200.png'
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

function slider_TG_mouseUp () { // Slider Treble Gain   mouseupevent
  handlectrl('toneha', trebleVal[TrebleGain.value])
  // console.log('Treble Gain=%i',Number(TrebleGain.value));
}



function slider_TG_set (value) { // set Slider Treble Gain
  var val = Number(value)
  if (val < 8) val = val + 8
  else val = val - 8
  document.getElementById('TrebleGain').value = val
  document.getElementById('label_TG_value').innerHTML = trebleDB[TrebleGain.value]
  console.log('Treble Gain=%i', val)
}
function slider_TF_mouseUp () { // Slider Treble Freq   mouseupevent
  handlectrl('tonehf', TrebleFreq.value)
  // console.log('Treble Freq=%i', Number(TrebleFreq.value));
}

function slider_TF_change () { //  Slider Treble Freq  changeevent
  console.log('Treble Freq=%i', Number(TrebleFreq.value))
  document.getElementById('label_TF_value').innerHTML = TrebleFreq.value
}

function slider_TF_set (value) { // set Slider Treble Freq
  var val = Number(value)
  document.getElementById('TrebleFreq').value = val
  document.getElementById('label_TF_value').innerHTML = TrebleFreq.value
  console.log('Treble Freq=%i', val)
}

function slider_BG_mouseUp () { // Slider Bass Gain   mouseupevent
  handlectrl('tonela', BassGain.value)
  // console.log('Bass Gain=%i', Number(BassGain.value));
}

function slider_BG_change () { //  Slider Bass Gain  changeevent
  var sign = ''
  if (BassGain.value !== '0') sign = '+'
  console.log('Bass Gain=%i', Number(BassGain.value))
  document.getElementById('label_BG_value').innerHTML = sign + BassGain.value
}

function slider_BG_set (value) { // set Slider Bass Gain
  var val = Number(value)
  var sign = ''
  if (BassGain.value !== '0') sign = '+'
  document.getElementById('BassGain').value = val
  document.getElementById('label_BG_value').innerHTML = sign + BassGain.value
  console.log('Bass Gain=%i', val)
}

function slider_BF_mouseUp () { // Slider Bass Gain   mouseupevent
  handlectrl('tonelf', BassFreq.value)
  // console.log('Bass Freq=%i', Number(BassFreq.value));
}

function slider_BF_change () { //  Slider Bass Gain  changeevent
  console.log('Bass Freq=%i', Number(BassFreq.value))
  document.getElementById('label_BF_value').innerHTML = (BassFreq.value - 1) * 10
}

function slider_BF_set (value) { // set Slider Bass Gain
  var val = Number(value)
  document.getElementById('BassFreq').value = val
  document.getElementById('label_BF_value').innerHTML = (BassFreq.value - 1) * 10
  console.log('Bass Freq=%i', val)
}

function slider_VOL_mouseUp () { // Slider Bass Gain   mouseupevent
 // handlectrl('tonelf', BassFreq.value)
   console.log('volume=%i', Number(VolGain.value));
   httpGet('volume='+ VolGain.value)
}

function slider_VOL_change () { //  Slider Bass Gain  changeevent
  console.log('Volume=%i', Number(VolGain.value))
  document.getElementById('label_VOL_value').innerHTML = VolGain.value;
  //(VolGain.value - 1) * 10
}

function slider_TG_change () { //  Slider Treble Gain  changeevent
  console.log('Treble Gain=%i', Number(TrebleGain.value))
  document.getElementById('label_TG_value').innerHTML = trebleDB[TrebleGain.value]
}

function setSlider (elmnt, value) {
  if (elmnt === 'toneha') slider_TG_set(value)
  if (elmnt === 'tonehf') slider_TF_set(value)
  if (elmnt === 'tonela') slider_BG_set(value)
  if (elmnt === 'tonelf') slider_BF_set(value)
}
function handlectrl (id, val) { // Radio: treble, bass, freq
  var theUrl = '/?' + id + '=' + val + '&version=' + Math.random()
  var xhr = new XMLHttpRequest()
  console.log("request=%s",theUrl) 
  xhr.onreadystatechange = function () {
    if (xhr.readyState === XMLHttpRequest.DONE) {
      resultstr.value = xhr.responseText
    }
  }
  xhr.open('GET', theUrl, true)
  xhr.send()
}


   window.onload = onloadfunc ;   // Run after page has been loaded
 
    </script>
</body>
</html>
<noscript>
  <link rel="stylesheet" href="radio.css">
  Sorry, ESP-radio does not work without JavaScript!
</noscript>
)=====" ;
