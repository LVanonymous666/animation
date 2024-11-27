#include <NanitLib.h>

int r = 20;
int x = r;
int y = r;
int startX = r;
int startY = r;
int endX = tft.width() + 0.5 * r;
int endY = tft.height() - 2.5 * r;
int stepX = 3;
int stepY = 2;

void setup() {
  Nanit_Base_Start();
  tft.fillScreen(WHITE16);
}

void loop() {
  tft.drawCircle(x, y, r, BLACK16);
  tft.fillCircle(x, y, r-1, RED16);
  delay(20);
  tft.drawCircle(x, y, r, WHITE16);
  tft.fillCircle(x, y, r-1, WHITE16);
  addSteps();
}

void addSteps() {
  setSteps();
  x += stepX;
  y += stepY;
}

void setSteps() {
  if(x <= startX) {
    stepX = 3;
  } else if(x >= endX) {
    stepX = -3;
  }

  if(y <= startY) {
    stepY = 2;
  } else if(y >= endY) {
    stepY = -2;
  }
}
