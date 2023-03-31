function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/S-Function */
	this.urlHashMap["PIL_simulation_monitoring_app:6775"] = "Subsystem1.c:37,44,45";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem1"};
	this.sidHashMap["Subsystem1"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "PIL_simulation_monitoring_app:6776"};
	this.sidHashMap["PIL_simulation_monitoring_app:6776"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "PIL_simulation_monitoring_app:6777"};
	this.sidHashMap["PIL_simulation_monitoring_app:6777"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "PIL_simulation_monitoring_app:6778"};
	this.sidHashMap["PIL_simulation_monitoring_app:6778"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "PIL_simulation_monitoring_app:6775"};
	this.sidHashMap["PIL_simulation_monitoring_app:6775"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "PIL_simulation_monitoring_app:6779"};
	this.sidHashMap["PIL_simulation_monitoring_app:6779"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S1>/Out2"] = {sid: "PIL_simulation_monitoring_app:6780"};
	this.sidHashMap["PIL_simulation_monitoring_app:6780"] = {rtwname: "<S1>/Out2"};
	this.rtwnameHashMap["<S1>/Out3"] = {sid: "PIL_simulation_monitoring_app:6781"};
	this.sidHashMap["PIL_simulation_monitoring_app:6781"] = {rtwname: "<S1>/Out3"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
