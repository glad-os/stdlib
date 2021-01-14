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


#include "maths.h"
#include "stdio.h"


double fabs( double i )
{

	printf( "fabs not done yet\n" );
	return 0.0;

}


int abs( int i )
{

	printf( "abs not done yet\n" );
	return 0;

}


double cos( double i )
{

	printf( "cos not done yet\n" );
	return 0.0;

}


int floor( double i )
{

	printf( "floor not done yet\n" );
	return 0;

}


unsigned int rand( void )
{

	// https://stackoverflow.com/questions/1167253/implementation-of-rand
	static unsigned int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
	   unsigned int b;
	   b  = ((z1 << 6) ^ z1) >> 13;
	   z1 = ((z1 & 4294967294U) << 18) ^ b;
	   b  = ((z2 << 2) ^ z2) >> 27;
	   z2 = ((z2 & 4294967288U) << 2) ^ b;
	   b  = ((z3 << 13) ^ z3) >> 21;
	   z3 = ((z3 & 4294967280U) << 7) ^ b;
	   b  = ((z4 << 3) ^ z4) >> 12;
	   z4 = ((z4 & 4294967168U) << 13) ^ b;
	   return (z1 ^ z2 ^ z3 ^ z4);


}


double sin( double i )
{

	printf( "sin not done yet\n" );
	return 0.0;

}


double sqrt( double i )
{

	printf( "sqrt not done yet\n" );
	return i;

}


unsigned int isnan( double i )
{

	printf( "isnan not done yet\n" );
	return 0;

}


double tan( double i )
{

	printf( "tan not done yet\n" );
	return 0.0;

}
