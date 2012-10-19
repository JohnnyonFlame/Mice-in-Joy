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

#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "analog.h"

int main(int argc, char *argv[])
{
	pid_t pid, sid;
	
	pid = fork();
	if (pid < 0) {
		printf("ERROR: Couldn't fork process.\n");
		return -1;
	}
	
	if (pid > 0) {
		printf("Process forked at pid: %i\n", pid);
		return 0;
	}
	
	umask(0);
	
	sid = setsid();
	
	if (sid < 0) {
		return -1;
	}
	
	if ((chdir("/")) < 0) {
		return -1;
	}
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	
	doMouse();
	
	return 0;
}