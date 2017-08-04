/*
* LED Cube pattern
* 2017/02/26
*/


/*------------------------------------------------------------------------
*         defined
------------------------------------------------------------------------*/
#define LED_INTERVAL 200    //点滅インターバル

/*------------------------------------------------------------------------
*         variable
------------------------------------------------------------------------*/
unsigned long signal = 0;
unsigned long time1 = millis();
unsigned long time2 = time1;
int col = 4;
int shift = 0;


/*------------------------------------------------------------------------
*         function
------------------------------------------------------------------------*/

void ledTest(int led_num){
  Led_ON(led_num);
  delay(1);
}


/*----------------------------------------
* ランダムに一つ点灯させる
----------------------------------------*/
void once_romdom(){
  int led = 0;

  //光らすLEDの選定
  led = random(0,64);

  //LEDの点滅  
  for(int i = 0; i < LED_INTERVAL; i++){
    Led_ON(led);
    delay(1);
  }

}

/*----------------------------------------
* ランダムに8つ点灯させる
----------------------------------------*/
 void eight(){
  int led[8] = {0,0,0,0,0,0,0,0};

  //光らすLEDの選定
  for(int i = 0; i < 8; i++){
    led[i] = random(0,64);  
  }
  
  //LEDの点滅  
  for(int i = 0; i < LED_INTERVAL; i++){
    for(int j = 0; j < 8; j++)
      Led_ON(led[j]);
    delay(1);
  }

}

/*----------------------------------------
* 箱型に点灯させる
----------------------------------------*/
void cube_edge(){
  int edge[4] = {0,3,12,15};
  int edge2[16] = {1,2,4,7,8,11,13,14,49,50,52,55,56,59,61,62};

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      Led_ON(edge[j] + i * 16);
    }
  }
  for(int i = 0; i < 16; i++){
    Led_ON(edge2[i]);
  }
  delay(1);
}


/*----------------------------------------
* 左右方向に往復させる
----------------------------------------*/
// void slide()
// {
//   static bool reverse = false;
  
//   for(int layer = 0; layer < 4; layer++)
//   {
//     LayerSwitch(layer);
//     for( int i = shift; i <  col; i++ )
//     {
//       digitalWrite(LATCHPIN, LOW);    // 送信中はLATCHPINをLOWに
  
//       // シフト演算を使って点灯するLEDを選択
//       MyShiftOut( DATAPIN, CLOCKPIN, 16, 1L << i );

//       digitalWrite(LATCHPIN, HIGH);   // 送信後はLATCHPINをHIGHに戻す

//       delay(1);
//     }
//   }
//   time2 = millis();
//   if((time2 - time1) > 50)
//   {
//     time1 = millis();     //タイム更新
//     if (!reverse)
//     {
//       col += 4;
//       shift += 4;
//       if(col >= 16)
//         reverse = true;
//     }
//     else
//     {
//       col -= 4;
//       shift -= 4;
//       if(col <= 4)
//         reverse = false;
//     }
//   } 
// }


// /*----------------------------------------
// * 上下方向に往復させる
// ----------------------------------------*/
// void updown(){
//   static bool reverse = false;
//   static int layer = 0;
    
//   for( int i = 0; i <  16; i++ )
//   {
//     digitalWrite(LATCHPIN, LOW);                    // 送信中はLATCHPINをLOWに
//     MyShiftOut( DATAPIN, CLOCKPIN, 16, 1L << i );   // シフト演算を使って点灯するLEDを選択
//     digitalWrite(LATCHPIN, HIGH);                   // 送信後はLATCHPINをHIGHに戻す

//     delay(1);
//   }
  
//   time2 = millis();
//   if((time2 - time1) > 50)
//   {
//     time1 = millis();     //タイム更新
//     if (!reverse)
//     {
//       layer ++;
//       if(layer >= 3)
//         reverse = true;
//     }
//     else
//     {
//       layer --;
//       if(layer <= 0)
//         reverse = false;
//     }
//     LayerSwitch(layer);
//   } 
// }

