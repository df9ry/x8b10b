/*
 * dump.h
 *
 *  Created on: 02.08.2017
 *      Author: tania
 */

#ifndef DUMP_H_
#define DUMP_H_

#include <inttypes.h>

/* Fast dump in a nice format: */
extern void dump_hex(FILE *file, const uint8_t *pb, uint32_t cb);

#endif /* DUMP_H_ */
