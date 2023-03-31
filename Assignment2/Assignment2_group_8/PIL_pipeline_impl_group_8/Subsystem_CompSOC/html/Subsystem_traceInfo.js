function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/S-Function */
	this.urlHashMap["PIL_simulation_monitoring_app:7481"] = "Subsystem.c:37,44,45";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem"};
	this.sidHashMap["Subsystem"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "PIL_simulation_monitoring_app:7482"};
	this.sidHashMap["PIL_simulation_monitoring_app:7482"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "PIL_simulation_monitoring_app:7483"};
	this.sidHashMap["PIL_simulation_monitoring_app:7483"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "PIL_simulation_monitoring_app:7484"};
	this.sidHashMap["PIL_simulation_monitoring_app:7484"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "PIL_simulation_monitoring_app:7481"};
	this.sidHashMap["PIL_simulation_monitoring_app:7481"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "PIL_simulation_monitoring_app:7485"};
	this.sidHashMap["PIL_simulation_monitoring_app:7485"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S1>/Out2"] = {sid: "PIL_simulation_monitoring_app:7486"};
	this.sidHashMap["PIL_simulation_monitoring_app:7486"] = {rtwname: "<S1>/Out2"};
	this.rtwnameHashMap["<S1>/Out3"] = {sid: "PIL_simulation_monitoring_app:7487"};
	this.sidHashMap["PIL_simulation_monitoring_app:7487"] = {rtwname: "<S1>/Out3"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
