function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["PIL_simulation_monitoring_app:7620"] = "PIL_simulation_monitoring_app:7619";
    this.sidParentMap["PIL_simulation_monitoring_app:7621"] = "PIL_simulation_monitoring_app:7619";
    this.sidParentMap["PIL_simulation_monitoring_app:7618"] = "PIL_simulation_monitoring_app:7619";
    this.sidParentMap["PIL_simulation_monitoring_app:7622"] = "PIL_simulation_monitoring_app:7619";
    this.sidParentMap["PIL_simulation_monitoring_app:7623"] = "PIL_simulation_monitoring_app:7619";
    this.sidParentMap["PIL_simulation_monitoring_app:7624"] = "PIL_simulation_monitoring_app:7619";
    this.sidParentMap["PIL_simulation_monitoring_app:7625"] = "PIL_simulation_monitoring_app:7619";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
