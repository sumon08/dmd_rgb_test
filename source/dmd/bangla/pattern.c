


#include <stddef.h>
#include "pattern.h"


uint32_t PatternHeight(const void * pttrn)
{
	Pattern * pattern = (Pattern * )pttrn;
	return pattern->height_pixel;
}


uint32_t PatternLength(const void * pttrn)
{
	Pattern * pattern = (Pattern * )pttrn;
	return pattern->length_pixel;
}

uint32_t PixelValue(const void * pttrn, uint32_t x, uint32_t y)
{
	Pattern * pattern = (Pattern * )pttrn;
	if (x > pattern->length_pixel || y > pattern->height_pixel) {
		return 0;
	}

	uint32_t bit_offset = y % 16;
	uint32_t byte_offset = y / 16;

	uint32_t byte_position = x*3+byte_offset;

	return pattern->pattern_data[byte_position] & 1 << bit_offset;
}

extern Pattern eight_pattern;
extern Pattern five_pattern;
extern Pattern four_pattern;
extern Pattern hazar_pattern;
extern Pattern koti_pattern;
extern Pattern lokkho_pattern;
extern Pattern nine_pattern;
extern Pattern one_pattern;
extern Pattern seven_pattern;
extern Pattern six_pattern;
extern Pattern taka_pattern;
extern Pattern three_pattern;
extern Pattern ti_pattern;
extern Pattern two_pattern;
extern Pattern zero_pattern;
extern Pattern space_pattern;
extern Pattern no_pattern;
extern Pattern shoto_pattern;
extern Pattern koma_pattern;

Pattern * GetPatternFromToken(uint32_t token)
{
	Pattern * ret = NULL;
	switch(token)
	{
	case 0:
		ret = &zero_pattern;
		break;
	case 1:
		ret = &one_pattern;
		break;
	case 2:
		ret = &two_pattern;
		break;
	case 3:
		ret = &three_pattern;
		break;
	case 4:
		ret = &four_pattern;
		break;
	case 5:
		ret = &five_pattern;
		break;
	case 6:
		ret = &six_pattern;
		break;
	case 7:
		ret = &seven_pattern;
		break;
	case 8:
		ret = &eight_pattern;
		break;
	case 9:
		ret = &nine_pattern;
		break;
	case 10:
		ret = &hazar_pattern;
		break;
	case 11:
		ret = &lokkho_pattern;
		break;
	case 12:
		ret = &koti_pattern;
		break;
	case 13:
		ret = &taka_pattern;
		break;
	case 14:
		ret = &ti_pattern;
		break;
	case 15:
		ret = &space_pattern;
		break;
	case 16:
		ret = &shoto_pattern;
		break;
	case 17:
		ret = &koma_pattern;
		break;
	default:
		ret = &no_pattern;
		break;
	}
	return ret;
}
