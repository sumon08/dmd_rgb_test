#include "pattern.h"
const uint16_t zero[] = { 
			 0x0000 ,  0x0000 ,  0x0000 , 
			 0xF000 ,  0x0003 ,  0x0000 , 
			 0xF800 ,  0x000F ,  0x0000 , 
			 0x1C00 ,  0x000C ,  0x0000 , 
			 0x0E00 ,  0x0018 ,  0x0000 , 
			 0x0600 ,  0x0018 ,  0x0000 , 
			 0x0600 ,  0x0018 ,  0x0000 , 
			 0x0600 ,  0x000C ,  0x0000 , 
			 0x0C00 ,  0x000E ,  0x0000 , 
			 0xFC00 ,  0x0007 ,  0x0000 , 
			 0xF800 ,  0x0003 ,  0x0000 , 
			 0x0000 ,  0x0000 ,  0x0000  
			};
const Pattern zero_pattern = {
  .height_pixel = 48,
  .length_pixel = 12,
  .pattern_data = zero
};			