function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/S-Function */
	this.urlHashMap["PIL_simulation_monitoring_app:7618"] = "Subsystem.c:37,45,46";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem"};
	this.sidHashMap["Subsystem"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "PIL_simulation_monitoring_app:7619"};
	this.sidHashMap["PIL_simulation_monitoring_app:7619"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "PIL_simulation_monitoring_app:7620"};
	this.sidHashMap["PIL_simulation_monitoring_app:7620"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "PIL_simulation_monitoring_app:7621"};
	this.sidHashMap["PIL_simulation_monitoring_app:7621"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "PIL_simulation_monitoring_app:7618"};
	this.sidHashMap["PIL_simulation_monitoring_app:7618"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "PIL_simulation_monitoring_app:7622"};
	this.sidHashMap["PIL_simulation_monitoring_app:7622"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S1>/Out2"] = {sid: "PIL_simulation_monitoring_app:7623"};
	this.sidHashMap["PIL_simulation_monitoring_app:7623"] = {rtwname: "<S1>/Out2"};
	this.rtwnameHashMap["<S1>/Out3"] = {sid: "PIL_simulation_monitoring_app:7624"};
	this.sidHashMap["PIL_simulation_monitoring_app:7624"] = {rtwname: "<S1>/Out3"};
	this.rtwnameHashMap["<S1>/Out4"] = {sid: "PIL_simulation_monitoring_app:7625"};
	this.sidHashMap["PIL_simulation_monitoring_app:7625"] = {rtwname: "<S1>/Out4"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
