#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "STD_TYPES.h"

#define TFT_CS    15   // TFT chip select pin
#define TFT_RST   2    // TFT reset pin
#define TFT_DC    4    // TFT data/command pin
#define TFT_SCLK  28   // TFT clock pin
#define TFT_MISO  19   // TFT MISO (not used)
#define TFT_MOSI  23   // TFT MOSI pin
