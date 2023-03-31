function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7008"] = "SIL_Simulation_Parallel_Implementation:7007";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7009"] = "SIL_Simulation_Parallel_Implementation:7007";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7006"] = "SIL_Simulation_Parallel_Implementation:7007";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7010"] = "SIL_Simulation_Parallel_Implementation:7007";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
