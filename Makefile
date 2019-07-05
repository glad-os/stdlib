#
# Copyright 2019 AbbeyCatUK
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

.SILENT:

# common

GCC_PATH		= ~/Downloads/Software/ARM/32-bit/gcc-arm-8.2-2019.01-x86_64-arm-eabi/
GCC      		= $(GCC_PATH)/bin/arm-eabi-gcc
AS       		= $(GCC_PATH)/arm-eabi/bin/as
AR       		= $(GCC_PATH)/arm-eabi/bin/ar
LD       		= $(GCC_PATH)/arm-eabi/bin/ld
OBJDUMP  		= $(GCC_PATH)/arm-eabi/bin/objdump
OBJCOPY  		= $(GCC_PATH)/arm-eabi/bin/objcopy

FIND     		= find
OPTIMIZE 		= -O0
ARCH	 		= -march=armv8-a -mtune=cortex-a53 -mfloat-abi=hard -mfpu=neon-fp-armv8
FLAGS_C  		= $(ARCH) -std=gnu99 -fsigned-char -undef -Wall -Wno-psabi $(OPTIMIZE) -fno-builtin -nostdinc -nostartfiles -ffreestanding -mapcs-frame -mno-thumb-interwork
FLAGS_A			= $(ARCH) $(OPTIMIZE)

# -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

# all

all: clean stdlib

# -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

# clean

clean:
	$(FIND) . -type f -name "*.o"    -delete
	$(FIND) . -type f -name "*.a"    -delete
	$(FIND) . -type f -name "*.hex"  -delete
	$(FIND) . -type f -name "*.bin"  -delete
	$(FIND) . -type f -name "*.elf"  -delete
	$(FIND) . -type f -name "*.list" -delete

# -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

STDLIB_HOME 			= .

STDLIB_INCLUDES			= -I $(STDLIB_HOME)/include
STDLIB_FLAGS_C	 		= $(FLAGS_C) $(STDLIB_INCLUDES)

STDLIB_CORE_FILES_C   	= $(patsubst %.c,%.o,$(wildcard $(STDLIB_HOME)/*.c))

stdlib: stdlib_c

	${AR} cr ${STDLIB_HOME}/stdlib.a ${STDLIB_HOME}/*.o 
	
stdlib_c: $(STDLIB_CORE_FILES_C)

$(STDLIB_HOME)/%.o : $(STDLIB_HOME)/%.c
	$(GCC) -c $(STDLIB_FLAGS_C) $< -o $@  

