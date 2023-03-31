%% Monitor app
def_monitor = legacy_code('initialize');
def_monitor.SourceFiles = {'monitor_app.c', 'memory_access.c'};
def_monitor.HeaderFiles = {'monitor_app.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_monitor.SFunctionName = 'monitor_app_block_pipe';
def_monitor.IncPaths = {'../../CompSOC_ec_target/files'};
def_monitor.OutputFcnSpec = 'void monitor(uint8 u1[12496], single y1[1], uint8 y2[1], uint32 u2[1], single y3[2])';
legacy_code('sfcn_cmex_generate', def_monitor);
legacy_code('sfcn_tlc_generate', def_monitor);
legacy_code('compile', def_monitor);
% legacy_code('slblock_generate', def_monitor);

%% Sensing task 1
def_sensing = legacy_code('initialize');
def_sensing.SourceFiles = {'sensing_task_1.c', 'memory_access.c'};
def_sensing.HeaderFiles = {'sensing_task.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_sensing.SFunctionName = 'sensing_block_1';
def_sensing.IncPaths = {'../../CompSOC_ec_target/files'};
def_sensing.OutputFcnSpec = 'void hough_transform()';
legacy_code('sfcn_cmex_generate', def_sensing);
legacy_code('sfcn_tlc_generate', def_sensing);
legacy_code('compile', def_sensing);

%% Sensing task 2
def_sensing = legacy_code('initialize');
def_sensing.SourceFiles = {'sensing_task_2.c', 'memory_access.c'};
def_sensing.HeaderFiles = {'sensing_task.h', 'memory_access.h', 'config.h', 'mapping.h'};
def_sensing.SFunctionName = 'sensing_block_2';
def_sensing.IncPaths = {'../../CompSOC_ec_target/files'};
def_sensing.OutputFcnSpec = 'void hough_transform()';
legacy_code('sfcn_cmex_generate', def_sensing);
legacy_code('sfcn_tlc_generate', def_sensing);
legacy_code('compile', def_sensing);
