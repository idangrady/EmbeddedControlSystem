function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/S-Function */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6990"] = "Subsystem.c:37,44";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem"};
	this.sidHashMap["Subsystem"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "SIL_Simulation_Parallel_Implementation:6992"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6992"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "SIL_Simulation_Parallel_Implementation:6993"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6993"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "SIL_Simulation_Parallel_Implementation:6990"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6990"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "SIL_Simulation_Parallel_Implementation:6994"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6994"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S1>/Out2"] = {sid: "SIL_Simulation_Parallel_Implementation:6995"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6995"] = {rtwname: "<S1>/Out2"};
	this.rtwnameHashMap["<S1>/Out3"] = {sid: "SIL_Simulation_Parallel_Implementation:6996"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6996"] = {rtwname: "<S1>/Out3"};
	this.rtwnameHashMap["<S1>/Out4"] = {sid: "SIL_Simulation_Parallel_Implementation:6997"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6997"] = {rtwname: "<S1>/Out4"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
