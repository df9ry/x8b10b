/*
 * x8b10b.h
 *
 *  Created on: 02.08.2017
 *      Author: tania
 */

#ifndef X8B10B_H_
#define X8B10B_H_

#include <inttypes.h>
#include <stdlib.h>

extern int x8b10b(uint8_t *pb_in, size_t cb_in, uint8_t *pb_out, size_t cb_out);

extern int x10b8b(uint8_t *pb_in, size_t cb_in, uint8_t *pb_out, size_t cb_out);

#endif /* X8B10B_H_ */
