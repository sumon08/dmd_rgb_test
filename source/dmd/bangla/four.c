#include "pattern.h"
const uint16_t four[] = { 
			 0x0000 ,  0x0000 ,  0x0000 , 
			 0x0000 ,  0x0006 ,  0x0000 , 
			 0x1E00 ,  0x000F ,  0x0000 , 
			 0xBF00 ,  0x001F ,  0x0000 , 
			 0xFB80 ,  0x0019 ,  0x0000 , 
			 0xF180 ,  0x0030 ,  0x0000 , 
			 0xE180 ,  0x0030 ,  0x0000 , 
			 0xE180 ,  0x0030 ,  0x0000 , 
			 0xF380 ,  0x0019 ,  0x0000 , 
			 0xBF00 ,  0x001F ,  0x0000 , 
			 0x0E00 ,  0x000F ,  0x0000 , 
			 0x0000 ,  0x0006 ,  0x0000 , 
			 0x0000 ,  0x0000 ,  0x0000 
			};
const Pattern four_pattern = {
  .height_pixel = 48,
  .length_pixel = 13,
  .pattern_data = four
};			