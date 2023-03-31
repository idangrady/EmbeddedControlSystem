function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/In1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7008"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7008";
	/* <S1>/In2 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7009"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7009";
	/* <S1>/S-Function */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7006"] = "Subsystem1.c:37,45";
	/* <S1>/Out1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7010"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7010";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem1"};
	this.sidHashMap["Subsystem1"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "SIL_Simulation_Parallel_Implementation:7007"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7007"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "SIL_Simulation_Parallel_Implementation:7008"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7008"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "SIL_Simulation_Parallel_Implementation:7009"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7009"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "SIL_Simulation_Parallel_Implementation:7006"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7006"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "SIL_Simulation_Parallel_Implementation:7010"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7010"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
