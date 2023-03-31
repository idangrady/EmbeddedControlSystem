
%% Sensing Task


def_hough = legacy_code('initialize');
def_hough.SourceFiles = {'sensing_task.c'};
def_hough.HeaderFiles = {'sensing_task.h'};
def_hough.SFunctionName = 'sensing_task_Sfunction';
def_hough.OutputFcnSpec = 'void sensing_task(uint8 u1[12496], int16 y1[1], int16 y2[1],int16 y3[1], int16 y4[1])';
def_hough.IncPaths = {'../../CompSOC_ec_target/files'};
legacy_code('sfcn_cmex_generate', def_hough);
legacy_code('sfcn_tlc_generate', def_hough);
legacy_code('compile', def_hough);
% legacy_code('slblock_generate', def_hough);

%% Merging Task
 
%  
def_merging = legacy_code('initialize');
def_merging.SourceFiles = {'merging_task.c'};
def_merging.HeaderFiles = {'merging_task.h'};
def_merging.SFunctionName = 'merging_task_Sfunction';
def_merging.OutputFcnSpec = 'single y1 = merging_task(int16 u1[1], int16 u2[1], int16 u3[1], int16 u4[1])';
def_merging.IncPaths = {'../../CompSOC_ec_target/files'};
legacy_code('sfcn_cmex_generate', def_merging);
legacy_code('sfcn_tlc_generate', def_merging);
legacy_code('compile', def_merging);
% legacy_code('slblock_generate', def_merging);
%% Controller Task
 

def_control = legacy_code('initialize');
def_control.SourceFiles = {'control.c'};
def_control.HeaderFiles = {'control.h'};
def_control.SFunctionName = 'controller_task_Sfunction';
def_control.OutputFcnSpec = 'single y1 =  PID_controller(single u1, single u2)';
def_control.IncPaths = {'../../CompSOC_ec_target/files'};
legacy_code('sfcn_cmex_generate', def_control);
legacy_code('sfcn_tlc_generate', def_control);
legacy_code('compile', def_control);
% legacy_code('slblock_generate', def_control);
