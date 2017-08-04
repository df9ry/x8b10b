/*
 * dump.c
 *
 *  Created on: 02.08.2017
 *      Author: tania
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dump.h"

void dump_hex(FILE *file, const uint8_t *pb, uint32_t cb) {
	char mask[] =
		"XXXX XXXX: XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX [XXXXXXXXXXXXXXXX]\n";
	const char hex[] = "0123456789abcdef";

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
