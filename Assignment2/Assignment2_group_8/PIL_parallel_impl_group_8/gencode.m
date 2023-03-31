
%% Monitor app
def_monitor = legacy_code('initialize');
def_monitor.SourceFiles = {'monitor_app.c', 'memory_access.c'};
def_monitor.HeaderFiles = {'monitor_app.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_monitor.SFunctionName = 'monitor_app_block';
def_monitor.IncPaths = {'../../CompSOC_ec_target/files'};
def_monitor.OutputFcnSpec = 'void monitor(uint8 u1[12496], single y1[1],  uint8 y2[1], uint32 u2[1], single y3[1], uint32 y4[1])';
legacy_code('sfcn_cmex_generate', def_monitor);
legacy_code('sfcn_tlc_generate', def_monitor);
legacy_code('compile', def_monitor);
% legacy_code('slblock_generate', def_monitor);

%% Sensing task1
def_sensing1 = legacy_code('initialize');
def_sensing1.SourceFiles = {'sensing_task1.c', 'memory_access.c'};
def_sensing1.HeaderFiles = {'sensing_task1.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_sensing1.SFunctionName = 'sensing_task1_block';
def_sensing1.IncPaths = {'../../CompSOC_ec_target/files'};
def_sensing1.OutputFcnSpec = 'void hough_transform()';
legacy_code('sfcn_cmex_generate', def_sensing1);
legacy_code('sfcn_tlc_generate', def_sensing1);
legacy_code('compile', def_sensing1);
% legacy_code('slblock_generate', def_sensing1);
%%
%% Sensing task2
def_sensing2 = legacy_code('initialize');
def_sensing2.SourceFiles = {'sensing_task2.c', 'memory_access.c'};
def_sensing2.HeaderFiles = {'sensing_task2.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_sensing2.SFunctionName = 'sensing_task2_block';
def_sensing2.IncPaths = {'../../CompSOC_ec_target/files'};
def_sensing2.OutputFcnSpec = 'void hough_transform()';
legacy_code('sfcn_cmex_generate', def_sensing2);
legacy_code('sfcn_tlc_generate', def_sensing2);
legacy_code('compile', def_sensing2);
% legacy_code('slblock_generate', def_sensing2);

%% MERGING app

def_merging = legacy_code('initialize');
def_merging.SourceFiles = {'merging_task.c', 'memory_access.c'};
def_merging.HeaderFiles = {'merging_task.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_merging.SFunctionName = 'merging_pos_task';
def_merging.IncPaths = {'../../CompSOC_ec_target/files'};
def_merging.OutputFcnSpec = 'void merging_task()';
legacy_code('sfcn_cmex_generate', def_merging);
legacy_code('sfcn_tlc_generate', def_merging);
legacy_code('compile', def_merging);
% legacy_code('slblock_generate', def_merging);

%% Controller app

def_control = legacy_code('initialize');
def_control.SourceFiles = {'control.c', 'memory_access.c'};
def_control.HeaderFiles = {'control.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_control.SFunctionName = 'generate_control_input';
def_control.IncPaths = {'../../CompSOC_ec_target/files'};
def_control.OutputFcnSpec = 'void PID_controller()';
legacy_code('sfcn_cmex_generate', def_control);
legacy_code('sfcn_tlc_generate', def_control);
legacy_code('compile', def_control);
% legacy_code('slblock_generate', def_control);

