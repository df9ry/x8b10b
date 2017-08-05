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

const uint8_t b5b6_1[32] = {
 /*D.00:+2N*/ 0xe7, /*D.01:+2N*/ 0xdd, /*D.02:+2N*/ 0xed, /*D.03:   */ 0x31,
 /*D.04:+2N*/ 0xf5, /*D.05:   */ 0x29, /*D.06:   */ 0x19, /*D.07:  N*/ 0xb8,
 /*D.08:+2N*/ 0xf9, /*D.09:   */ 0x25, /*D.10:   */ 0x15, /*D.11:   */ 0x34,
 /*D.12:   */ 0x0d, /*D.13:   */ 0x2c, /*D.14:   */ 0x1c, /*D.15:+2N*/ 0xd7,
 /*D.16:+2N*/ 0xdb, /*D.17:   */ 0x23, /*D.18:   */ 0x13, /*D.19:   */ 0x32,
 /*D.20:   */ 0x0b, /*D.21:   */ 0x2a, /*D.22:   */ 0x1a, /*D.23:+2N*/ 0xfa,
 /*D.24:+2N*/ 0xf3, /*D.25:   */ 0x26, /*D.26:   */ 0x16, /*D.27:+2N*/ 0xf6,
 /*D.28:   */ 0x0e, /*D.29:+2N*/ 0xee, /*D.30:+2N*/ 0xde, /*D.31:+2N*/ 0xeb,
};

const uint8_t b6b5_1[64] = {
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*D.20:   */ 0x14,
 /*NOTM:   */ 0xff, /*D.12:   */ 0x0c, /*D.28:   */ 0x1c, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*D.18:   */ 0x12,
 /*NOTM:   */ 0xff, /*D.10:   */ 0x0a, /*D.26:   */ 0x1a, /*D.15:+2N*/ 0xcf,
 /*NOTM:   */ 0xff, /*D.06:   */ 0x06, /*D.22:   */ 0x16, /*D.16:+2N*/ 0xd0,
 /*D.14:   */ 0x0e, /*D.01:+2N*/ 0xc1, /*D.30:+2N*/ 0xde, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*D.17:   */ 0x11,
 /*NOTM:   */ 0xff, /*D.09:   */ 0x09, /*D.25:   */ 0x19, /*D.00:+2N*/ 0xc0,
 /*NOTM:   */ 0xff, /*D.05:   */ 0x05, /*D.21:   */ 0x15, /*D.31:+2N*/ 0xdf,
 /*D.13:   */ 0x0d, /*D.02:+2N*/ 0xc2, /*D.29:+2N*/ 0xdd, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*D.03:   */ 0x03, /*D.19:   */ 0x13, /*D.24:+2N*/ 0xd8,
 /*D.11:   */ 0x0b, /*D.04:+2N*/ 0xc4, /*D.27:+2N*/ 0xdb, /*NOTM:   */ 0xff,
 /*D.07:  N*/ 0x87, /*D.08:+2N*/ 0xc8, /*D.23:+2N*/ 0xd7, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
};

const uint8_t b3b4_1[9] = {
 /*D.x.0 :+2N*/ 0xcb, /*D.x.1 :   */ 0x09, /*D.x.2 :   */ 0x05, /*D.x.3 :  N*/ 0x8c,
 /*D.x.4 :+2N*/ 0xcd, /*D.x.5 :   */ 0x0a, /*D.x.6 :   */ 0x06, /*D.x.P7:+2N*/ 0xce,
 /*D.x.A7:+2N*/ 0xc7,
};

const uint8_t b4b3_1[16] = {
 /*NOTMAP:   */ 0xff, /*NOTMAP:   */ 0xff, /*NOTMAP:   */ 0xff, /*NOTMAP:   */ 0xff,
 /*NOTMAP:   */ 0xff, /*D.x.2 :   */ 0x02, /*D.x.6 :   */ 0x06, /*D.x.A7:+2N*/ 0xc7,
 /*NOTMAP:   */ 0xff, /*D.x.1 :   */ 0x01, /*D.x.5 :   */ 0x05, /*D.x.0 :+2N*/ 0xc0,
 /*D.x.3 :  N*/ 0x83, /*D.x.4 :+2N*/ 0xc4, /*D.x.P7:+2N*/ 0xc7, /*NOTMAP:   */ 0xff,
};

