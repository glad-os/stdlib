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
    #define _SVC_CALL0( SVC_NUMBER )    \
        __asm__ __volatile__ (                  \
        "SVC %[svc]            \n\t"            \
        "MOV %[result] , x0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [svc]    "I"  ( SVC_NUMBER )        \
        :                                       \
        );


    #define _SVC_CALL1( SVC_NUMBER, X0 ) \
        __asm__ __volatile__ (                  \
        "MOV x0        , %[x0] \n\t"            \
        "SVC %[svc]            \n\t"            \
        "MOV %[result] , x0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [svc]    "I"  ( SVC_NUMBER ) ,      \
            [x0]     "r"  (X0)                  \
        :                                       \
        );


    #define _SVC_CALL2( SVC_NUMBER, X0, X1 ) \
        __asm__ __volatile__ (                  \
        "MOV x0        , %[x0] \n\t"            \
        "MOV x1        , %[x1] \n\t"            \
        "SVC %[svc]            \n\t"            \
        "MOV %[result] , x0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [svc]    "I"  ( SVC_NUMBER ) ,      \
            [x0]     "r"  (X0)  ,               \
            [x1]     "r"  (X1)                  \
        :                                       \
        );


    #define _SVC_CALL3( SVC_NUMBER, X0, X1, X2 ) \
        __asm__ __volatile__ (                  \
        "MOV x0        , %[x0] \n\t"            \
        "MOV x1        , %[x1] \n\t"            \
        "MOV x2        , %[x2] \n\t"            \
        "SVC %[svc]            \n\t"            \
        "MOV %[result] , x0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [svc]    "I"  ( SVC_NUMBER ) ,      \
            [x0]     "r"  (X0)  ,               \
            [x1]     "r"  (X1)  ,               \
            [x2]     "r"  (X2)                  \
        :                                       \
        );


    // KJS - not clear why but with AArch64, unlike AArch32, the inputs
    // here must be listed in the *correct* order (or we get "mov x0,x3; mov x1,x2; mov x2,x1; mov x3,x0")!
    #define _SVC_CALL4( SVC_NUMBER, X0, X1, X2, X3 ) \
        __asm__ __volatile__ (                  \
        "MOV x0        , %[x0] \n\t"            \
        "MOV x1        , %[x1] \n\t"            \
        "MOV x2        , %[x2] \n\t"            \
        "MOV x3        , %[x3] \n\t"            \
        "SVC %[svc]            \n\t"            \
        "MOV %[result] , x0    \n\t"            \
        :   [result] "=r" ( result )            \
        :   [svc]    "I"  ( SVC_NUMBER ) ,      \
            [x0]     "r"  (X0)  ,               \
            [x1]     "r"  (X1)  ,               \
            [x2]     "r"  (X2)  ,               \
            [x3]     "r"  (X3)                  \
        :                                       \
        );


#endif /*SVC_MACROS_H*/
