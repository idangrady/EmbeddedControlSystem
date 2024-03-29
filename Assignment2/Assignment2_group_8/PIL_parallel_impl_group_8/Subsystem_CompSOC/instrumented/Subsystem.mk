 # Embedded Coder Template Makefile
#
# - You can use this template makefile as the basis for your own
#   custom target including support for Processor-in-the-Loop (PIL).
# - The intent is that you should not have to modify this example
#   template makefile to create your own PIL implementation.
# - The embedded tooling information is abstracted into a separate
#   file, target_tools.mk.
# - To create a custom target for your own processor, you will
#   need to modify the target_tools.mk to specify the appropriate
#   embedded tools and options.
#
# Copyright 2009-2014 The MathWorks, Inc.

#------------------------ Macros read by make_rtw ------------------------------
MAKECMD         = /usr/bin/make
HOST                = ANY
BUILD               = yes
SYS_TARGET_FILE     = any
COMPILER_TOOL_CHAIN = default
MAKEFILE_FILESEP = /
#---------------------- Tokens expanded by make_rtw ----------------------------
MODEL                   = Subsystem
MODULES                 = monitor_app.c memory_access.c coder_profile_timer.c
MAKEFILE                = Subsystem.mk
MATLAB_ROOT             = /opt/matlab/r2018b
ALT_MATLAB_ROOT         = /opt/matlab/r2018b
MASTER_ANCHOR_DIR       = 
START_DIR               = /home/computation/5lij0_ECS_Course_2023/PIL_Implementation/PIL_parallel_impl
S_FUNCTIONS             = 
S_FUNCTIONS_LIB         = 
NUMST                   = 1
NCSTATES                = 0
COMPUTER                = GLNXA64
BUILDARGS               =  GENERATE_ASAP2=0 DOWNLOAD_TO_COMPSOC=0 DIALOG_OPTIONS="" ALTERNATIVE_GCC="" PROCESSOR_TILE=0 ISPROTECTINGMODEL=NOTPROTECTING STANDALONE_SUPPRESS_EXE=1
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 0
ONESTEPFCN              = 1
TERMFCN                 = 0
B_ERTSFCN               = 0
MEXEXT                  = mexa64
EXT_MODE                = 0
TMW_EXTMODE_TESTING     = 0
EXTMODE_TRANSPORT       = 0
EXTMODE_STATIC          = 1
EXTMODE_STATIC_SIZE     = 9200
MULTI_INSTANCE_CODE     = 0
TGT_FCN_LIB             = ISO_C
MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
GEN_SAMPLE_MAIN         = 1
TARGET_LANG_EXT         = c
PORTABLE_WORDSIZES      = 0
SHRLIBTARGET            = 0
OPTIMIZATION_FLAGS      = 
ADDITIONAL_LDFLAGS      = 
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = Subsystemlib.a
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ../..
MODELREF_TARGET_TYPE      = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif


#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE #-DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c
    EXT_LIB = $(MATLAB_ROOT)\sys\lcc\lib\wsock32.lib
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c rtiostream_serial_interface.c # rtiostream_serial.c
    #EXT_SRC = ext_svr.c updown.c ext_work.c rtiostream_interface.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif


#------------------ Include a tool specification settings -----------------
# TARGET_INCS - include options for the target source files (e.g. -I$(TARGET_INC_DIR))
# TARGET_SRCS - a list of the target source files
# CC - C compiler command
# CFLAGS - C compiler options
# CDEBUG - C compiler debug option
# CCOUTPUTFLAG - C compiler output option (e.g. -o)
# OBJ_EXT - object file extension
# CXX - C++ compiler command
# CXXFLAGS - C++ compiler options
# CXXDEBUG - C++ compiler debug option
# LD - linker command
# LDFLAGS - linker options
# LDDEBUG - linker debug option
# LDOUTPUTFLAG - linker output option (e.g. -o)
# PROGRAM_FILE_EXT - linker output file extension (e.g .elf)
# AR - Archiver command
# ARFLAGS - Archiver options
# OBJCOPY - Binary file format converter command
# OBJCOPYFLAGS - Binary file format converter options
# BINARY_FILE_EXT - Binary file extension (e.g. .hex or .mot)
# EXE_FILE_EXT = $(BINARY_FILE_EXT) or $(PROGRAM_FILE_EXT) - build product ext.

