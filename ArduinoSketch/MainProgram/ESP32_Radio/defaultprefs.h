// Default preferences in raw data format for PROGMEM
//
#define defaultprefs_version 1808016
const char defprefs_txt[] PROGMEM = R"=====(
# Example configuration
# Programmable input pins:
gpio_00 = uppreset = 1
gpio_12 = upvolume = 2
gpio_13 = downvolume = 2
gpio_14 = stop
gpio_17 = resume
gpio_34 = station = icecast.omroep.nl:80/radio1-bb-mp3
#
# MQTT settings
mqttbroker = none
mqttport = 1883
mqttuser = none
mqttpasswd = none
mqqprefix = none
# Enter your WiFi network specs here:
wifi_00 = SSID1/PASSWD1
wifi_01 = SSID2/PASSWD2
#
volume = 72
toneha = 0
tonehf = 0
tonela = 0
tonelf = 0
#
# Some preset examples preson = station log, preset= station url
precon_00 = https://i.postimg.cc/Z5w6Md75/Logo-Sublime-De-Leckere-Donkere-achtergrond.png
precon_01 = http://1047hit.com/wp/wp-content/uploads/2016/06/cropped-logo-270x270.png
precon_02 = https://i.postimg.cc/Z5w6Md75/Logo-Sublime-De-Leckere-Donkere-achtergrond.png
precon_03 = https://i.postimg.cc/Z5w6Md75/Logo-Sublime-De-Leckere-Donkere-achtergrond.png
precon_04 = https://l1.nl//static/meta/apple-touch-icon.png
precon_05 = https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/NPO_Radio_1_logo_2014.svg/640px-NPO_Radio_1_logo_2014.svg.png
precon_06 = https://www.npo3fm.nl/templates/npo3fm/images/logo-npo3fm.png
precon_07 = http://www.themusicalbox.com.ar/favicon.ico
preset = 0
preset_00 = playerservices.streamtheworld.com/api/livestream-redirect/SUBLIMEARROWJAZZ.mp3   # 0 - Sublime - Arrow Jazz
preset_01 = s8.voscast.com:7528/;stream1483728563212/1 # 1 - 1047 Hit - San Jose
preset_02 = playerservices.streamtheworld.com/api/livestream-redirect/SUBLIMESMOOTH.mp3      # 2 - Sublime - Smooth
preset_03 = playerservices.streamtheworld.com/api/livestream-redirect/SUBLIMEPLAYGROUND.mp3?ver=78785 # 3 - Sublime Christmas
preset_04 = d34pj260kw1xmk.cloudfront.net/icecast/l1/radio-bb-mp3                            # 4 - L1 Radio
preset_05 = icecast.omroep.nl:80/radio1-bb-mp3                                               # 5 - NPO Radio 1
preset_06 = icecast.omroep.nl/3fm-bb-aac                                                     # 6 - NPO 3FM
preset_07 = albireo.shoutca.st:9740/stream # 7 - The Musical Box Radio
preset_08 = skonto.ls.lv:8002/mp3                                                            # 8 - Skonto 128k
preset_09 = 94.23.66.155:8106                                                                # 9 - *ILR CHILL and GROOVE
preset_10 = ihr/IHR_IEDM                                                                     # 10 - iHeartRadio IHR_IEDM
preset_11 = ihr/IHR_TRAN                                                                     # 11 - iHeartRadio IHR_TRAN
preset_12 = s2.netradiofm.com:6338                                                           # 12 - twitradioo#
# Clock offset and daylight saving time
clk_server = pool.ntp.org                            # Time server to be used
clk_offset = 1                                       # Offset with respect to UTC in hours
clk_dst = 1                                          # Offset during daylight saving time (hours)
# Some IR codes
ir_40BF = upvolume = 2
ir_C03F = downvolume = 2
# GPIO pinnings
pin_ir = 35                                          # GPIO Pin number for IR receiver VS1838B
pin_enc_clk = 26                                     # GPIO Pin number for rotary encoder "CLK"
pin_enc_dt = 25                                      # GPIO Pin number for rotary encoder "DT"
pin_enc_sw = 27                                      # GPIO Pin number for rotary encoder "SW"
#
pin_tft_cs = 15                                      # GPIO Pin number for TFT "CS"
pin_tft_dc = 2                                       # GPIO Pin number for TFT "DC"
#
pin_sd_cs = 21                                       # GPIO Pin number for SD card "CS"
#
pin_vs_cs = 5                                        # GPIO Pin number for VS1053 "CS"
pin_vs_dcs = 16                                      # GPIO Pin number for VS1053 "DCS"
pin_vs_dreq = 4                                      # GPIO Pin number for VS1053 "DREQ"
)=====" ;
