/*
 * Mouse pointer emulator using the Analog Joystick.
 * 
 * Mice in Joy Copyright (c) 2012 Johnny on Flame
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include <ini.h>
#include <stdio.h>
#include <assert.h>

#include <string.h>
#include <stdlib.h>

#include "configure.h"
#include "analog.h"

/*
 * __alloccpy_str( char* str, size_t b, const char* buf)
 * Allocates and copies a string from a buffer into a new char.
 */

#define __alloccpy_str(a, b, c) \
	a = alloca(b+1); \
	a[b] = '\0'; \
	memcpy(a, c, b);

void doConfigure(char *f){

	struct INI *ini = ini_open(f);
	const char *bufa, *bufb, *bufc;
	size_t sa, sb, sc;

	if (ini) {
			while (ini_next_section(ini, &bufa, &sa)) {
					char *section;
					__alloccpy_str(section, sa, bufa);

					while (ini_read_pair(ini, &bufb, &sb, &bufc, &sc)) {
							char *key, *value;
							__alloccpy_str(key, 	sb, bufb);
							__alloccpy_str(value, sc, bufc);

							doOption(key, value);
					}
			}
	}
}

void doOption(char *key, char *val)
{
	float value = atof(val);

	if (!strcmp(key, "sensitivity"))
		sensitivity = 1 / (MAX_ABS/value);
	
	if (!strcmp(key, "polling"))
		polling_rate = 1000000/value;

}
