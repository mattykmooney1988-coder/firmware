1| #ifndef Pins_Arduino_h
2| #define Pins_Arduino_h
3| 
4| #include "soc/soc_caps.h"
5| #include <stdint.h>
6| 
7| // USB Serial (ESP32-S3 native USB)
8| static const uint8_t TX = 43;
9| static const uint8_t RX = 44;
10| 
11| // Main SPI bus (shared with SD card, CC1101, NRF24)
12| #define SPI_SCK_PIN  12
13| #define SPI_MOSI_PIN 11
14| #define SPI_MISO_PIN 13
15| #define SPI_SS_PIN   15
16| 
17| static const uint8_t SS   = SPI_SS_PIN;
18| static const uint8_t MOSI = SPI_MOSI_PIN;
19| static const uint8_t MISO = SPI_MISO_PIN;
20| static const uint8_t SCK  = SPI_SCK_PIN;
21| 
22| // I2C / Grove
23| #define GROVE_SDA 4
24| #define GROVE_SCL 5
25| static const uint8_t SDA = GROVE_SDA;
26| static const uint8_t SCL = GROVE_SCL;
27| 
28| // Serial / GPS
29| #define SERIAL_TX     43
30| #define SERIAL_RX     44
31| 
32| // IR / RF
33| #define TXLED   2
34| #define LED_ON  HIGH
35| #define LED_OFF LOW
36| 
37| // CC1101 on main SPI bus
38| #define USE_CC1101_VIA_SPI
39| #define CC1101_GDO0_PIN  2
40| #define CC1101_SS_PIN    15
41| #define CC1101_MOSI_PIN  SPI_MOSI_PIN
42| #define CC1101_SCK_PIN   SPI_SCK_PIN
43| #define CC1101_MISO_PIN  SPI_MISO_PIN
44| 
45| // NRF24 on main SPI bus
46| #define USE_NRF24_VIA_SPI
47| #define NRF24_CE_PIN    2
48| #define NRF24_SS_PIN    15
49| #define NRF24_MOSI_PIN  SPI_MOSI_PIN
50| #define NRF24_SCK_PIN   SPI_SCK_PIN
51| #define NRF24_MISO_PIN  SPI_MISO_PIN
52| 
53| // W5500 on main SPI bus
54| #define USE_W5500_VIA_SPI
55| #define W5500_SS_PIN    15
56| #define W5500_MOSI_PIN  SPI_MOSI_PIN
57| #define W5500_SCK_PIN   SPI_SCK_PIN
58| #define W5500_MISO_PIN  SPI_MISO_PIN
59| #define W5500_INT_PIN   2
60| 
61| // SD Card on main SPI bus
62| #define SDCARD_CS   42
63| #define SDCARD_SCK  SPI_SCK_PIN
64| #define SDCARD_MISO SPI_MISO_PIN
65| #define SDCARD_MOSI SPI_MOSI_PIN
66| 
67| // Font sizes
68| #define FP 1
69| #define FM 2
70| #define FG 3
71| 
72| // Screen / Display
73| #define HAS_SCREEN 1
74| #define ROTATION   1
75| #define BACKLIGHT  45
76| #define MINBRIGHT  (uint8_t)1
77| 
78| // TFT_eSPI - ST7789, 3.2" 320x240, SPI
79| #define USER_SETUP_LOADED 1
80| #define ST7789_DRIVER     1
81| #define TFT_WIDTH         240
82| #define TFT_HEIGHT        320
83| #define TFT_MISO          13
84| #define TFT_MOSI          11
85| #define TFT_SCLK          12
86| #define TFT_CS            10
87| #define TFT_DC            9
88| #define TFT_RST           46
89| #define TFT_BL            45
90| #define TFT_BACKLIGHT_ON  HIGH
91| #define SMOOTH_FONT       1
92| #define SPI_FREQUENCY       40000000
93| #define SPI_READ_FREQUENCY  20000000
94| #define SPI_TOUCH_FREQUENCY 2500000
95| 
96| // Resistive touch (XPT2046, shared SPI bus)
97| #define HAS_TOUCH              1
98| #define HAS_RESISTIVE_TOUCH    1
99| #define TOUCH_XPT2046_SPI
100| #define XPT2046_TOUCH_CONFIG_INT_GPIO_NUM  -1
101| #define XPT2046_SPI_BUS_MISO_IO_NUM        SPI_MISO_PIN
102| #define XPT2046_SPI_BUS_MOSI_IO_NUM        SPI_MOSI_PIN
103| #define XPT2046_SPI_BUS_SCLK_IO_NUM        SPI_SCK_PIN
104| #define XPT2046_SPI_CONFIG_CS_GPIO_NUM     14
105| 
106| // TFT brightness PWM
107| #define TFT_BRIGHT_CHANNEL 0
108| #define TFT_BRIGHT_Bits    8
109| #define TFT_BRIGHT_FREQ    5000
110| 
111| // Audio / Mic - not present
112| #define PIN_CLK       -1
113| #define PIN_DATA      -1
114| #define I2S_SCLK_PIN  -1
115| #define I2S_DATA_PIN  -1
116| #define BCLK          -1
117| #define WCLK          -1
118| #define DOUT          -1
119| 
120| // RGB LED - not present
121| #define RGB_LED -1
122| 
123| #endif /* Pins_Arduino_h */
