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
#include <time.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>

#include "dump.h"
#include "x8b10b.h"
#include "dc_check.h"

#define B8_BUFFER_SIZE     4096
#define B10_BUFFER_SIZE    ((B8_BUFFER_SIZE / 8 + 1) * 10)
#define N_TESTS           10000

static uint8_t source_buffer[B8_BUFFER_SIZE];
static uint8_t target_buffer[B8_BUFFER_SIZE];
static uint8_t encode_buffer[B10_BUFFER_SIZE];
static int     source_size, target_size, encode_size;
static int     n_errors = 0;

#undef  TEST_ZERO
#undef  BIN_DUMP
#define MSB 0

int main(void) {
	size_t i;
	int    c;
#ifndef TEST_ZERO
	size_t j;
#endif

	puts("x8b10b test start");
	srand(time(NULL));
	for (i = 0; i < N_TESTS; ++i) {
		fflush(stdout);
		source_size = rand() % B8_BUFFER_SIZE;
#ifdef TEST_ZERO
		memset(source_buffer, 0x00, sizeof(source_buffer));
#else
		for (j = 0; j < source_size; ++j)
			source_buffer[j] = rand() % 256;
#endif
		memset(encode_buffer, 0x00, sizeof(encode_buffer));
		encode_size = x8b10b(source_buffer, source_size,
							 encode_buffer, sizeof(encode_buffer));
		if (encode_size < 0) {
			++n_errors;
			fprintf(stderr, "x8b10b() failed: %s\n", strerror(-encode_size));
			fflush(stderr);
			continue;
		}

#ifdef BIN_DUMP
		dump_bin(stderr, encode_buffer, encode_size, MSB);
#endif

		c = dc_check(encode_buffer, encode_size, MSB);
		if (c > 5) {
			++n_errors;
			fprintf(stderr, "dc_check reported sequences of %d bits\n", c);
			fflush(stderr);
		}

		memset(target_buffer, 0x00, sizeof(target_buffer));
		target_size = x10b8b(encode_buffer, encode_size,
							 target_buffer, sizeof(target_buffer));
		if (target_size < 0) {
			++n_errors;
			fprintf(stderr, "x10b8b() failed: %s\n", strerror(-target_size));
			fflush(stderr);
			continue;
		}

		if (source_size != target_size) {
			++n_errors;
			fprintf(stderr, "Sizes differ: src=%d, tgt=%d\n",
					source_size, target_size);
			fflush(stderr);
			continue;
		}

		if (memcmp(source_buffer, target_buffer, source_size) != 0) {
			++n_errors;
			fprintf(stderr, "Contents differ\n");
			fflush(stderr);
			fprintf(stderr, "Source:\n");
			dump_hex(stderr, source_buffer, source_size);
			fprintf(stderr, "Target:\n");
			dump_hex(stderr, target_buffer, target_size);
			continue;
		}
	} // end for //

	fprintf(stdout, "x8b10b %d tests finished with %d errors\n",
			N_TESTS, n_errors);
	return n_errors ? EXIT_FAILURE : EXIT_SUCCESS;
}
