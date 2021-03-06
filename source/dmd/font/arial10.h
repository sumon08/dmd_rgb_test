

/*
 *
 * arial11
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : arial11
 * Date                : 11.05.2017
 * Font size in bytes  : 4512
 * Font width          : 10
 * Font height         : 10
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>

#ifndef ARIAL11_H
#define ARIAL11_H

#define ARIAL11_WIDTH 10
#define ARIAL11_HEIGHT 10

static const uint8_t arial11[] = {
		0x0D, 0xAE, // size
		    0x0A, // width
		    0x0A, // height
		    0x20, // first char
		    0x60, // char count

		    // char widths
		    0x00, 0x01, 0x03, 0x05, 0x05, 0x07, 0x05, 0x01, 0x02, 0x02,
		    0x03, 0x04, 0x02, 0x02, 0x01, 0x02, 0x04, 0x02, 0x04, 0x04,
		    0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 0x01, 0x04, 0x04,
		    0x04, 0x04, 0x07, 0x05, 0x04, 0x05, 0x05, 0x04, 0x04, 0x05,
		    0x05, 0x01, 0x03, 0x04, 0x04, 0x05, 0x05, 0x05, 0x04, 0x05,
		    0x05, 0x04, 0x05, 0x05, 0x05, 0x07, 0x05, 0x05, 0x04, 0x02,
		    0x02, 0x01, 0x03, 0x05, 0x01, 0x04, 0x04, 0x03, 0x04, 0x04,
		    0x02, 0x04, 0x04, 0x01, 0x01, 0x03, 0x01, 0x05, 0x04, 0x04,
		    0x04, 0x04, 0x03, 0x03, 0x02, 0x04, 0x03, 0x05, 0x04, 0x03,
		    0x03, 0x03, 0x01, 0x03, 0x04, 0x02,

		    // font data
		    0xBE, 0x00, // 33
		    0x0E, 0x00, 0x0E, 0x00, 0x00, 0x00, // 34
		    0xF8, 0x2E, 0xF8, 0x2E, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
		    0x4C, 0x92, 0xFF, 0x92, 0x64, 0x00, 0x00, 0x40, 0x00, 0x00, // 36
		    0x0C, 0x12, 0xCC, 0x30, 0x6C, 0x92, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 37
		    0x60, 0xAC, 0x92, 0x6C, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, // 38
		    0x0E, 0x00, // 39
		    0xFC, 0x02, 0x40, 0x80, // 40
		    0x02, 0xFC, 0x80, 0x40, // 41
		    0x14, 0x0E, 0x14, 0x00, 0x00, 0x00, // 42
		    0x10, 0x7C, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, // 43
		    0x80, 0x80, 0x40, 0x40, // 44
		    0x20, 0x20, 0x00, 0x00, // 45
		    0x80, 0x00, // 46
		    0xE0, 0x1E, 0x00, 0x00, // 47
		    0x7C, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00, 0x00, // 48
		    0x04, 0xFE, 0x00, 0x00, // 49
		    0xC6, 0xA2, 0x92, 0x8E, 0x00, 0x00, 0x00, 0x00, // 50
		    0xC6, 0x92, 0x92, 0xEE, 0x00, 0x00, 0x00, 0x00, // 51
		    0x30, 0x28, 0x24, 0xFE, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // 52
		    0x4C, 0x8A, 0x8A, 0x72, 0x00, 0x00, 0x00, 0x00, // 53
		    0x7C, 0x92, 0x92, 0x62, 0x00, 0x00, 0x00, 0x00, // 54
		    0x02, 0xE2, 0x1A, 0x06, 0x00, 0x00, 0x00, 0x00, // 55
		    0x6C, 0x92, 0x92, 0x6C, 0x00, 0x00, 0x00, 0x00, // 56
		    0x8C, 0x92, 0x92, 0x7C, 0x00, 0x00, 0x00, 0x00, // 57
		    0x88, 0x00, // 58
		    0x88, 0x40, // 59
		    0x10, 0x28, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, // 60
		    0x28, 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, // 61
		    0x44, 0x28, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00, // 62
		    0x04, 0xA2, 0x12, 0x0C, 0x00, 0x00, 0x00, 0x00, // 63
		    0xF8, 0x04, 0x72, 0x8A, 0xFA, 0x84, 0x78, 0x00, 0x40, 0x80, 0x80, 0x80, 0x80, 0x40, // 64
		    0xFC, 0x22, 0x22, 0x22, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, // 65
		    0xFE, 0x92, 0x92, 0xEE, 0x00, 0x00, 0x00, 0x00, // 66
		    0x7C, 0x82, 0x82, 0x82, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, // 67
		    0xFE, 0x82, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, // 68
		    0xFE, 0x92, 0x92, 0x92, 0x00, 0x00, 0x00, 0x00, // 69
		    0xFE, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, // 70
		    0x7C, 0x82, 0x82, 0x92, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00, // 71
		    0xFE, 0x10, 0x10, 0x10, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, // 72
		    0xFE, 0x00, // 73
		    0x40, 0x80, 0x7E, 0x00, 0x00, 0x00, // 74
		    0xFE, 0x18, 0x64, 0x82, 0x00, 0x00, 0x00, 0x00, // 75
		    0xFE, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, // 76
		    0xFE, 0x3C, 0x40, 0x3C, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, // 77
		    0xFE, 0x0E, 0x38, 0xE0, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, // 78
		    0x7C, 0x82, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, // 79
		    0xFE, 0x12, 0x12, 0x0C, 0x00, 0x00, 0x00, 0x00, // 80
		    0x7C, 0x82, 0xA2, 0x42, 0xBC, 0x00, 0x00, 0x00, 0x00, 0x00, // 81
		    0xFE, 0x12, 0x32, 0x52, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, // 82
		    0x4C, 0x92, 0x92, 0x64, 0x00, 0x00, 0x00, 0x00, // 83
		    0x02, 0x02, 0xFE, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
		    0x7E, 0x80, 0x80, 0x80, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, // 85
		    0x0E, 0x78, 0x80, 0x78, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
		    0x7E, 0x80, 0x7C, 0x02, 0x7C, 0x80, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 87
		    0x82, 0x6C, 0x10, 0x6C, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, // 88
		    0x02, 0x0C, 0xF0, 0x0C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
		    0xC2, 0xB2, 0x8A, 0x86, 0x00, 0x00, 0x00, 0x00, // 90
		    0xFE, 0x02, 0xC0, 0x80, // 91
		    0x0E, 0xF0, 0x00, 0x00, // 92
		    0xFE, 0xC0, // 93
		    0x1C, 0x02, 0x1C, 0x00, 0x00, 0x00, // 94
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // 95
		    0x03, 0x00, // 96
		    0xE8, 0xA8, 0xA8, 0xF0, 0x00, 0x00, 0x00, 0x00, // 97
		    0xFE, 0x50, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, // 98
		    0x70, 0x88, 0xD0, 0x00, 0x00, 0x00, // 99
		    0x70, 0x88, 0x50, 0xFE, 0x00, 0x00, 0x00, 0x00, // 100
		    0x70, 0xA8, 0xA8, 0xB0, 0x00, 0x00, 0x00, 0x00, // 101
		    0xFE, 0x0A, 0x00, 0x00, // 102
		    0x70, 0x88, 0x50, 0xF8, 0x80, 0x80, 0x80, 0x40, // 103
		    0xFE, 0x10, 0x08, 0xF0, 0x00, 0x00, 0x00, 0x00, // 104
		    0xFA, 0x00, // 105
		    0xFA, 0xC0, // 106
		    0xFE, 0x30, 0xC8, 0x00, 0x00, 0x00, // 107
		    0xFE, 0x00, // 108
		    0xF8, 0x08, 0xF8, 0x08, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, // 109
		    0xF8, 0x10, 0x08, 0xF0, 0x00, 0x00, 0x00, 0x00, // 110
		    0x70, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, // 111
		    0xF8, 0x50, 0x88, 0x70, 0xC0, 0x00, 0x00, 0x00, // 112
		    0x70, 0x88, 0x50, 0xF8, 0x00, 0x00, 0x00, 0xC0, // 113
		    0xF8, 0x10, 0x08, 0x00, 0x00, 0x00, // 114
		    0x90, 0xA8, 0x68, 0x00, 0x00, 0x00, // 115
		    0xFE, 0x88, 0x00, 0x00, // 116
		    0x78, 0x80, 0x40, 0xF8, 0x00, 0x00, 0x00, 0x00, // 117
		    0x78, 0x80, 0x78, 0x00, 0x00, 0x00, // 118
		    0x78, 0x80, 0x78, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, // 119
		    0x88, 0x70, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, // 120
		    0x18, 0xE0, 0x18, 0x80, 0x40, 0x00, // 121
		    0xC8, 0xA8, 0x98, 0x00, 0x00, 0x00, // 122
		    0x20, 0xDC, 0x02, 0x00, 0x40, 0x80, // 123
		    0xFE, 0xC0, // 124
		    0x02, 0xDC, 0x20, 0x80, 0x40, 0x00, // 125
		    0x10, 0x08, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, // 126
		    0xFC, 0xFC, 0x00, 0x00 // 127
};

#endif
