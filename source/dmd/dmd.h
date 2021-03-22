




#ifndef DMD_H
#define DMD_H

#include <stdint.h>
#include "dmd_cnfg.h"
#include "gpio.h"



//display screen (and subscreen) sizing
#define DMD_PIXELS_ACROSS         32      //pixels across x axis (base 2 size expected)
#define DMD_PIXELS_DOWN           32      //pixels down y axis
#define DMD_BITSPERPIXEL           1      //1 bit per pixel, use more bits to allow for pwm screen brightness control


// Font Indices
#define FONT_LENGTH             0
#define FONT_FIXED_WIDTH        2
#define FONT_HEIGHT             3
#define FONT_FIRST_CHAR         4
#define FONT_CHAR_COUNT         5
#define FONT_WIDTH_TABLE        6


#define TRUE 1
#define FALSE 0


#define GRAPHICS_NORMAL    0
#define GRAPHICS_INVERSE   1
#define GRAPHICS_TOGGLE    2
#define GRAPHICS_OR        3
#define GRAPHICS_NOR       4




#define COLOR_BLACK		0
#define COLOR_RED 		1
#define COLOR_GREEN		2
#define COLOR_BLUE		3
#define COLOR_YELLOW	4
#define COLOR_MAGENTA	5
#define COLOR_CYAN		6
#define COLOR_WHITE		7


typedef void * DmdHandle;

typedef struct
{
	uint16_t screen[32][192];
	//uint16_t screen[16][192];
	uint32_t DisplaysWide;
	uint32_t DisplaysHigh;
	uint32_t DisplaysTotal;
	uint32_t bChars;
	uint32_t slots;
	//Pointer to current font
	const uint8_t* Font;

	uint32_t screen_height;
	uint32_t screen_length;

	uint32_t byte_counter;
	uint32_t bit_counter;


	uint16_t * port;
	PinHandle connector_oe_pin;
	PinHandle connector_address_a_pin;
	PinHandle connector_address_b_pin;
	PinHandle connector_address_c_pin;
	PinHandle connector_address_d_pin;
	PinHandle connector_strobe_pin;
	PinHandle connector_sck_pin;
}Dmd;


DmdHandle InitDmdModule();
void DrawPic(DmdHandle dmd);
void DrawPattern(DmdHandle dmd, const void * pattern, uint32_t x, uint32_t y);
void ClearScreen(DmdHandle dmd);
void FlushScreen(DmdHandle dmd);
int StringWidth(char * str);
//Set or clear a pixel at the x and y location (0,0 is the top left corner)
void writePixel( DmdHandle handle, unsigned int x, unsigned int y, uint16_t color );

//Draw a string
void drawString( DmdHandle handle, int bX, int bY, const char* bChars, char length, char color);


//Draw a string
void drawStringExtended( DmdHandle handle, const char* bChars, char length);

//Select a text font
void selectFont(DmdHandle handle, const uint8_t* font);

//Draw a single character
int drawChar(DmdHandle handle, const int bX, const int bY, const char letter, char color);

//Find the width of a character
int charWidth(DmdHandle handle, const char letter);

//Draw or clear a line from x1,y1 to x2,y2
void drawLine( DmdHandle handle, int x1, int y1, int x2, int y2, char color );

//Draw or clear a circle of radius r at x,y centre
void drawCircle( DmdHandle handle, int xCenter, int yCenter, int radius, char bGraphicsMode );

//Draw or clear a box(rectangle) with a single pixel border
void drawBox( DmdHandle handle, int x1, int y1, int x2, int y2, char bGraphicsMode );

//Draw or clear a filled box(rectangle) with a single pixel border
void drawFilledBox( DmdHandle handle, int x1, int y1, int x2, int y2, char color );
void drawCircleSub( DmdHandle handle, int cx, int cy, int x, int y, char bGraphicsMode );

uint32_t GetBaseAddress();

#endif //DMD_H
