#include "tft.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const int progressBarWidth = 100;
const int progressBarHeight = 10;
const int progressBarX = (tft.width() - progressBarWidth) / 2;
const int progressBarY = (tft.height() - progressBarHeight) / 2;

void TFT_init() 
{
  tft.initR(INITR_BLACKTAB); 
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
}


void updateProgressBar(int percentage) 
{
  int progressWidth = (progressBarWidth * percentage) / 100;
  
  tft.fillRect(progressBarX, progressBarY, progressBarWidth, progressBarHeight, ST7735_BLACK);
  tft.fillRect(progressBarX, progressBarY, progressWidth, progressBarHeight, ST7735_GREEN);
  
  tft.drawRect(progressBarX, progressBarY, progressBarWidth, progressBarHeight, ST7735_WHITE);
  
  tft.setCursor(progressBarX + progressBarWidth / 2 - 13, progressBarY + progressBarHeight + 7);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(0);
  tft.print(percentage);
  tft.print("%");

}

void TFT_WriteText(const String& text, uint16_t color, uint8_t size, int16_t x, int16_t y) 
{
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(color); // Set the text color
  tft.setTextSize(size); // Set the text size
  tft.setCursor(x, y); // Set the cursor location
  tft.println(text); // Print the text on the display
}
