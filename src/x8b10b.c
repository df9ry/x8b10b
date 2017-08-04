/*
 * x8b10b.c
 *
 *  Created on: 02.08.2017
 *      Author: tania
 */

#include <errno.h>
#include <stdio.h>

#include "x8b10b.h"
#include "x8b10b_tables.h"

#undef _TRACE

static inline void _8b_2_10b(uint8_t u8b, uint16_t *p10b, int *rd)
{
	uint16_t abcdeifghj;
	uint8_t  abcdei, fghj, x, y;
	int rs;

	x = u8b & ((1<<5)-1); /* 5 bit */
	abcdei = x5b6b[x] & ((1<<6)-1);
	rs = (abcdei & (1<<7));
	if (rs) /*RD sensible*/ {
		if (*rd < 0) {
			abcdei = ~abcdei;
			*rd = +1;
		} else {
			*rd = -1;
		}
		abcdei = abcdei & ((1<<6)-1);
	}

	y = (u8b >> 5) & ((1<<3)-1); /* 3 bit */
	if (y == 7) { // Special case:
		if (*rd < 0) {
			if ((y == 17) || (x == 18) || (x = 20))
				y = 8;
		} else {
			if ((y == 11) || (x == 13) || (x = 14))
				y = 8;
		}
	}
	fghj = x3b4b[y];
	rs = (fghj & (1<<7));
	if (rs) /*RD sensible*/ {
		if (*rd < 0) {
			fghj = ~fghj;
			*rd = +1;
		} else {
			*rd = -1;
		}
		fghj = fghj & ((1<<4)-1);
	}

	abcdeifghj = (abcdei << 4) | fghj;
#ifdef _TRACE
	printf("_8b_2_10b: abcdei=%02x / ", abcdei);
	printf("fghj=%01x / ", fghj);
	printf("abcdeifghj=%03x\n", abcdeifghj);
#endif
	*p10b = abcdeifghj;
}

static inline int _10b_2_8b(uint16_t u10b, uint8_t *p8b)
{
	uint16_t abcdeifghj;
	uint8_t  abcdei, fghj, x, y, z;

	abcdeifghj = u10b & ((1<<10)-1);
	abcdei = (abcdeifghj >> 4) & ((1<<6)-1);
	x =	x6b5b[abcdei];
	fghj = abcdeifghj & ((1<<4)-1);
#ifdef _TRACE
	printf("_10b_2_8b: abcdei=%02x / ", abcdei);
	printf("fghj=%01x / ", fghj);
	printf("abcdeifghj=%03x\n", abcdeifghj);
#endif
	y =	x4b3b[fghj];
	if ((x == 0xff) || (y == 0xff)) /* Code not assigned */
		return 0;
	z = x | (y << 5);
	(*p8b) = z;
	return 1;
}

int x8b10b(uint8_t *pb_in,  size_t cb_in, uint8_t *pb_out, size_t cb_out)
{
	uint16_t abcdeifghj, u10;
	int rd = -1, n_bits = 0, result = 0;

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
		if (cb_out == 0)
			return -E2BIG;
		*pb_out = (uint8_t)u10; ++result;
	}
	return result;
}

int x10b8b(uint8_t *pb_in,  size_t cb_in, uint8_t *pb_out, size_t cb_out)
{
	uint16_t u10;
	int n_bits = 0, result = 0;

	u10 = 0x0000;
	while (cb_in != 0) {
		while (n_bits < 10) {
			if (cb_in == 0)
				return -EINVAL;
			u10 = u10 | (*pb_in << n_bits); ++pb_in; --cb_in; n_bits += 8;
		} // end while //
		if (!cb_out)
			return -E2BIG;
		if (!_10b_2_8b(u10, pb_out))
			return -EINVAL;
		++pb_out; --cb_out; ++result;
		u10 = u10 >> 10; n_bits -= 10;
	} // end while //
	return result;
}
