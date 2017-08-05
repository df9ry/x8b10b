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

#include <errno.h>
#include <stdio.h>

#include "x8b10b.h"
#include "x8b10b_tables.h"

#undef  _TRACE

#define BIT(N)  (1<<(N))
#define MASK(N) ((1<<(N))-1)
#define RD_BIT  BIT(7)

#define L2R

#ifdef _TRACE
static char buf[20];
static char* bits(uint16_t symbol, int n) {
	for (int i = 0; i < n; ++i)
		 buf[i] = ((symbol & BIT(n-i-1)) != 0) ? '1' : '0';
	buf[n] = '\0';
	return buf;
}
#endif

static inline void _8b_2_10b(uint8_t u8b, uint16_t *p10b, int *rd)
{
	uint16_t abcdeifghj;
	uint8_t  abcdei, abcdei_rd, fghj, fghj_rd, x, y;

	x =  u8b       & MASK(5); /* 5 bit */
	y = (u8b >> 5) & MASK(3); /* 3 bit */

	abcdei = ((*rd) < 0) ? b5b6_1[x] : b5b6_2[x];
	abcdei_rd = ((abcdei & RD_BIT) != 0x00);
	abcdei = abcdei & MASK(6);
	if (abcdei_rd) {
		if ((*rd) < 0)
			(*rd) += 2;
		else
			(*rd) -= 2;
	}

	if (y == 7) {
		if ((*rd) < 0) {
			if ((x == 17) || (x == 18) || (x = 20))
					y = 8;
		} else {
			if ((x == 11) || (x == 13) || (x = 14))
					y = 8;
		}
	}

	fghj = ((*rd) < 0) ? b3b4_1[y] : b3b4_2[y];
	fghj_rd = ((fghj & RD_BIT) != 0x00);
	fghj = fghj & MASK(4);
	if (fghj_rd) {
		if ((*rd) < 0)
			(*rd) += 2;
		else
			(*rd) -= 2;
	}

	abcdeifghj = (abcdei << 4) | fghj;
#ifdef _TRACE
	printf("_8b_2_10b: "
		   "abcdei=%s / ",     bits(abcdei,      6));
	printf("fghj=%s / ",       bits(fghj,        4));
	printf("abcdeifghj=%s / ", bits(abcdeifghj, 10));
	printf("rd=%s\n",          ((*rd)<0)?"-1":"+1" );
	if (((*rd) != -1) && ((*rd) != +1))
		printf("Error: Invalid RD=%d\n", (*rd));
#endif
	(*p10b) = abcdeifghj;
}

static inline int _10b_2_8b(uint16_t abcdeifghj, uint8_t *p8b, int *rd)
{
	uint8_t  abcdei, x_rd, fghj, y_rd, x, y;

	abcdeifghj = abcdeifghj & MASK(10);

	abcdei = (abcdeifghj >> 4) & MASK(6);
	fghj   =  abcdeifghj       & MASK(4);

#ifdef _TRACE
	printf("_10b_2_8b: "
		   "abcdei=%s / ",     bits(abcdei,      6));
	printf("fghj=%s / ",       bits(fghj,        4));
	printf("abcdeifghj=%s / ", bits(abcdeifghj, 10));
	printf("rd=%s\n",          ((*rd)<0)?"-1":"+1" );
	if (((*rd) != -1) && ((*rd) != +1))
		printf("Error: Invalid RD=%d\n", (*rd));
#endif

	x = ((*rd) < 0) ? b6b5_1[abcdei] : b6b5_2[abcdei];
	if (x == 0xff) /* Code not assigned */
		return 0;
	x_rd = ((x & RD_BIT) != 0x00);
	x = x & MASK(5);
	if (x_rd) {
		if ((*rd) < 0)
			(*rd) += 2;
		else
			(*rd) -= 2;
	}

	y = ((*rd) < 0) ? b4b3_1[fghj] : b4b3_2[fghj];
	if (y == 0xff) /* Code not assigned */
		return 0;
	y_rd = ((y & RD_BIT) != 0x00);
	y = y & MASK(3);
	if (y_rd) {
		if ((*rd) < 0)
			(*rd) += 2;
		else
			(*rd) -= 2;
	}

	(*p8b) = x | (y << 5);
	return 1;
}

int x8b10b(uint8_t *pb_in,  size_t cb_in, uint8_t *pb_out, size_t cb_out)
{
	uint16_t abcdeifghj;
	int n_bits = 0, result = 0, rd = -1;

#ifdef L2R
	union {
		uint16_t reg;
		uint8_t oct[2];
	} u;

	u.reg = 0x0000;
	while (cb_in != 0) {
		_8b_2_10b((*pb_in), &abcdeifghj, &rd); ++pb_in; --cb_in;
		u.reg = u.reg | (abcdeifghj << (6 - n_bits)); n_bits += 10;
		while (n_bits >= 8) {
			if (cb_out == 0)
				return -E2BIG;
			(*pb_out) = u.oct[1]; u.reg = (u.reg << 8); n_bits -= 8;
			++pb_out; --cb_out;
			++result;
		} // end while //
	} // end while //
	if (n_bits > 0) {
		if (cb_out == 0)
			return -E2BIG;
		u.reg = u.reg | 0x55 << (8 - n_bits);
		(*pb_out) = u.oct[1];
		++result;
	}
#else
	uint16_t u10;

	u10 = 0x0000;
	while (cb_in != 0) {
		_8b_2_10b(*pb_in, &abcdeifghj, &rd); ++pb_in; --cb_in;
		u10 = u10 | (abcdeifghj << n_bits); n_bits += 10;
		while (n_bits >= 8) {
			if (cb_out == 0)
				return -E2BIG;
			*pb_out = u10 & 0xff; u10 = u10 >> 8; n_bits -= 8;
			++pb_out; --cb_out;
			++result;
		} // end while //
	} // end while //
	if (n_bits > 0) {
		if (u10 & ((1<<(n_bits-1))))
			u10 = u10 | (0x66 << n_bits);
		else
			u10 = u10 | (0x55 << n_bits);
		if (cb_out == 0)
			return -E2BIG;
		*pb_out = (uint8_t)u10; ++result;
	}
#endif
	return result;
}

int x10b8b(uint8_t *pb_in,  size_t cb_in, uint8_t *pb_out, size_t cb_out)
{
	int n_bits = 0, result = 0, rd = -1;

#ifdef L2R
	uint16_t u10, t10;

	u10 = 0x0000;
	while (cb_in != 0) {
		while (n_bits < 10) {
			if (cb_in == 0)
				return -EINVAL;
			t10 = (*pb_in);	--cb_in; ++pb_in;
			u10 = u10 | (t10 << (8 - n_bits));
			n_bits += 8;
		} // end while //
		if (cb_out == 0)
			return -E2BIG;
		t10 = (u10 >>  6) & MASK(10);
		u10 = (u10 << 10);
		n_bits -= 10;
		if (!_10b_2_8b(t10, pb_out, &rd))
			return -EINVAL;
		++pb_out; --cb_out; ++result;
	} // end while //

#else
	uint16_t u10;

	u10 = 0x0000;
	while (cb_in != 0) {
		while (n_bits < 10) {
			if (cb_in == 0)
				return -EINVAL;
			u10 = u10 | ((*pb_in) << n_bits); ++pb_in; --cb_in; n_bits += 8;
		} // end while //
		if (!cb_out)
			return -E2BIG;
		if (!_10b_2_8b(u10, pb_out, &rd))
			return -EINVAL;
		++pb_out; --cb_out; ++result;
		u10 = u10 >> 10; n_bits -= 10;
	} // end while //
#endif
	return result;
}
