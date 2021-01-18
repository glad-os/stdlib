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


#ifndef SVC_MACROS_H
#define SVC_MACROS_H


    // SVC call may occur with 0-4 inputs...
    #define _SVC_CALL0( SWI_NUMBER )    \
        __asm__ __volatile__ (                  \
        "SWI %[swi]            \n\t"            \
        "MOV %[result] , r0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [swi]    "I"  ( SWI_NUMBER )        \
        :                                       \
        );


    #define _SVC_CALL1( SWI_NUMBER, R0 ) \
        __asm__ __volatile__ (                  \
        "MOV r0        , %[r0] \n\t"            \
        "SWI %[swi]            \n\t"            \
        "MOV %[result] , r0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [swi]    "I"  ( SWI_NUMBER ) ,      \
            [r0]     "r"  (R0)                  \
        :                                       \
        );


    #define _SVC_CALL2( SWI_NUMBER, R0, R1 ) \
        __asm__ __volatile__ (                  \
        "MOV r0        , %[r0] \n\t"            \
        "MOV r1        , %[r1] \n\t"            \
        "SWI %[swi]            \n\t"            \
        "MOV %[result] , r0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [swi]    "I"  ( SWI_NUMBER ) ,      \
            [r1]     "r"  (R1)  ,               \
            [r0]     "r"  (R0)                  \
        :                                       \
        );


    #define _SVC_CALL3( SWI_NUMBER, R0, R1, R2 ) \
        __asm__ __volatile__ (                  \
        "MOV r0        , %[r0] \n\t"            \
        "MOV r1        , %[r1] \n\t"            \
        "MOV r2        , %[r2] \n\t"            \
        "SWI %[swi]            \n\t"            \
        "MOV %[result] , r0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [swi]    "I"  ( SWI_NUMBER ) ,      \
            [r2]     "r"  (R2)  ,               \
            [r1]     "r"  (R1)  ,               \
            [r0]     "r"  (R0)                  \
        :                                       \
        );


    #define _SVC_CALL4( SWI_NUMBER, R0, R1, R2, R3 ) \
        __asm__ __volatile__ (                  \
        "MOV r0        , %[r0] \n\t"            \
        "MOV r1        , %[r1] \n\t"            \
        "MOV r2        , %[r2] \n\t"            \
        "MOV r3        , %[r3] \n\t"            \
        "SWI %[swi]            \n\t"            \
        "MOV %[result] , r0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [swi]    "I"  ( SWI_NUMBER ) ,      \
            [r3]     "r"  (R3)  ,               \
            [r2]     "r"  (R2)  ,               \
            [r1]     "r"  (R1)  ,               \
            [r0]     "r"  (R0)                  \
        :                                       \
        );


#endif /*SVC_MACROS_H*/
