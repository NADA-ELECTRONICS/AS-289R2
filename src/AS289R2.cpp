#include "Arduino.h"
#include "AS289R2.h"


AS289R2::AS289R2(Stream& s): serial(s)
{

}

size_t AS289R2::write(const char *str)
{
	uint8_t len = strlen(str);
	for(uint8_t i = 0; i < len; i++) {
		if(str[i] == '\n') continue;
		serial.write(str[i]);
  }
	return len;
}

size_t AS289R2::write(const unsigned char c)
{
	if(c == '\n') return 0;
	serial.write(c);
	return 1;
}

void AS289R2::initialize(void)
{
	byte buffer[2] = {0x1B, 0x40};
	serial.write(buffer, 2);
}

void AS289R2::putLineFeed(uint8_t lines)
{
  for (uint8_t i = 0; i < lines; i++) {
    serial.write("\r");
  }
}

void AS289R2::clearBuffer(void)
{
  serial.write(0x18);
}

void AS289R2::setDoubleSizeHeight(void)
{
	byte buffer[3] = {0x1B, 0x4E, 0x31};
	serial.write(buffer, 3);
}

void AS289R2::clearDoubleSizeHeight(void)
{
	byte buffer[3] = {0x1B, 0x4E, 0x30};
	serial.write(buffer, 3);
}

void AS289R2::setDoubleSizeWidth(void)
{
	byte buffer[3] = {0x1B, 0x57, 0x31};
	serial.write(buffer, 3);
}

void AS289R2::clearDoubleSizeWidth(void)
{
	byte buffer[3] = {0x1B, 0x57, 0x30};
	serial.write(buffer, 3);
}

void AS289R2::setLargeFont(void)
{
	byte buffer[3] = {0x1B, 0x4C, 0x31};
	serial.write(buffer, 3);
}

void AS289R2::clearLargeFont()
{
	byte buffer[3] = {0x1B, 0x4C, 0x30};
	serial.write(buffer, 3);
}

void AS289R2::setANKFont(uint8_t font)
{
	byte buffer[3] = {0x1B, 0x68, font};
	serial.write(buffer, 3);
}

void AS289R2::setKanjiFont(uint8_t font)
{
	byte buffer[3] ={0x12, 0x53, font};
	serial.write(buffer, 3);
}

void AS289R2::printQRCode(uint8_t err, const char *param)
{
  uint8_t len = strlen(param);
	byte buffer[4] ={0x1D, 0x78, err, len};
	serial.write(buffer, 4);
    for (uint8_t i = 0; i < len; i++) {
      serial.write(param[i]);
    }
}

void AS289R2::printBarCode(uint8_t code, const char *param)
{
  uint8_t len = strlen(param);
 	byte buffer[3] ={0x1D, 0x6B, code};
	serial.write(buffer, 3);
  for (uint8_t i = 0; i < len; i++) {
    serial.write(param[i]);
  }
  serial.write("\0", 1);
}

void AS289R2::printBitmapImage(uint8_t mode, uint16_t lines)
{
  byte buffer[5] ={0x1C, 0x2A, mode, 0, 0};
  buffer[3] = (lines >> 8) & 0xFF;
  buffer[4] = (lines >> 0) & 0xFF;
  serial.write(buffer, 5);
}

void AS289R2::setLineSpaceing(uint8_t space)
{
	byte buffer[3] ={0x1B, 0x33, space};
	serial.write(buffer, 3);
}

void AS289R2::defaultLineSpaceing()
{
	byte buffer[3] ={0x1B, 0x33, 0x04};
	serial.write(buffer, 3);
}

void AS289R2::setPrintDirection(uint8_t direction)
{
	byte buffer[3] ={0x1B, 0x49, direction};
	serial.write(buffer, 3);
}

void AS289R2::putPaperFeed(uint8_t space)
{
	byte buffer[3] ={0x1B, 0x4A, space};
	serial.write(buffer, 3);
}

void AS289R2::setInterCharacterSpace(uint8_t space)
{
	byte buffer[3] ={0x1B, 0x20, space};
	serial.write(buffer, 3);
}

void AS289R2::defaultInterCharacterSpace()
{
	byte buffer[3] ={0x1B, 0x20, 0x01};
	serial.write(buffer, 3);
}

void AS289R2::putPrintPosition(uint8_t position)
{
	byte buffer[3] ={0x1B, 0x6C, position};
	serial.write(buffer, 3);
}

void AS289R2::setScript(script_mode script)
{
	byte buffer[3] ={0x1B, 0x73, script};
	serial.write(buffer, 3);
}

void AS289R2::clearScript()
{
	byte buffer[3] ={0x1B, 0x73, 0x30};
	serial.write(buffer, 3);
}

void AS289R2::setQuadrupleSize()
{
	byte buffer[3] ={0x1C, 0x57, 0x31};
	serial.write(buffer, 3);
}

void AS289R2::clearQuadrupleSize()
{
	byte buffer[3] ={0x1C, 0x57, 0x30};
	serial.write(buffer, 3);
}

void AS289R2::setEnlargement(uint8_t width, uint8_t height)
{
	byte buffer[4] ={0x1C, 0x65, width, height};
	serial.write(buffer, 4);
}

void AS289R2::clearEnlargement()
{
	byte buffer[4] ={0x1C, 0x65, 0x31, 0x31};
	serial.write(buffer, 4);
}

void AS289R2::setBarCodeHeight(uint8_t height)
{
	byte buffer[3] ={0x1D, 0x68, height};
	serial.write(buffer, 3);
}

void AS289R2::defaultBarCodeHeight()
{
	byte buffer[3] ={0x1D, 0x68, 0x50};
	serial.write(buffer, 3);
}

void AS289R2::setBarCodeBarSize(uint8_t narrowbar, uint8_t widebar)
{
	byte buffer[4] ={0x1D, 0x77, narrowbar, widebar};
	serial.write(buffer, 4);
}

void AS289R2::defaultBarCodeBarSize()
{
	byte buffer[4] ={0x1D, 0x77, 0x02, 0x05};
	serial.write(buffer, 4);
}
