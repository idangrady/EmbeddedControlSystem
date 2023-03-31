function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7483"] = "SIL_Simulation_Sequential_Implementation:7482";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7484"] = "SIL_Simulation_Sequential_Implementation:7482";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7481"] = "SIL_Simulation_Sequential_Implementation:7482";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7485"] = "SIL_Simulation_Sequential_Implementation:7482";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
