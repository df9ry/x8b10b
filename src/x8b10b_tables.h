/* Copyright 2017 Tania Hagn.
 *
 * This file is part of x8b10b.
 *
 *    Daisy is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Daisy is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Daisy.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef X8B10B_TABLES_H_
#define X8B10B_TABLES_H_

#include <inttypes.h>

static const uint8_t x5b6b[32] = {
	/*00*/ 0x18, /*01*/ 0x22, /*02*/ 0x12, /*03*/ 0x31,
	/*04*/ 0x0a, /*05*/ 0x29, /*06*/ 0x19, /*07*/ 0x07,
	/*08*/ 0x06, /*09*/ 0x25, /*0a*/ 0x15, /*0b*/ 0x34,
	/*0c*/ 0x0d, /*0d*/ 0x2c, /*0e*/ 0x1c, /*0f*/ 0x28,
	/*10*/ 0x24, /*11*/ 0x23, /*12*/ 0x13, /*13*/ 0x32,
	/*14*/ 0x0b, /*15*/ 0x2a, /*16*/ 0x1a, /*17*/ 0x05,
	/*18*/ 0x0c, /*19*/ 0x26, /*1a*/ 0x16, /*1b*/ 0x09,
	/*1c*/ 0x0e, /*1d*/ 0x11, /*1e*/ 0x21, /*1f*/ 0x14
};

static const uint8_t x3b4b[9] = {
	/*00*/ 0x0b, /*01*/ 0x09, /*02*/ 0x05, /*03*/ 0x0c,
	/*04*/ 0x0d, /*05*/ 0x0a, /*06*/ 0x06, /*07*/ 0x0e,
	/*08*/ 0x07
};

static const uint8_t x6b5b[64] = {
	/*00*/ 0xff, /*01*/ 0xff, /*02*/ 0xff, /*03*/ 0xff,
	/*04*/ 0xff, /*05*/ 0x17, /*06*/ 0x08, /*07*/ 0x07,
	/*08*/ 0xff, /*09*/ 0x1b, /*0a*/ 0x04, /*0b*/ 0x14,
	/*0c*/ 0x18, /*0d*/ 0x0c, /*0e*/ 0x1c, /*0f*/ 0xff,
	/*10*/ 0xff, /*11*/ 0x1d, /*12*/ 0x02, /*13*/ 0x12,
	/*14*/ 0x1f, /*15*/ 0x0a, /*16*/ 0x1a, /*17*/ 0xff,
	/*18*/ 0x00, /*19*/ 0x06, /*1a*/ 0x16, /*1b*/ 0xff,
	/*1c*/ 0x0e, /*1d*/ 0xff, /*1e*/ 0xff, /*1f*/ 0xff,
	/*20*/ 0xff, /*21*/ 0x1e, /*22*/ 0x01, /*23*/ 0x11,
	/*24*/ 0x10, /*25*/ 0x09, /*26*/ 0x19, /*27*/ 0xff,
	/*28*/ 0x0f, /*29*/ 0x05, /*2a*/ 0x15, /*2b*/ 0xff,
	/*2c*/ 0x0d, /*2d*/ 0xff, /*2e*/ 0xff, /*2f*/ 0xff,
	/*30*/ 0xff, /*31*/ 0x03, /*32*/ 0x13, /*33*/ 0xff,
	/*34*/ 0x0b, /*35*/ 0xff, /*36*/ 0xff, /*37*/ 0xff,
	/*38*/ 0xff, /*39*/ 0xff, /*3a*/ 0xff, /*3b*/ 0xff,
	/*3c*/ 0xff, /*3d*/ 0xff, /*3e*/ 0xff, /*3f*/ 0xff
};

static const uint8_t x4b3b[16] = {
	/*00*/ 0xff, /*01*/ 0xff, /*02*/ 0xff, /*03*/ 0xff,
	/*04*/ 0xff, /*05*/ 0x02, /*06*/ 0x06, /*07*/ 0x07,
	/*08*/ 0xff, /*09*/ 0x01, /*0a*/ 0x05, /*0b*/ 0x00,
	/*0c*/ 0x03, /*0d*/ 0x04, /*0e*/ 0x07, /*0f*/ 0x00
};

#endif /* X8B10B_TABLES_H_ */
