function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/S-Function */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7481"] = "Subsystem2.c:37,45,47";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem2"};
	this.sidHashMap["Subsystem2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "SIL_Simulation_Sequential_Implementation:7482"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7482"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "SIL_Simulation_Sequential_Implementation:7483"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7483"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "SIL_Simulation_Sequential_Implementation:7484"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7484"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "SIL_Simulation_Sequential_Implementation:7481"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7481"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "SIL_Simulation_Sequential_Implementation:7485"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7485"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
