function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6780"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6781"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6782"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6783"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6784"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6785"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6786"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6787"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6678"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6679"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6680"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6681"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:7005"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.sidParentMap["SIL_Simulation_Parallel_Implementation:6788"] = "SIL_Simulation_Parallel_Implementation:6779";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
