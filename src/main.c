/*
 ============================================================================
 Name        : x8b10b_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>

#include "dump.h"
#include "x8b10b.h"

#define B8_BUFFER_SIZE     4096
#define B10_BUFFER_SIZE    ((B8_BUFFER_SIZE / 8 + 1) * 10)
#define N_TESTS            1024

#define LINE_WIDTH           72

static uint8_t source_buffer[B8_BUFFER_SIZE];
static uint8_t target_buffer[B8_BUFFER_SIZE];
static uint8_t encode_buffer[B10_BUFFER_SIZE];
static int     source_size, target_size, encode_size;
static int     n_errors = 0;

int main(void) {
	size_t i, j;

	puts("x8b10b test start");
	srand(time(NULL));
	for (i = 0; i < N_TESTS; ++i) {
//		if ((i % LINE_WIDTH) == 0)
//			putchar('\n');
//		putchar('.');
		fflush(stdout);
		source_size = rand() % B8_BUFFER_SIZE;
		for (j = 0; j < source_size; ++j)
			source_buffer[j] = rand() % 256;
//		fprintf(stdout, "Buffer output:\n");
//		dump(stdout, input_buffer, input_size);
		memset(encode_buffer, 0x00, sizeof(encode_buffer));
		encode_size = x8b10b(source_buffer, source_size,
							 encode_buffer, sizeof(encode_buffer));
		if (encode_size < 0) {
			++n_errors;
			fprintf(stderr, "x8b10b() failed: %s\n", strerror(-encode_size));
			fflush(stderr);
			continue;
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

	fprintf(stdout, "\n\nx8b10b test finished with %d errors\n", n_errors);
	return n_errors ? EXIT_FAILURE : EXIT_SUCCESS;
}
