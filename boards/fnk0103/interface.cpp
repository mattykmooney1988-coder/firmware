1| #include "core/powerSave.h"
2| #include "core/utils.h"
3| #include <interface.h>
4| 
5| #include <CYD28_TouchscreenR.h>
6| CYD28_TouchR touch(TFT_HEIGHT, TFT_WIDTH);
7| 
8| /***************************************************************************************
9| ** Function name: _setup_gpio()
10| ** Location: main.cpp
11| ** Description:   initial setup for the device
12| ***************************************************************************************/
13| void _setup_gpio() {
14|     pinMode(XPT2046_SPI_CONFIG_CS_GPIO_NUM, OUTPUT);
15|     digitalWrite(XPT2046_SPI_CONFIG_CS_GPIO_NUM, HIGH);
16|     bruceConfig.colorInverted = 0;
17| }
18| 
19| /***************************************************************************************
20| ** Function name: _post_setup_gpio()
21| ** Location: main.cpp
22| ** Description:   second stage gpio setup to make a few functions work
23| ***************************************************************************************/
24| void _post_setup_gpio() {
25|     if (!touch.begin(&tft.getSPIinstance())) {
26|         Serial.println("Touch IC not Started");
27|         log_i("Touch IC not Started");
28|     } else Serial.println("Touch IC Started");
29| 
30|     pinMode(TFT_BL, OUTPUT);
31|     ledcAttach(TFT_BL, TFT_BRIGHT_FREQ, TFT_BRIGHT_Bits);
32|     ledcWrite(TFT_BL, 255);
33| }
34| 
35| /***************************************************************************************
36| ** Function name: getBattery()
37| ** location: display.cpp
38| ** Description:   Delivers the battery value from 1-100
39| ***************************************************************************************/
40| int getBattery() { return 0; }
41| 
42| /*********************************************************************
43| ** Function: setBrightness
44| ** location: settings.cpp
45| ** set brightness value
46| **********************************************************************/
47| void _setBrightness(uint8_t brightval) {
48|     int dutyCycle;
49|     if (brightval == 100) dutyCycle = 255;
50|     else if (brightval == 75) dutyCycle = 130;
51|     else if (brightval == 50) dutyCycle = 70;
52|     else if (brightval == 25) dutyCycle = 20;
53|     else if (brightval == 0) dutyCycle = 0;
54|     else dutyCycle = ((brightval * 255) / 100);
55|     ledcWrite(TFT_BL, dutyCycle);
56| }
57| 
58| /*********************************************************************
59| ** Function: InputHandler
60| ** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
61| **********************************************************************/
62| void InputHandler(void) {
63|     static unsigned long tm = millis();
64|     if (!(millis() - tm > 200 || LongPress)) return;
65| 
66|     if (touch.touched()) {
67|         auto t = touch.getPointScaled();
68|         t = touch.getPointScaled();
69|         if (bruceConfigPins.rotation == 3) {
70|             t.y = (tftHeight + 20) - t.y;
71|             t.x = tftWidth - t.x;
72|         }
73|         if (bruceConfigPins.rotation == 0) {
74|             int tmp = t.x;
75|             t.x = tftWidth - t.y;
76|             t.y = tmp;
77|         }
78|         if (bruceConfigPins.rotation == 2) {
79|             int tmp = t.x;
80|             t.x = t.y;
81|             t.y = (tftHeight + 20) - tmp;
82|         }
83|         tm = millis();
84|         if (!wakeUpScreen()) AnyKeyPress = true;
85|         else return;
86|         touchPoint.x = t.x;
87|         touchPoint.y = t.y;
88|         touchPoint.pressed = true;
89|         touchHeatMap(touchPoint);
90|     } else touchPoint.pressed = false;
91| }
