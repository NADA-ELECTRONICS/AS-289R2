/* Sample program
   AS-289R2 Thermal Printer Shield
   NADA ELECTRONICS, LTD.
   Copyright (c) 2017 Takehiro Yamaguchi, MIT License

   Permission is hereby granted, free of charge, to any person obtaining a copy of this software
   and associated documentation files (the "Software"), to deal in the Software without restriction,
   including without limitation the rights to use, copy, modify, merge, publish, distribute,
   sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
   BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <avr/pgmspace.h>
#include <AS289R2.h>
#include "image.h"  // MonochromeBitmap to cpp : http://www.nada.co.jp/as289r2/en/ex_bitmap.html

#define LED_PIN 13

// Constructor
// Hardwear Serial
// Arduino UNO : Serial
// Arduino/Genuino 101 : Serial1
AS289R2 tp(Serial);

void AS289R2_demo()
{
  /* initialize */
  tp.initialize();

  tp.putLineFeed(2);

  /* Print Text Message */
  tp.print("Thermal Printer Shield\r");
  tp.print("Model:AS-289R2\r");

  tp.putLineFeed(2);

  /* Change ANK Font size */
  tp.setANKFont(AS289R2::ANK_8x16);
  tp.print("Font8x16\rABCDEF012345ｱｲｳｴｵ\r\r");
  tp.setANKFont(AS289R2::ANK_16x16);
  tp.print("Font16x16\rABCDEF012345ｱｲｳｴｵ\r\r");
  tp.setANKFont(AS289R2::ANK_12x24);
  tp.print("Font12x24\rABCDEF012345ｱｲｳｴｵ\r\r");
  tp.setANKFont(AS289R2::ANK_24x24);
  tp.print("Font24x24\rABCDEF012345ｱｲｳｴｵ\r\r");

  tp.putLineFeed(2);

  /* Change font width and height */
  tp.setANKFont(AS289R2::ANK_12x24);
  tp.print("AS-289R2\r");
  tp.setDoubleSizeWidth();
  tp.print("AS-289R2\r");
  tp.clearDoubleSizeWidth();
  tp.setDoubleSizeHeight();
  tp.print("AS-289R2\r");
  tp.clearDoubleSizeHeight();
  tp.setQuadrupleSize();
  tp.print("AS-289R2\r");
  tp.clearQuadrupleSize();
  tp.setEnlargement(3, 3);
  tp.print("AS-289R2\r");
  tp.clearEnlargement();

  tp.putLineFeed(2);

  /* Print KANJI HIRAGANA KATAKANA */
  tp.setANKFont(AS289R2::ANK_8x16);
  tp.setKanjiFont(AS289R2::KANJI_16x16);
  tp.print("Japanese\r");
  tp.print("16x16: 漢字ひらがなカタカナ\r");
  tp.setANKFont(AS289R2::ANK_12x24);
  tp.setKanjiFont(AS289R2::KANJI_24x24);
  tp.print("24x24: 漢字ひらがなカタカナ\r");

  tp.putLineFeed(2);

  /* Barcode */
  tp.print("Barcode UPC-A\r");
  tp.printBarCode(AS289R2::BCODE_UPC_A, "12345678901");
  tp.print("Barcode JAN13\r");
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
  tp.print("Barcode JAN8\r");
  tp.printBarCode(AS289R2::BCODE_JAN8, "1234567");
  tp.print("Barcode CODE39\r");
  tp.printBarCode(AS289R2::BCODE_CODE39, "123456");
  tp.print("Barcode ITF\r");
  tp.printBarCode(AS289R2::BCODE_ITF, "01234567890123");
  tp.print("Barcode CODABAR(NW7)\r");
  tp.printBarCode(AS289R2::BCODE_CODABAR, "A0123456789A");

  tp.putLineFeed(2);

  /* Barcode height */
  tp.print("Barcode height\r");
  tp.setBarCodeHeight(10);
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
  tp.setBarCodeHeight(20);
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
  tp.setBarCodeHeight(30);
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
  tp.defaultBarCodeHeight();
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");

  tp.putLineFeed(2);

  /* Barcode-bar size */
  tp.print("Barcode bar size\r");
  tp.setBarCodeBarSize(3, 5);
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
  tp.defaultBarCodeBarSize();
  tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");

  tp.putLineFeed(2);

  /* QR code */
  char url[] = "https://www.nada.co.jp/as289r2/";
  tp.printQRCode(AS289R2::QR_ERR_LVL_M, url);
  tp.print("\r");
  //tp.printf(url);

  tp.putLineFeed(2);

  /* Image : The city of Kobe Japan */
  int lines = sample_image_len / 48;
  tp.printBitmapImage(0x63, lines);
  byte myImage;
  for (uint16_t i = 0; i < (48 * lines); i++) {
    myImage = pgm_read_byte_near(&sample_image[i]);
    tp.write(myImage);
  }

  tp.putLineFeed(2);

  /* Print Direction */
  tp.setPrintDirection(1);    // Prints from the bottom
  tp.print("test\r");
  tp.setPrintDirection(0);    // Prints from the top
  tp.print("test\r");

  tp.putLineFeed(2);

  /* Inter-Character Spacing */
  tp.setInterCharacterSpace(0);
  tp.print("test\r");
  tp.setInterCharacterSpace(3);
  tp.print("test\r");
  tp.setInterCharacterSpace(6);
  tp.print("test\r");
  tp.setInterCharacterSpace(9);
  tp.print("test\r");
  tp.defaultInterCharacterSpace();

  tp.putLineFeed(2);

  /* Line and Character Spacing */
  tp.setLineSpaceing(0);
  tp.print("test\r");
  tp.setLineSpaceing(5);
  tp.print("test\r");
  tp.setLineSpaceing(10);
  tp.print("test\r");
  tp.setLineSpaceing(15);
  tp.print("test\r");
  tp.defaultLineSpaceing();

  tp.putLineFeed(2);

  /* Print Position */
  tp.putPrintPosition(10);
  tp.print("test\r");
  tp.putPrintPosition(15);
  tp.print("test\r");
  tp.putPrintPosition(20);
  tp.print("test\r");

  tp.putLineFeed(2);

  /* Superscript */
  tp.print("1cm");
  tp.setScript(1);
  tp.print("3");
  tp.print("\r");
  tp.clearScript();

  /* Subscript */
  tp.print("H");
  tp.setScript(2);
  tp.print("2");
  tp.clearScript();
  tp.print("O\r");

  /* PaperFeed */
  tp.putPaperFeed(200);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  AS289R2_demo();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
