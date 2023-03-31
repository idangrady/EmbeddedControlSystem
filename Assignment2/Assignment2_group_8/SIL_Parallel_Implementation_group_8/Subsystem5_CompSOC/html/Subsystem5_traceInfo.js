function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/In1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6780"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6780";
	/* <S1>/In2 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6781"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6781";
	/* <S1>/In3 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6782"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6782";
	/* <S1>/In4 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6783"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6783";
	/* <S1>/In5 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6784"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6784";
	/* <S1>/In6 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6785"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6785";
	/* <S1>/In7 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6786"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6786";
	/* <S1>/In8 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6787"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6787";
	/* <S1>/Add */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6678"] = "Subsystem5.c:42";
	/* <S1>/Add1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6679"] = "Subsystem5.c:48";
	/* <S1>/Add2 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6680"] = "Subsystem5.c:54";
	/* <S1>/Add3 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6681"] = "Subsystem5.c:60";
	/* <S1>/S-Function */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:7005"] = "Subsystem5.c:66,69";
	/* <S1>/Out1 */
	this.urlHashMap["SIL_Simulation_Parallel_Implementation:6788"] = "msg=&block=SIL_Simulation_Parallel_Implementation:6788";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem5"};
	this.sidHashMap["Subsystem5"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "SIL_Simulation_Parallel_Implementation:6779"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6779"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "SIL_Simulation_Parallel_Implementation:6780"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6780"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "SIL_Simulation_Parallel_Implementation:6781"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6781"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/In3"] = {sid: "SIL_Simulation_Parallel_Implementation:6782"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6782"] = {rtwname: "<S1>/In3"};
	this.rtwnameHashMap["<S1>/In4"] = {sid: "SIL_Simulation_Parallel_Implementation:6783"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6783"] = {rtwname: "<S1>/In4"};
	this.rtwnameHashMap["<S1>/In5"] = {sid: "SIL_Simulation_Parallel_Implementation:6784"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6784"] = {rtwname: "<S1>/In5"};
	this.rtwnameHashMap["<S1>/In6"] = {sid: "SIL_Simulation_Parallel_Implementation:6785"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6785"] = {rtwname: "<S1>/In6"};
	this.rtwnameHashMap["<S1>/In7"] = {sid: "SIL_Simulation_Parallel_Implementation:6786"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6786"] = {rtwname: "<S1>/In7"};
	this.rtwnameHashMap["<S1>/In8"] = {sid: "SIL_Simulation_Parallel_Implementation:6787"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6787"] = {rtwname: "<S1>/In8"};
	this.rtwnameHashMap["<S1>/Add"] = {sid: "SIL_Simulation_Parallel_Implementation:6678"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6678"] = {rtwname: "<S1>/Add"};
	this.rtwnameHashMap["<S1>/Add1"] = {sid: "SIL_Simulation_Parallel_Implementation:6679"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6679"] = {rtwname: "<S1>/Add1"};
	this.rtwnameHashMap["<S1>/Add2"] = {sid: "SIL_Simulation_Parallel_Implementation:6680"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6680"] = {rtwname: "<S1>/Add2"};
	this.rtwnameHashMap["<S1>/Add3"] = {sid: "SIL_Simulation_Parallel_Implementation:6681"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6681"] = {rtwname: "<S1>/Add3"};
	this.rtwnameHashMap["<S1>/S-Function"] = {sid: "SIL_Simulation_Parallel_Implementation:7005"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:7005"] = {rtwname: "<S1>/S-Function"};
	this.rtwnameHashMap["<S1>/Out1"] = {sid: "SIL_Simulation_Parallel_Implementation:6788"};
	this.sidHashMap["SIL_Simulation_Parallel_Implementation:6788"] = {rtwname: "<S1>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
