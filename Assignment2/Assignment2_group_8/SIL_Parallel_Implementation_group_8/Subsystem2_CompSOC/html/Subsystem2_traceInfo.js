function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/In1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7000"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7000";
	/* <S1>/S-Function1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6991"] = "Subsystem2.c:37";
	/* <S1>/Out1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7001"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7001";
	/* <S1>/Out2 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7002"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7002";
	/* <S1>/Out3 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7003"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7003";
	/* <S1>/Out4 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7004"] = "msg=&block=SIL_Simulation_Parallel_Implementation:7004";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem2"};
	this.sidHashMap["Subsystem2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "SIL_Simulation_Parallel_Implementation:6999"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6999"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "SIL_Simulation_Parallel_Implementation:7000"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7000"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/S-Function1"] = {sid: "SIL_Simulation_Parallel_Implementation:6991"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6991"] = {rtwname: "<S1>/S-Function1"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "SIL_Simulation_Parallel_Implementation:7001"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7001"] = {rtwname: "<S1>/Out1"};
	this.rtwnameHashMap["<S1>/Out2"] = {sid: "SIL_Simulation_Parallel_Implementation:7002"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7002"] = {rtwname: "<S1>/Out2"};
	this.rtwnameHashMap["<S1>/Out3"] = {sid: "SIL_Simulation_Parallel_Implementation:7003"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7003"] = {rtwname: "<S1>/Out3"};
	this.rtwnameHashMap["<S1>/Out4"] = {sid: "SIL_Simulation_Parallel_Implementation:7004"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7004"] = {rtwname: "<S1>/Out4"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
