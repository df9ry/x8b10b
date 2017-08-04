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

#include "dc_check.h"

int dc_check(const uint8_t *pb, uint32_t cb, int msb) {
	int last_bit = 0, count_bit = 0, max_sequ = 0, k, bit = 0;

	while (cb-- != 0) {
		uint8_t x = *pb++;

		for (k = 0; k < 8; ++k) {
			if (msb)
				bit = ((x & ((1 << (7-k)))) != 0x00);
			else
				bit = ((x & ((1 << k))) != 0x00);

			if (bit == last_bit) {
				++count_bit;
				if (count_bit > max_sequ)
					max_sequ = count_bit;
			} else {
				last_bit = bit;
				count_bit = 1;
			}
		} // end for //
	} // end while //
	return max_sequ;
}
