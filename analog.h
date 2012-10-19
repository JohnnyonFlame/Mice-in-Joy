/*
 * Mouse pointer emulator using the Analog Joystick.
 * 
 * Mice Joy Copyright (c) 2012 Johnny on Flame
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

#ifndef __ANALOG_H__
#define __ANALOG_H__

#include <linux/input.h>
#include <linux/joystick.h>
#include <linux/uinput.h>

#define SIZE_EV sizeof(struct js_event)

#define MAX_ABS 32768

void doMouse();

int report_mice(int f, unsigned int axis, int value);
int report_ev(int f, int type, int code, int value);

extern int polling_rate;
extern int sensivity;

#endif //__ANALOG_H__