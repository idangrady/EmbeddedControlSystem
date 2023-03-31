#
# Copyright 2012-2014 The MathWorks, Inc.
#
include $(START_DIR)/slprj/CompSOC_prefs.mk

LOCAL_GCC_TOOLS_PATH = $(COMPILER_ROOT)
ifneq ($(ALTERNATIVE_GCC),)
LOCAL_GCC_TOOLS_PATH = $(ALTERNATIVE_GCC)
endif

ifeq ($(PIL_SPEED),)
PIL_SPEED = 9600
endif

ifeq ($(COMPSOC_VER),)
COMPSOC_VER = 105
endif

ifeq ($(BOARD_TYPE),leonardo)
USBCON = -DUSBCON
endif

LOCAL_OPT       = -ffunction-sections -fdata-sections -fvisibility=hidden -nostartfiles -march=rv32imc -mabi=ilp32 -Os -static --specs=nano.specs -mcmodel=medany $(USBCON) $(DIALOG_OPTIONS) -I$(COMPSOC_ROOT)/files/
LOCAL_CDEFS     = -DF_CPU=$(F_CPU) -DCOMPSOC=$(COMPSOC_VER) -DPIL_SPEED=$(PIL_SPEED) -D__true_false_are_keywords -DUSB_VID=0x2341 -DUSB_PID=0x8036 -Dtrue=0x1 -Dfalse=0x0 -DEXIT_FAILURE=1 -I$(COMPSOC_ROOT)/files/
LOCAL_CXXDEFS   = -DF_CPU=$(F_CPU) -DCOMPSOC=$(COMPSOC_VER) -DPIL_SPEED=$(PIL_SPEED) -D__true_false_are_keywords -DUSB_VID=0x2341 -DUSB_PID=0x8036 -Dtrue=0x1 -Dfalse=0x0 -I$(COMPSOC_ROOT)/files/
LOCAL_CSTANDARD = -std=gnu99
LOCAL_CWARN     = -Wall -Wextra
LOCAL_MCU_OPT   = #-mcpu=v10.0
LOCAL_OPT       += -DEXTMODE_DISABLEPRINTF=1 -DEXTMODE_DISABLE_ARGS_PROCESSING=1
#CDEBUG          = -gstabs

# Compiler command and options
CC                  = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-gcc
CFLAGS              = $(LOCAL_MCU_OPT) -I. $(LOCAL_CDEFS)
CFLAGS             = $(LOCAL_OPT) $(LOCAL_CWARN) $(LOCAL_CSTANDARD)

# Specify the output extension from compiler
CCOUTPUTFLAG        = -o
OBJ_EXT             = .o

CXX                 = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-g++
CXXFLAGS            = $(LOCAL_MCU_OPT) -L -I. $(LOCAL_CXXDEFS) $(LOCAL_OPT)

# Linker command and options
LD                  = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-gcc
LDFLAGS             += -lm  -L$(COMPSOC_ROOT)/files/ -lbsp
LINKER_SCRIPT       := $(COMPSOC_ROOT)/files/von_neumann.ld
LDFLAGS             += $(LOCAL_MCU_OPT) $(LOCAL_CDEFS) $(LOCAL_OPT) $(LOCAL_CWARN) $(LOCAL_CSTANDARD) \
                      -Wl,-T -Wl,${LINKER_SCRIPT}  -o
LDFLAGS             += --gc-sections
                      
ifeq ($(INTEGER_CODE),1)
# LDFLAGS             += -Wl,-u,vfprintf -lprintf_min # this is minimalistic version of printf, 
#                                                       but formating is not completely supported
endif

ifeq ($(INTEGER_CODE),0)
# See http://www.atmel.no/webdoc/AVRLibcReferenceManual/group__avr__stdio_1gaa3b98c0d17b35642c0f3e4649092b9f1.html                    
LDFLAGS             += -Wl,-u,-lm  # this is floating-point version of printf
endif

# Specify extension from linker
LDOUTPUTFLAG        = -o
PROGRAM_FILE_EXT    = .elf
#PROGRAM_FILE_EXT    = .hex

# Archiver command and options
AR                  = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-ar
ARFLAGS             := $(ARFLAGS)U

# Binary file format converter command and options
OBJCOPY             = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-objcopy
OBJCOPYFLAGS        = --remove-section='.partition.*' -g  -Obinary
BINARY_FILE_EXT     = .hex

# Binary size
SIZE                = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-size

# Disassembler
OBJDUMP             = $(LOCAL_GCC_TOOLS_PATH)/riscv32-unknown-elf-objdump
OBJDUMPFLAGS        = -h

# Specify extension for final product at end of build
EXE_FILE_EXT = $(BINARY_FILE_EXT)
#EXE_FILE_EXT = $(PROGRAM_FILE_EXT)

#CompSOC_INC_LIBS    = -I$(CompSOC_ROOT)/libraries/Wire \
                      -I$(CompSOC_ROOT)/libraries/Wire/utility \
                      -I$(CompSOC_ROOT)/libraries/Servo \
                      -I$(CompSOC_ROOT)/libraries/LiquidCrystal \
                      -I$(CompSOC_ROOT)/libraries/Ethernet \
                      -I$(CompSOC_ROOT)/libraries/Ethernet/utility \
                      -I$(CompSOC_ROOT)/libraries/SPI \

#TARGET_INC_DIR       = -I$(CompSOC_ROOT)/hardware/CompSOC/cores/CompSOC
#TARGET_INC_DIR      += -I$(CompSOC_ROOT)/hardware/CompSOC/variants/$(VARIANT)

#TARGET_INCS         = $(TARGET_INC_DIR) $(CompSOC_INC_LIBS)
#TARGET_SRC_DIR      = $(CompSOC_ROOT)/hardware/CompSOC/cores/CompSOC
#LOCAL_CompSOC_SRCS  = $(notdir $(wildcard $(TARGET_SRC_DIR)/*.cpp)) $(notdir $(wildcard $(TARGET_SRC_DIR)/*.c))
#TARGET_SRCS         = $(filter-out main.cpp,$(LOCAL_CompSOC_SRCS)) $(CompSOC_LIBS)

ifeq ($(USERTOS),1)
TARGET_INC_DIR      += -I$(COMPSOC_SL)/RTOS
TARGET_SRCS         +=  $(wildcard $(COMPSOC_SL)/RTOS/*.c)
endif

# Here we add some CompSOC library files from different folders
#EXTRA_SRCS		=	$(TARGET_SRC_DIR)/avr-libc/malloc.c \
#                    $(TARGET_SRC_DIR)/avr-libc/realloc.c

# Add low-level communication for ExtMode
ifeq ($(EXT_MODE),1)
#EXTRA_SRCS		+= $(COMPSOC_SL)/rtiostream_serial.c
EXTRA_SRCS		+= $(COMPSOC_SL)/rtiostream_tcpip.c
endif 

TARGET_SRCS		+= $(notdir	$(EXTRA_SRCS))
VPATH			= $(sort $(dir $(EXTRA_SRCS)))

