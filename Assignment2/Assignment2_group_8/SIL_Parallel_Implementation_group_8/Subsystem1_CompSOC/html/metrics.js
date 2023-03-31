function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["Err"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/control.c",
	size: 4};
	 this.metricsArray.var["dPart"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/control.c",
	size: 4};
	 this.metricsArray.var["iPart"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/control.c",
	size: 4};
	 this.metricsArray.var["pPart"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/control.c",
	size: 4};
	 this.metricsArray.var["prev_Err"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/control.c",
	size: 4};
	 this.metricsArray.var["rtM_"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/Subsystem1_CompSOC/Subsystem1.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/Subsystem1_CompSOC/Subsystem1.c",
	size: 8};
	 this.metricsArray.var["rtY"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/Subsystem1_CompSOC/Subsystem1.c",
	size: 4};
	 this.metricsArray.fcn["Subsystem1_initialize"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/Subsystem1_CompSOC/Subsystem1.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem1_step"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/Subsystem1_CompSOC/Subsystem1.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["abs"] = {file: "/opt/matlab/r2018b/sys/lcc/include/stdlib.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["controller_task"] = {file: "/home/computation/5lij0_ECS_Course_2023/SIL_Implementation/SIL_Parallel_Implementation/control.c",
	stack: 8,
	stackTotal: 8};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Subsystem1_metrics.html">Global Memory: 36(bytes) Maximum Stack: 8(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
