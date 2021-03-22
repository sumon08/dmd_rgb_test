



#include <stddef.h>
#include "font.h"
#include "arial10.h"
#include "arial12.h"
#include "arial13.h"
#include "arial14.h"
#include "arial15.h"
#include "arial16.h"
#include "arial18.h"

char * arial[] = {};

const uint8_t * FindFont(int font_size)
{
	const uint8_t * selected_font = arial16;
	switch (font_size) {
		case 10:
			selected_font = arial11;
			break;
		case 11:
		case 12:
			selected_font = arial12;
			break;
		case 13:
		case 14:
			selected_font = arial14;
			break;
		case 15:
		case 16:
			selected_font = arial16;
			break;
		case 17:
		case 18:
			selected_font = arial18;
			break;
		default:
			break;
	}
	return selected_font;
}
