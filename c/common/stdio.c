/**
 * Copyright 2019 AbbeyCatUK
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "stdio.h"
#include "swi.h"
#include <stdint.h>


unsigned int sprintf( char *str )
{

        unsigned int result;

        __asm__ __volatile__ ( 
        "MOV r0, %[str]      \n\t" 
        "SWI %[swi]          \n\t"
        "MOV %[result], r0   \n\t"
        :   [result] "=r" ( result )                    /* output operands */
        :   [str]    "r"  ( str ),                      /* input operands */
            [swi]    "I"  ( OS_PrintString )
        :                                               /* no clobber */
        );

        return result;

}


int sprintf_i( char *s, int i )
{

	// just get it working for now
	unsigned long int length;
	unsigned long int divisor;
	unsigned long int quotient;
	length = 0;

	if ( i == 0 )
	{

		*s++ = 48;
		length++;

	} else {

		divisor = 1000000000;
		while ( divisor >= 1 )
		{
			quotient = i / divisor;
			if ( quotient || length ) {
				*s++ = quotient + 48;
				length++;
				i -= (quotient * divisor);
			}
			divisor /= 10;
		}

	}

	// stick \0 at end
	*s = 0;
	length++;

	return length;

}


int getchar( void )
{

    /*
    struct _kernel_regs in, out;
    _kernel_swi( OS_ReadC, &in, &out );

    return out.r[ 0 ];
    */

    return 65;

}


char *gets( char *s )
{
	
    int  index, line_terminated, render;
    char next, printme[2];

    index = line_terminated = 0;
    while ( !line_terminated )
    {
		
        next   = getchar();
	render = 0;

	if ( next == 0x0a )
	{
            s[index++] = 0x00;
            line_terminated = 1;
	}
	else
	{
            if ( next == 0x7f )
            {
                if (index > 0)
		{
                    index--;
                    render = 1;
		}
            }
            else
            {
                if ( index < 255 )
		{
                    s[index++] = next;
                    render = 1;
		}
            }
	}

	if ( render )
	{
            printme[0] = next;
            printme[1] = 0x00;
            sprintf( printme );
	}
		
    }

    sprintf( "\n" );	
    return s;
	
}
