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

#include <stdio.h>
#include <assert.h>

#include <string.h>
#include <stdlib.h>

#include "configure.h"
#include "analog.h"

void doConfigure(char *f){
	char buf[32];
	
	FILE *config_id = NULL;
	
	config_id = fopen(f, "r");
	//assert(config_id);
	
	if (config_id!=NULL) {
		while(getLine(config_id, buf))
		{
			char opt[16];
			int value=0;
			
			printf("%s\n", buf);
			
			if (sscanf(buf, "%s = %i", opt, &value))
			{
				doOption(opt, value);
			}
		}
	}
	else
	{
		char p[128], ch;
		sprintf(p, "%s/%s", getenv("PWD"), "analog.conf");
		
		FILE *source = fopen(p, "r");
		
		if (source==NULL)
			return;
		
		FILE *target = fopen(f, "w");
		
		if (target==NULL)
		{
			fclose(target);
			return;
		}
		
		while( ( ch = fgetc(source) ) != EOF )
			fputc(ch, target);
		
		fclose(target);
		fclose(source);
		
		sensivity = MAX_ABS/10;
		polling_rate = 1000000/33;
	}
}

int getLine(FILE *f, char *c){
	char buf[32];
	
	if (!fgets(buf, sizeof(buf), f))
		return 0;
	
	int len = strlen(buf)-1;
	if(buf[len] == '\n') 
		buf[len] = '\0';
	
	printf("%s\n", buf);
	
	strcpy(c, buf);
	
	return 1;
}

void doOption(char *opt, int value)
{
	if (!strcmp(opt, "sensivity"))
		sensivity = MAX_ABS/value;
	
	if (!strcmp(opt, "polling"))
		polling_rate = 1000000/value;
	
}