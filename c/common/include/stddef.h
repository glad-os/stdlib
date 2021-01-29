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


#ifndef STDDEF_H
#define STDDEF_H

    // @TODO - KJS - these types need solidifying and aligning between both platforms
    // I almost need this idea of a "native" unsigned int thing? Because I am referencing
    // "uint32_t" in BASIC, but when doing "make 64-bit" it's throwing warnings, which I'd 
    // really like to get on top of. So let's take a step back and our next step here is going 
    // to be making sure that not only is stdlib building CLEANLY for 32/64 bit, but also 
    // BASIC is suitably building with the right sizes of things here.

    typedef unsigned char uint8_t;
    typedef unsigned int  uint32_t;
    typedef uint32_t      uintmax_t;

#endif /*STDDEF_H*/
