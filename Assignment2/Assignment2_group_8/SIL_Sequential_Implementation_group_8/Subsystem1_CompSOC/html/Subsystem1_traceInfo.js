function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/In1 */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7476"] = "msg=&block=SIL_Simulation_Sequential_Implementation:7476";
	/* <S1>/In2 */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7477"] = "msg=&block=SIL_Simulation_Sequential_Implementation:7477";
	/* <S1>/In3 */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7478"] = "msg=&block=SIL_Simulation_Sequential_Implementation:7478";
	/* <S1>/In4 */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7479"] = "msg=&block=SIL_Simulation_Sequential_Implementation:7479";
	/* <S1>/S-Function */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7474"] = "Subsystem1.c:37,49";
	/* <S1>/Out1 */
	this.urlHashMap["SIL_Simulation_Sequential_Implementation:7480"] = "msg=&block=SIL_Simulation_Sequential_Implementation:7480";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem1"};
	this.sidHashMap["Subsystem1"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "SIL_Simulation_Sequential_Implementation:7475"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7475"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "SIL_Simulation_Sequential_Implementation:7476"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7476"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "SIL_Simulation_Sequential_Implementation:7477"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7477"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/In3"] = {sid: "SIL_Simulation_Sequential_Implementation:7478"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7478"] = {rtwname: "<S1>/In3"};
	this.rtwnameHashMap["<S1>/In4"] = {sid: "SIL_Simulation_Sequential_Implementation:7479"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7479"] = {rtwname: "<S1>/In4"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "SIL_Simulation_Sequential_Implementation:7474"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7474"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "SIL_Simulation_Sequential_Implementation:7480"};
	this.sidHashMap["SIL_Simulation_Sequential_Implementation:7480"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
