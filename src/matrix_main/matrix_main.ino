/*************************************************** 
  2017.08.04 teppei
  8*16のマトリクスLEDにテキストをスクロール表示する
 ****************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();


// 定数
String VIEW_TEXT1 = "P-Robo 204"; // 表示するテキスト (20文字まで)
String VIEW_TEXT2 = "EXO WHEEL";  // 表示するテキスト2　(20文字まで)
int8_t TEXT1_NUM = 10;
int8_t TEXT2_NUM = 9;


// グローバル変数
int8_t scroll1 = (-1) * (TEXT1_NUM * 5 + 16);
int8_t scroll2 = (-1) * (TEXT2_NUM * 5 + 16);

// 設定
void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("16x8 LED Mini Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  matrix.setTextSize(1);
  matrix.setTextWrap(false);
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);

  
}

// メインループ
void loop() {
  
  //テキスト１の表示
  for (int8_t x=16; x>= scroll1; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(VIEW_TEXT1);
    matrix.writeDisplay();
    delay(100);
  }

  // テキスト２の表示
  for (int8_t x=16; x>= scroll2; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(VIEW_TEXT2);
    matrix.writeDisplay();
    delay(100);
  }

}