include $(START_DIR)/slprj/target_tools.mk

#------------------------------ Includes -------------------------------------
# Place -I options here
MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/rtw/c/ert \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# Additional includes
ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/Subsystem_CompSOC/instrumented \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \
	-I$(MATLAB_ROOT)/rtw/c/ert \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) \
           $(ADD_INCLUDES) $(MODELREF_INC_PATH) $(SHARED_INCLUDES) \
           $(TARGET_INCS)


CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE)

OPTS=
CFLAGS += $(OPTS) $(CPP_REQ_DEFINES) $(EXT_CC_OPTS)
CXXFLAGS +=	$(OPTS) $(CPP_REQ_DEFINES) $(EXT_CC_OPTS)


CFLAGS += $(INCLUDES)
CXXFLAGS += $(INCLUDES)

ifeq ($(DEBUG_BUILD),1)
# Set flags for debugging
CFLAGS += $(CDEBUG)
CXXFLAGS += $(CXXDEBUG)
LDFLAGS += $(LDDEBUG)
endif
#-------------------------------- Target application --------------------------------------
# Define the type of build


ifeq ($(MODELREF_TARGET_TYPE), NONE)
ifeq ($(MAKEFILEBUILDER_TGT), 0)
ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
# Build object code only for top level model (preliminary step for building
# PIL application)
BUILD_MODE=pil_prebuild
PRODUCT=ObjectModules
BUILD_PRODUCT_TYPE = object modules
else
# Building executable for real-time deployment
BUILD_MODE=real_time
PRODUCT = $(MODEL)$(EXE_FILE_EXT)
BUILD_PRODUCT_TYPE = executable
endif
else
# Building executable for deployment as PIL application (non-real-time
# simulation)
BUILD_MODE=pil_application
PRODUCT = $(MODEL)$(EXE_FILE_EXT)
BUILD_PRODUCT_TYPE = executable
endif
else
# Building a library for a referenced model
BUILD_MODE = model_reference
PRODUCT = $(MODELLIB)
BUILD_PRODUCT_TYPE = library
endif

#-------------- Source Files, Object Files and Dependency Files -----------

SRCS = $(ADD_SRCS) $(S_FUNCTIONS)

ifeq ($(BUILD_MODE), pil_prebuild)
  SRCS += $(MODULES) $(MODEL).$(TARGET_LANG_EXT) $(EXT_SRC)
endif

ifeq ($(BUILD_MODE), pil_application)
  SRCS += $(TARGET_SRCS)
  PREBUILT_SRCS      = $(MODULES)
  PREBUILT_OBJS      = $(addsuffix $(OBJ_EXT), $(basename $(PREBUILT_SRCS)))
endif

ifeq ($(BUILD_MODE), real_time)
  SRCS += $(MODULES) $(MODEL).$(TARGET_LANG_EXT) $(EXT_SRC) ert_main.c
  SRCS += $(TARGET_SRCS)
endif

ifeq ($(BUILD_MODE), model_reference)
  SRCS += $(MODULES)
endif

USER_SRCS =

USER_OBJS       = $(addsuffix $(OBJ_EXT), $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(addsuffix $(OBJ_EXT), $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix $(OBJ_EXT), $(basename $(SRCS))) $(LOCAL_USER_OBJS) $(PREBUILT_OBJS)

LIBS = $(S_FUNCTIONS_LIB)

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix $(OBJ_EXT), $(basename $(SHARED_SRC)))

#-------------- Default target -----------
TARGETS = $(PRODUCT)

