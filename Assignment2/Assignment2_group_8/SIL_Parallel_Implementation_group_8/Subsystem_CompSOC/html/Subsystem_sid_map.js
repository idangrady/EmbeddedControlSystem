function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6993"] = "SIL_Simulation_Parallel_Implementation:6992";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6990"] = "SIL_Simulation_Parallel_Implementation:6992";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6994"] = "SIL_Simulation_Parallel_Implementation:6992";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6995"] = "SIL_Simulation_Parallel_Implementation:6992";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6996"] = "SIL_Simulation_Parallel_Implementation:6992";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6997"] = "SIL_Simulation_Parallel_Implementation:6992";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
