#ifndef AS289R2_h
#define AS289R2_h
#include <Arduino.h>

class AS289R2
{
  public:

    enum Kanji_font_size {
        KANJI_24x24 = 0x30,
        KANJI_16x16,
        KANJI_DEFAULT = KANJI_24x24
    };

    enum ANK_font_size {
        ANK_8x16 = 0x30,
        ANK_12x24,
        ANK_16x16,
        ANK_24x24,
        ANK_DEFAULT = ANK_12x24
    };

    enum QRcode_error_level {
        QR_ERR_LVL_L = 0x4C,
        QR_ERR_LVL_M = 0x4D,
        QR_ERR_LVL_Q = 0x51,
        QR_ERR_LVL_H = 0x48
    };

    enum Barcode_mode {
        BCODE_UPC_A = 0x30,
        _UNUSED_,
        BCODE_JAN13,
        BCODE_JAN8,
        BCODE_CODE39,
        BCODE_ITF,
        BCODE_CODABAR
    };

    enum script_mode {
        SCRIPT_CANCEL = 0,
        SCRIPT_SUPER,
        SCRIPT_SUB
    };

    AS289R2(Stream& s);
    void print(const char* text);
	void write(const unsigned char c);
	// Initialize
    void initialize(void);
	// Line feed
    void putLineFeed(uint8_t lines);
    // Clear data
	void clearBuffer(void);
	// Apply double-height printing
    void setDoubleSizeHeight(void);
    // Cancel double-height printing
    void clearDoubleSizeHeight(void);
    // Apply double-width printing
    void setDoubleSizeWidth(void);
    // Cancel double-width printing
    void clearDoubleSizeWidth(void);
    // Apply LargeFont
    void setLargeFont(void);
    // Cancel LargeFont
    void clearLargeFont(void);
    // Specify ANK character font
    void setANKFont(uint8_t font);
    // Specify Kanji font
    void setKanjiFont(uint8_t font);
    // Print QR Barcode
    void printQRCode(uint8_t err, const char* param);
    // Print Barcode
    void printBarCode(uint8_t code, const char* param);
    // Print Bitmap image
    void printBitmapImage(uint8_t mode, uint16_t lines);
	// Specify line spacing
    void setLineSpaceing(uint8_t space);
 	// Default line spacing
    void defaultLineSpaceing(void);
    // Specify print direction
    void setPrintDirection(uint8_t direction);
    // Default print direction
	void putPaperFeed(uint8_t space);
	// Specify inter-character space
	void setInterCharacterSpace(uint8_t space);
	// Default inter-character space
	void defaultInterCharacterSpace();
	// Move print position
	void putPrintPosition(uint8_t position);
	// Apply script
	void setScript(script_mode script);
	// Cancel script
	void clearScript();
	// Apply quadruple size printing
	void setQuadrupleSize();
	// Cancel quadruple size printing
	void clearQuadrupleSize();
	// Specify width-height enlargement ratio
	void setEnlargement(uint8_t width, uint8_t height);
	// Clear enlargement ratio
	void clearEnlargement();
	// Clear enlargement ratio
	void setBarCodeHeight(uint8_t height);
	// Specifying barcode height
	void defaultBarCodeHeight();
	// Specify Barcodebar size
	void setBarCodeBarSize(uint8_t narrowbar, uint8_t widebar);
	// Default Barcodebar size
	void defaultBarCodeBarSize();

  private:
    Stream& serial;
};
#endif
