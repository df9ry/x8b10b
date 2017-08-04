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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dump.h"

static const char hex[] = "0123456789abcdef";

void dump_hex(FILE *file, const uint8_t *pb, uint32_t cb) {
	char mask[] =
		"XXXX XXXX: XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX [XXXXXXXXXXXXXXXX]\n";

	uint64_t addr = 0;
	while (addr < cb) {
		{
			uint32_t x = addr;
			mask[8] = hex[x & 0x0f]; x >>= 4;
			mask[7] = hex[x & 0x0f]; x >>= 4;
			mask[6] = hex[x & 0x0f]; x >>= 4;
			mask[5] = hex[x & 0x0f]; x >>= 4;
			mask[3] = hex[x & 0x0f]; x >>= 4;
			mask[2] = hex[x & 0x0f]; x >>= 4;
			mask[1] = hex[x & 0x0f]; x >>= 4;
			mask[0] = hex[x & 0x0f];
		}

		for (int i = 0; i < 16; ++i) {
			uint32_t j = 11 + 3 * i;
			if (addr + i < cb) {
				uint8_t x = pb[addr+i];
				mask[j] = hex[x/16]; mask[j+1] = hex[x%16];
				mask[i+60] = isprint((char)x) ? (char)x : '.';
			} else {
				mask[j] = mask[j+1] = mask[i+60] = ' ';
			}
		} // end for //
		fprintf(file, "%s", mask);
		addr += 16;
	} // end while //
}

void dump_bin(FILE *file, const uint8_t *pb, uint32_t cb, int msb) {
	char mask[] =
		"XXXX: XXXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX\n";

	uint32_t addr = 0;
	while (addr < cb) {
		{
			uint32_t x = addr & 0x0000ffff;
			mask[3] = hex[x & 0x0f]; x >>= 4;
			mask[2] = hex[x & 0x0f]; x >>= 4;
			mask[1] = hex[x & 0x0f]; x >>= 4;
			mask[0] = hex[x & 0x0f];
		}

		for (int i = 0; i < 8; ++i) {
			uint32_t j = 6 + 9 * i;
			int      k;

			if (addr + i < cb) {
				uint8_t x = pb[addr+i];
				if (msb) {
					for (k = 0; k < 8; ++k)
						mask[j + k] = (x & ((1 << (7-k)))) ? '1' : '0';
				} else {
					for (k = 0; k < 8; ++k)
						mask[j + k] = (x & ((1 << k))) ? '1' : '0';
				}
			} else {
				memset(&mask[j], ' ', 8);
			}
		} // end for //
		fprintf(file, "%s", mask);
		addr += 16;
	} // end while //
}
