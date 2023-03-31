function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["PIL_simulation_monitoring_app:7483"] = "PIL_simulation_monitoring_app:7482";
    this.sidParentMap["PIL_simulation_monitoring_app:7484"] = "PIL_simulation_monitoring_app:7482";
    this.sidParentMap["PIL_simulation_monitoring_app:7481"] = "PIL_simulation_monitoring_app:7482";
    this.sidParentMap["PIL_simulation_monitoring_app:7485"] = "PIL_simulation_monitoring_app:7482";
    this.sidParentMap["PIL_simulation_monitoring_app:7486"] = "PIL_simulation_monitoring_app:7482";
    this.sidParentMap["PIL_simulation_monitoring_app:7487"] = "PIL_simulation_monitoring_app:7482";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
