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


#include "kernel.h"
#include "swis.h"


void _kernel_swi( unsigned int swi_number, struct _kernel_regs *in, struct _kernel_regs *out )
{

	switch ( swi_number ) {
		case OS_SetColour 			: SWI( OS_SetColour, in, out ); 			break;
		case OS_ClearScreen 		: SWI( OS_ClearScreen, in, out ); 			break;
		case OS_PutPixel 			: SWI( OS_PutPixel, in, out ); 				break;
		case OS_GetPixel 			: SWI( OS_GetPixel, in, out ); 				break;
		case OS_SetCursorPosition	: SWI( OS_SetCursorPosition, in, out );		break;
		case OS_PrintChar 			: SWI( OS_PrintChar, in, out ); 			break;
		case OS_PrintString 		: SWI( OS_PrintString, in, out ); 			break;
		case OS_ReadVideoVariables 	: SWI( OS_ReadVideoVariables, in, out ); 	break;
		case OS_ReadC 				: SWI( OS_ReadC, in, out ); 				break;
		case OS_ProcessBegin		: SWI( OS_ProcessBegin, in, out ); 			break;
        case OS_ProcessExit         : SWI( OS_ProcessExit, in, out );           break;	
    }

}
