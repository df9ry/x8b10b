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

#ifndef DUMP_H_
#define DUMP_H_

#define dump_bin_lsb(F,P,C) dump_bin(F,P,C,0)
#define dump_bin_msb(F,P,C) dump_bin(F,P,C,1)

#include <inttypes.h>

/* Fast dump in a nice format: */
extern void dump_hex(FILE *file, const uint8_t *pb, uint32_t cb);
extern void dump_bin(FILE *file, const uint8_t *pb, uint32_t cb, int msb);

#endif /* DUMP_H_ */
