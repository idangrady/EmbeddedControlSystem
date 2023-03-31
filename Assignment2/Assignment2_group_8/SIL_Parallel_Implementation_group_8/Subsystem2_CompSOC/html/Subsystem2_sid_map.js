function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7000"] = "SIL_Simulation_Parallel_Implementation:6999";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6991"] = "SIL_Simulation_Parallel_Implementation:6999";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7001"] = "SIL_Simulation_Parallel_Implementation:6999";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7002"] = "SIL_Simulation_Parallel_Implementation:6999";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7003"] = "SIL_Simulation_Parallel_Implementation:6999";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7004"] = "SIL_Simulation_Parallel_Implementation:6999";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
