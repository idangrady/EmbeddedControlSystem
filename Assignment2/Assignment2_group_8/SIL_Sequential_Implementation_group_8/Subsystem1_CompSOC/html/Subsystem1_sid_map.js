function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7476"] = "SIL_Simulation_Sequential_Implementation:7475";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7477"] = "SIL_Simulation_Sequential_Implementation:7475";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7478"] = "SIL_Simulation_Sequential_Implementation:7475";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7479"] = "SIL_Simulation_Sequential_Implementation:7475";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7474"] = "SIL_Simulation_Sequential_Implementation:7475";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7480"] = "SIL_Simulation_Sequential_Implementation:7475";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
