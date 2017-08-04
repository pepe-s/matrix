/*************************************************************************
* Matrix LED 
* 2017/07/28
* Teppei
*************************************************************************/


/*------------------------------------------------------------------------
*         definition
------------------------------------------------------------------------*/
#define DATAPIN 9     // 74HC595のDSへ
#define LATCHPIN 12   // 74HC595のST_CPへ
#define CLOCKPIN 11   // 74HC595のSH_CPへ

/*------------------------------------------------------------------------
*         variable
------------------------------------------------------------------------*/


/*------------------------------------------------------------------------
*         function
------------------------------------------------------------------------*/

/*----------------------------------------
* シフトレジスタに出力する
----------------------------------------*/
void MyShiftOut( int dataPin, int clockPin, int bit, unsigned long val, bool rev)
{
  for( int i = 0; i < bit; i++ )
  {
    if(rev)
      digitalWrite(dataPin, !(val & (1L << i)));  //反転
    else
      digitalWrite(dataPin, !!(val & (1L << i)));

    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
  }
}

/*----------------------------------------
* 指定した番号のLEDを点灯させる
----------------------------------------*/
void Led_ON(int num){
  unsigned long row = 0;
  unsigned long col = 0;

  //アノードのピンを算出
  col = num / 8;
  row = num % 8 ;
  
  // シフト演算を使って点灯するLEDを選択
  digitalWrite(LATCHPIN, LOW);    // 送信中はLATCHPINをLOW
  MyShiftOut(DATAPIN, CLOCKPIN, 8, 1L << col, true);  //列を送信
  MyShiftOut(DATAPIN, CLOCKPIN, 8, 1L << row, false);  //行を送信
  digitalWrite(LATCHPIN, HIGH);   // 送信後はLATCHPINをHIGHに戻す
}

/*------------------------------------------------------------------------
*         main
------------------------------------------------------------------------*/

/*----------------------------------------
* setup
----------------------------------------*/
void setup()
{
  pinMode(DATAPIN, OUTPUT);
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
}

/*----------------------------------------
* loop
----------------------------------------*/
void loop()
{
  for(int i=1; i<64; i++){
    ledTest(i);
    delay(50);
  }
  
}


