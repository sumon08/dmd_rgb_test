

#ifndef PATTERN_H
#define PATTERN_H

#include <stdint.h>





typedef struct
{
	uint32_t height_pixel;
	uint32_t length_pixel;
	const uint16_t * pattern_data;
}Pattern;





uint32_t PatternHeight(const void * pttrn);
uint32_t PatternLength(const void * pttrn);
uint32_t PixelValue(const void * pttrn, uint32_t x, uint32_t y);

Pattern * GetPatternFromToken(uint32_t token);

#endif //PATTERN_H