all: $(TARGETS)

# Need a rule to generate the build success string if product was already up to date
.PHONY : all
all : $(PRODUCT)
	echo ### Created $(PRODUCT) successfully (or it was already up to date)

#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_LIB) : $(SHARED_OBJS)
	echo ### Creating $@
	@$(AR) $(ARFLAGS) $@ $(SHARED_OBJS)
	echo ### $@ Created

##-------------------------- Support for building modules ----------------------
ifeq ($(BUILD_MODE), pil_prebuild)
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	echo ### BUILD_MODE $(BUILD_MODE)
	echo ### Created $(PRODUCT)
endif

ifeq ($(BUILD_MODE), real_time)
$(PRODUCT) : $(MODEL)$(PROGRAM_FILE_EXT)
	@$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
	echo ### Generated $(PRODUCT)
	echo ### Project size
	@$(SIZE) $<
	@$(SIZE) $< >code_size_$(TARGET_LANG_EXT).txt
	@$(OBJDUMP) $(OBJDUMPFLAGS) $< > disassembly.txt
endif

ifeq ($(BUILD_MODE), pil_application)
$(PRODUCT) : $(MODEL)$(PROGRAM_FILE_EXT)
	echo ### BUILD_MODE $(BUILD_MODE)
	@$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
	echo ### Generated $(PRODUCT)
	echo ### Project size
	@$(SIZE) $<
	@$(OBJDUMP) $(OBJDUMPFLAGS) $< > disassembly.txt
endif

ifeq ($(BUILD_MODE), model_reference)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS)
	echo ### BUILD_MODE $(BUILD_MODE)
	echo ### Creating library ...
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	echo ### Generated $@
endif

ifeq ($(BUILD_MODE), pil_application)
$(MODEL)$(PROGRAM_FILE_EXT): $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS)
	echo ### BUILD_MODE $(BUILD_MODE)
	@$(AR) $(ARFLAGS) core.a $(filter-out pil_main.o,$^)
	@$(LD) pil_main.o core.a $(filter-out %.o,$^) $(LDFLAGS) $(LDOUTPUTFLAG) $@
	echo ### Generated $@
endif

ifeq ($(BUILD_MODE), real_time)
$(MODEL)$(PROGRAM_FILE_EXT): $(OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS)
	echo ### BUILD_MODE $(BUILD_MODE)
	@$(AR) $(ARFLAGS) core.a $(filter-out ert_main.o,$^)
	@$(LD) ert_main.o core.a $(LDFLAGS) $(filter-out %.o,$^) $(SHARED_LIB) $(LDOUTPUTFLAG) $@
	echo ### Generated $@
endif

%$(OBJ_EXT) : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	echo Compiling: $<
	@$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT): $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	echo Compiling: $<
	@$(CXX) -c $(CXXFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT): %.cpp
	echo Compiling: $<
	@$(CXX) -c $(CXXFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT): %.c
	echo Compiling: $<
	@$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT): $(TARGET_SRC_DIR)/%.cpp
	echo Compiling: $<
	@$(CXX) -c $(CXXFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT): $(TARGET_SRC_DIR)/%.c
	echo Compiling: $<
	@$(CC) -c $(CFLAGS) $< $(CCOUTPUTFLAG) $@

%$(OBJ_EXT) : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	echo Compiling: $<
	@$(CXX) -c $(CXXFLAGS) $<

%$(OBJ_EXT) : $(MATLAB_ROOT)/simulink/src/%.cpp
	echo Compiling: $<
	@$(CXX) -c $(CXXFLAGS) $<



%$(OBJ_EXT) : $(MATLAB_ROOT)/rtw/c/src/%.c
	echo Compiling: $<
	@$(CC) -c $(CFLAGS) $<

%$(OBJ_EXT) : $(MATLAB_ROOT)/simulink/src/%.c
	echo Compiling: $<
	@$(CC) -c $(CFLAGS) $<