const uint8_t b5b6_2[32] = {
 /*D.00:-2N*/ 0xd8, /*D.01:-2N*/ 0xe2, /*D.02:-2N*/ 0xd2, /*D.03:   */ 0x31,
 /*D.04:-2N*/ 0xca, /*D.05:   */ 0x29, /*D.06:   */ 0x19, /*D.07:  N*/ 0x87,
 /*D.08:-2N*/ 0xc6, /*D.09:   */ 0x25, /*D.10:   */ 0x15, /*D.11:   */ 0x34,
 /*D.12:   */ 0x0d, /*D.13:   */ 0x2c, /*D.14:   */ 0x1c, /*D.15:-2N*/ 0xe8,
 /*D.16:-2N*/ 0xe4, /*D.17:   */ 0x23, /*D.18:   */ 0x13, /*D.19:   */ 0x32,
 /*D.20:   */ 0x0b, /*D.21:   */ 0x2a, /*D.22:   */ 0x1a, /*D.23:-2N*/ 0xc5,
 /*D.24:-2N*/ 0xcc, /*D.25:   */ 0x26, /*D.26:   */ 0x16, /*D.27:-2N*/ 0xc9,
 /*D.28:   */ 0x0e, /*D.29:-2N*/ 0xd1, /*D.30:-2N*/ 0xe1, /*D.31:-2N*/ 0xd4,
};

const uint8_t b6b5_2[64] = {
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*D.23:-2N*/ 0xd7, /*D.08:-2N*/ 0xc8, /*D.07:  N*/ 0x87,
 /*NOTM:   */ 0xff, /*D.27:-2N*/ 0xdb, /*D.04:-2N*/ 0xc4, /*D.20:   */ 0x14,
 /*D.24:-2N*/ 0xd8, /*D.12:   */ 0x0c, /*D.28:   */ 0x1c, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*D.29:-2N*/ 0xdd, /*D.02:-2N*/ 0xc2, /*D.18:   */ 0x12,
 /*D.31:-2N*/ 0xdf, /*D.10:   */ 0x0a, /*D.26:   */ 0x1a, /*NOTM:   */ 0xff,
 /*D.00:-2N*/ 0xc0, /*D.06:   */ 0x06, /*D.22:   */ 0x16, /*NOTM:   */ 0xff,
 /*D.14:   */ 0x0e, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*D.30:-2N*/ 0xde, /*D.01:-2N*/ 0xc1, /*D.17:   */ 0x11,
 /*D.16:-2N*/ 0xd0, /*D.09:   */ 0x09, /*D.25:   */ 0x19, /*NOTM:   */ 0xff,
 /*D.15:-2N*/ 0xcf, /*D.05:   */ 0x05, /*D.21:   */ 0x15, /*NOTM:   */ 0xff,
 /*D.13:   */ 0x0d, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*D.03:   */ 0x03, /*D.19:   */ 0x13, /*NOTM:   */ 0xff,
 /*D.11:   */ 0x0b, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
 /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff, /*NOTM:   */ 0xff,
};

const uint8_t b3b4_2[9] = {
 /*D.x.0 :-2N*/ 0xc4, /*D.x.1 :   */ 0x09, /*D.x.2 :   */ 0x05, /*D.x.3 :  N*/ 0x83,
 /*D.x.4 :-2N*/ 0xc2, /*D.x.5 :   */ 0x0a, /*D.x.6 :   */ 0x06, /*D.x.P7:-2N*/ 0xc1,
 /*D.x.A7:-2N*/ 0xc8,
};

const uint8_t b4b3_2[16] = {
 /*NOTMAP:   */ 0xff, /*D.x.P7:-2N*/ 0xc7, /*D.x.4 :-2N*/ 0xc4, /*D.x.3 :  N*/ 0x83,
 /*D.x.0 :-2N*/ 0xc0, /*D.x.2 :   */ 0x02, /*D.x.6 :   */ 0x06, /*NOTMAP:   */ 0xff,
 /*D.x.A7:-2N*/ 0xc7, /*D.x.1 :   */ 0x01, /*D.x.5 :   */ 0x05, /*NOTMAP:   */ 0xff,
 /*NOTMAP:   */ 0xff, /*NOTMAP:   */ 0xff, /*NOTMAP:   */ 0xff, /*NOTMAP:   */ 0xff,
};

#endif /* X8B10B_TABLES_H_ */
