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

#ifndef X8B10B_H_
#define X8B10B_H_

#include <inttypes.h>
#include <stdlib.h>

extern int x8b10b(uint8_t *pb_in, size_t cb_in, uint8_t *pb_out, size_t cb_out);

extern int x10b8b(uint8_t *pb_in, size_t cb_in, uint8_t *pb_out, size_t cb_out);

#endif /* X8B10B_H_ */
