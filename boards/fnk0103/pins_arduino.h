#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// USB Serial (ESP32-S3 native USB)
static const uint8_t TX = 43;
static const uint8_t RX = 44;

// Main SPI bus (shared with SD card, CC1101, NRF24)
#define SPI_SCK_PIN  12
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 13
#define SPI_SS_PIN   15

static const uint8_t SS   = SPI_SS_PIN;
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK  = SPI_SCK_PIN;

// I2C / Grove
#define GROVE_SDA 4
#define GROVE_SCL 5
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

// Serial / GPS
#define SERIAL_TX     43
#define SERIAL_RX     44
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// BadUSB
#define BAD_TX SERIAL_TX
#define BAD_RX SERIAL_RX
#define USB_as_HID 1

// Buttons - touch only
#define HAS_BTN    0
#define BTN_ALIAS  "\"Ok\""
#define BTN_PIN    0
#define BTN_ACT    LOW

// IR / RF
#define TXLED   2
#define LED_ON  HIGH
#define LED_OFF LOW

// CC1101 on main SPI bus
#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN  2
#define CC1101_SS_PIN    15
#define CC1101_MOSI_PIN  SPI_MOSI_PIN
#define CC1101_SCK_PIN   SPI_SCK_PIN
#define CC1101_MISO_PIN  SPI_MISO_PIN

// NRF24 on main SPI bus
#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN    2
#define NRF24_SS_PIN    15
#define NRF24_MOSI_PIN  SPI_MOSI_PIN
#define NRF24_SCK_PIN   SPI_SCK_PIN
#define NRF24_MISO_PIN  SPI_MISO_PIN

// W5500 on main SPI bus
#define USE_W5500_VIA_SPI
#define W5500_SS_PIN    15
#define W5500_MOSI_PIN  SPI_MOSI_PIN
#define W5500_SCK_PIN   SPI_SCK_PIN
#define W5500_MISO_PIN  SPI_MISO_PIN
#define W5500_INT_PIN   2

// SD Card on main SPI bus
#define SDCARD_CS   42
#define SDCARD_SCK  SPI_SCK_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN

// Font sizes
#define FP 1
#define FM 2
#define FG 3

// Screen / Display
#define HAS_SCREEN 1
#define ROTATION   1
#define BACKLIGHT  45
#define MINBRIGHT  (uint8_t)1

// TFT_eSPI - ST7789, 3.2" 320x240, SPI
#define USER_SETUP_LOADED 1
#define ST7789_DRIVER     1
#define TFT_WIDTH         240
#define TFT_HEIGHT        320
#define TFT_MISO          13
#define TFT_MOSI          11
#define TFT_SCLK          12
#define TFT_CS            10
#define TFT_DC            9
#define TFT_RST           46
#define TFT_BL            45
#define TFT_BACKLIGHT_ON  HIGH
#define SMOOTH_FONT       1
#define SPI_FREQUENCY       40000000
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY 2500000

// Resistive touch (XPT2046, shared SPI bus)
#define HAS_TOUCH              1
#define HAS_RESISTIVE_TOUCH    1
#define TOUCH_XPT2046_SPI
#define XPT2046_TOUCH_CONFIG_INT_GPIO_NUM  -1
#define XPT2046_SPI_BUS_MISO_IO_NUM        SPI_MISO_PIN
#define XPT2046_SPI_BUS_MOSI_IO_NUM        SPI_MOSI_PIN
#define XPT2046_SPI_BUS_SCLK_IO_NUM        SPI_SCK_PIN
#define XPT2046_SPI_CONFIG_CS_GPIO_NUM     14

// TFT brightness PWM
#define TFT_BRIGHT_CHANNEL 0
#define TFT_BRIGHT_Bits    8
#define TFT_BRIGHT_FREQ    5000

// Audio / Mic - not present
#define PIN_CLK       -1
#define PIN_DATA      -1
#define I2S_SCLK_PIN  -1
#define I2S_DATA_PIN  -1
#define BCLK          -1
#define WCLK          -1
#define DOUT          -1

// RGB LED - not present
#define RGB_LED -1

#endif /* Pins_Arduino_h */
