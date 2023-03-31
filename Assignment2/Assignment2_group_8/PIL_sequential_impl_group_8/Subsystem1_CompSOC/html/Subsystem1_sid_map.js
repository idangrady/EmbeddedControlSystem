function RTW_SidParentMap() {
    this.sidParentMap = new Array();
    this.sidParentMap["PIL_simulation_monitoring_app:6777"] = "PIL_simulation_monitoring_app:6776";
    this.sidParentMap["PIL_simulation_monitoring_app:6778"] = "PIL_simulation_monitoring_app:6776";
    this.sidParentMap["PIL_simulation_monitoring_app:6775"] = "PIL_simulation_monitoring_app:6776";
    this.sidParentMap["PIL_simulation_monitoring_app:6779"] = "PIL_simulation_monitoring_app:6776";
    this.sidParentMap["PIL_simulation_monitoring_app:6780"] = "PIL_simulation_monitoring_app:6776";
    this.sidParentMap["PIL_simulation_monitoring_app:6781"] = "PIL_simulation_monitoring_app:6776";
    this.getParentSid = function(sid) { return this.sidParentMap[sid];}
}
    RTW_SidParentMap.instance = new RTW_SidParentMap();
