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


#include "stdlib.h"
#include "svc.h"
#include "stdio.h"


int atoi( const char *s )
{

	int result = 0;
	char c;

	while ( (c = *s++) ) {
		result = (result*10) + (c-48);
	}

	return result;

}


double atof( const char *s )
{

	printf( "atof not done yet\n" );

	return 0.0;

}


unsigned int fork( const char *str )
{

    unsigned int result;

    _SVC_CALL0( OS_ProcessBegin );

    return result;

}



void process_exit( void )
{

    unsigned int result;

    _SVC_CALL0( OS_ProcessExit );

}
