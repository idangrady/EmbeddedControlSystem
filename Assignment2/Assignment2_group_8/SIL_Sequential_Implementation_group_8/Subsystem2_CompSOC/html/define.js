function CodeDefine() { 
this.def = new Array();
this.def["rtU"] = {file: "Subsystem2_c.html",line:25,type:"var"};this.def["rtY"] = {file: "Subsystem2_c.html",line:28,type:"var"};this.def["rtM_"] = {file: "Subsystem2_c.html",line:31,type:"var"};this.def["rtM"] = {file: "Subsystem2_c.html",line:32,type:"var"};this.def["Subsystem2_step"] = {file: "Subsystem2_c.html",line:35,type:"fcn"};this.def["Subsystem2_initialize"] = {file: "Subsystem2_c.html",line:51,type:"fcn"};this.def["RT_MODEL"] = {file: "Subsystem2_h.html",line:42,type:"type"};this.def["ExtU"] = {file: "Subsystem2_h.html",line:48,type:"type"};this.def["ExtY"] = {file: "Subsystem2_h.html",line:53,type:"type"};this.def["int8_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};this.def["uint8_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};this.def["int16_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};this.def["uint16_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};this.def["int32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};this.def["uint32_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};this.def["int64_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};this.def["uint64_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};this.def["real32_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};this.def["real64_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};this.def["real_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};this.def["time_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};this.def["boolean_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};this.def["int_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};this.def["uint_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};this.def["ulong_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};this.def["char_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};this.def["uchar_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};this.def["byte_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};this.def["creal32_T"] = {file: "rtwtypes_h.html",line:87,type:"type"};this.def["creal64_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};this.def["creal_T"] = {file: "rtwtypes_h.html",line:97,type:"type"};this.def["cint8_T"] = {file: "rtwtypes_h.html",line:104,type:"type"};this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:111,type:"type"};this.def["cint16_T"] = {file: "rtwtypes_h.html",line:118,type:"type"};this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:125,type:"type"};this.def["cint32_T"] = {file: "rtwtypes_h.html",line:132,type:"type"};this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:139,type:"type"};this.def["cint64_T"] = {file: "rtwtypes_h.html",line:146,type:"type"};this.def["cuint64_T"] = {file: "rtwtypes_h.html",line:153,type:"type"};this.def["pointer_T"] = {file: "rtwtypes_h.html",line:174,type:"type"};this.def["pPart"] = {file: "control_c.html",line:10,type:"var"};this.def["Err"] = {file: "control_c.html",line:11,type:"var"};this.def["PID_controller"] = {file: "control_c.html",line:13,type:"fcn"};this.def["uOverrunCounter"] = {file: "ert_main_c.html",line:25,type:"var"};this.def["GetOverrunCounter"] = {file: "ert_main_c.html",line:26,type:"fcn"};this.def["main"] = {file: "ert_main_c.html",line:33,type:"fcn"};}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "/";
var isPC = false;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["Subsystem2_c.html"] = "../Subsystem2.c";
	this.html2Root["Subsystem2_c.html"] = "Subsystem2_c.html";
	this.html2SrcPath["Subsystem2_h.html"] = "../Subsystem2.h";
	this.html2Root["Subsystem2_h.html"] = "Subsystem2_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["control_c.html"] = "../../control.c";
	this.html2Root["control_c.html"] = "control_c.html";
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"Subsystem2_c.html","Subsystem2_h.html","rtwtypes_h.html","control_c.html","ert_main_c.html"];
