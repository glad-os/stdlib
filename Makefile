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

#.SILENT:

# common
FIND     			= find
OPTIMIZE 			= 0

# 32-bit toolchain
GCC_PATH_32			= /gcc-arm-8.3-2019.03-x86_64-arm-eabi
GCC_32      			= $(GCC_PATH_32)/bin/arm-eabi-gcc
AS_32       			= $(GCC_PATH_32)/arm-eabi/bin/as
AR_32       			= $(GCC_PATH_32)/arm-eabi/bin/ar
LD_32       			= $(GCC_PATH_32)/arm-eabi/bin/ld
OBJDUMP_32  			= $(GCC_PATH_32)/arm-eabi/bin/objdump
OBJCOPY_32  			= $(GCC_PATH_32)/arm-eabi/bin/objcopy

# 64-bit toolchain
GCC_PATH_64			= /gcc-arm-8.3-2019.03-x86_64-aarch64-elf
GCC_64      			= $(GCC_PATH_64)/bin/aarch64-elf-gcc
AS_64       			= $(GCC_PATH_64)/aarch64-elf/bin/as
AR_64       			= $(GCC_PATH_64)/aarch64-elf/bin/ar
LD_64       			= $(GCC_PATH_64)/aarch64-elf/bin/ld
OBJDUMP_64  			= $(GCC_PATH_64)/aarch64-elf/bin/objdump
OBJCOPY_64  			= $(GCC_PATH_64)/aarch64-elf/bin/objcopy

# 32/64 bit flags for Assembler and Compiler
ARCH_64	 			= -march=armv8-a -mtune=cortex-a53
FLAGS_C_64  			= $(ARCH_64) -nostdlib -nostdinc -std=gnu99 -fsigned-char -Wno-psabi -O$(OPTIMIZE) -fno-builtin -nostartfiles -ffreestanding -D ISA_TYPE=$(ISA_TYPE)
FLAGS_A_64			= $(ARCH_64) -O$(OPTIMIZE) -D ISA_TYPE=$(ISA_TYPE)

ARCH_32	 			= -march=armv8-a -mtune=cortex-a53 -mfpu=neon-fp-armv8 -mfloat-abi=hard
FLAGS_C_32  			= $(ARCH_32) -nostdlib -nostdinc -std=gnu99 -fsigned-char -Wno-psabi -O$(OPTIMIZE) -fno-builtin -nostartfiles -ffreestanding -mapcs-frame -mno-thumb-interwork -D ISA_TYPE=$(ISA_TYPE)
FLAGS_A_32			= $(ARCH_32) -O$(OPTIMIZE) -D ISA_TYPE=$(ISA_TYPE)

# -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

# 32-bit

32-bit: clean stdlib-32

32-bit: ISA_TYPE		= 32

32-bit: GCC			= $(GCC_32)
32-bit: AS			= $(AS_32)
32-bit: AR			= $(AR_32)
32-bit: LD			= $(LD_32)
32-bit: OBJDUMP			= $(OBJDUMP_32)
32-bit: OBJCOPY			= $(OBJCOPY_32)

32-bit: FLAGS_C			= $(FLAGS_C_32)
32-bit: FLAGS_A			= $(FLAGS_A_32)

# -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  

# 64-bit

64-bit: clean stdlib-64

64-bit: ISA_TYPE		= 64

64-bit: GCC			= $(GCC_64)
64-bit: AS			= $(AS_64)
64-bit: AR			= $(AR_64)
64-bit: LD			= $(LD_64)
64-bit: OBJDUMP			= $(OBJDUMP_64)
64-bit: OBJCOPY			= $(OBJCOPY_64)

64-bit: FLAGS_C			= $(FLAGS_C_64)
64-bit: FLAGS_A			= $(FLAGS_A_64)

64-bit: INCLUDE_DIR		= c/64-bit/include/

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

# stdlib
STDLIB_HOME 			= .
STDLIB_INCLUDES			= -I $(STDLIB_HOME)/c/common/include

STDLIB_FILES_C_COMMON		= $(patsubst %.c,%.o,$(shell find c/common   -type f -name '*.c'))
STDLIB_FILES_C_32		= $(patsubst %.c,%.o,$(shell find c/32-bit   -type f -name '*.c'))
STDLIB_FILES_C_64		= $(patsubst %.c,%.o,$(shell find c/64-bit   -type f -name '*.c'))
STDLIB_FLAGS_C	 		= $(FLAGS_C) $(STDLIB_INCLUDES)

#stdlib-32: $(STDLIB_FILES_C_COMMON) $(STDLIB_FILES_C_32) stdlib
stdlib-32: $(STDLIB_FILES_C_COMMON) stdlib
stdlib-64: $(STDLIB_FILES_C_COMMON) $(STDLIB_FILES_C_64) stdlib

stdlib:
	${AR} cr ${STDLIB_HOME}/stdlib-$(ISA_TYPE).a ${STDLIB_HOME}/c/common/*.o
	$(OBJDUMP) -D stdlib-$(ISA_TYPE).a > stdlib-$(ISA_TYPE).list

$(STDLIB_HOME)/c/common/%.o : $(STDLIB_HOME)/c/common/%.c
	$(GCC) -c $(STDLIB_FLAGS_C) $< -o $@  

$(STDLIB_HOME)/c/32-bit/%.o : $(STDLIB_HOME)/c/32-bit/%.c
	$(GCC_32) -c $(STDLIB_FLAGS_C) $< -o $@  

$(STDLIB_HOME)/c/64-bit/%.o : $(STDLIB_HOME)/c/64-bit/%.c
	$(GCC_64) -c $(STDLIB_FLAGS_C) $< -o $@  

