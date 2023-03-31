function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7462"] = "SIL_Simulation_Sequential_Implementation:7461";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7458"] = "SIL_Simulation_Sequential_Implementation:7461";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7463"] = "SIL_Simulation_Sequential_Implementation:7461";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7464"] = "SIL_Simulation_Sequential_Implementation:7461";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7465"] = "SIL_Simulation_Sequential_Implementation:7461";
    this.sidParentMap["SIL_Simulation_Sequential_Implementation:7466"] = "SIL_Simulation_Sequential_Implementation:7461";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
