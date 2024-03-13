from generator.config import config
from gen.cores import app_cores, app_core0, app_core1
from generator import globals as gr

global config
global app_cores, app_core0, app_core1
global resource_core0, resource_core1

gr.genfile = open(gr.src_path+"resource_Cfg.c",'w')

core0_general_resources = []
core1_general_resources = []

core0_internal_resources = []
core1_internal_resources = []

priority = {}




gr.printFile("#include \"resource_Cfg.h\"")
# /* separate the general resources and internal resources */
resources = config.getList("/AUTOSAR","OsResource")
for resource in resources:
    resourceproperty = config.getValue("/AUTOSAR/" + resource, "OsResourceProperty")
    app = config.getList("/AUTOSAR/" + resource ,"OsResourceAccessingApplication")
    if app_cores[app[0]] == "OS_CORE_ID_0":
        if resourceproperty==""or resourceproperty=="STANDARD":
            core0_general_resources.append(resource)
        elif resourceproperty=="INTERNAL":
            core0_internal_resources.append(resource)

    else:
        if resourceproperty==""or resourceproperty=="STANDARD":
            core1_general_resources.append(resource)
        elif resourceproperty=="INTERNAL":
            core1_internal_resources.append(resource)

    task_ref = []
    application = config.getList("/AUTOSAR/" + resource, "OsResourceAccessingApplication")
    
    if len(application)>0:
        for i in range(len(application)):
            tasks = config.getList("/AUTOSAR/" + application[i], "OsAppTaskRef")
            if len(tasks)>0:
                for i in range(len(tasks)):
                    ref = config.getValue("/AUTOSAR/" + tasks[i], "OsTaskPriority")
                    task_ref.append(ref)
    task_ref = set(task_ref)
    task_ref = list(task_ref)
      
    if task_ref != "":
        priority["{}".format(resource)] = len(task_ref)

os = config.getValue("/AUTOSAR","OsOS")
schedulerpolicy = config.getValue("/AUTOSAR/" + os,"OsUseResScheduler")


#/* Resources Priorities */
tasks = config.getList("/AUTOSAR", "OsTASK")
intnames = config.getList("/AUTOSAR", "OsISR")

for int in intnames:
    intcat = config.getValue("/AUTOSAR/" + int,"OsIsrCategory")
    if intcat == 2:
        tasks.append(int)


if(len(core0_general_resources)>0 or schedulerpolicy=="TRUE"):
    gr.printFile ("/* brief Resources Priorities */")
    gr.printFile ("const TaskPriorityType ResourcesPriority_core0[RESOURCES_COUNT_CORE0] = {")
    if(schedulerpolicy=="TRUE"):
        Res_Scheduler_Priority = 0
        for resource in core0_general_resources:
            if Res_Scheduler_Priority < priority["{}".format(resource)]:
                Res_Scheduler_Priority = priority["{}".format(resource)]                   
            gr.printFile ("    {},".format( Res_Scheduler_Priority ) )
    
    resource_count = 0
    for resource in core0_general_resources:
        resource_count += 1
        gr.printFile ("    {},".format(priority["{}".format(resource)]))
    for app in app_core0:
        gr.printFile ("    {},".format(priority["{}".format(resource)]))
    gr.printFile ("};\n")

if(len(core0_general_resources)>0 or schedulerpolicy=="TRUE"):
    gr.printFile ("/* Brief ResourceVar Array */")
    gr.printFile ("ResourceVarType ResourceVar_core0[RESOURCES_COUNT_CORE0] = {\n")
    
    if(schedulerpolicy=="TRUE"):
        resource = "RES_SCHEDULER_core0"
        gr.printFile ("    /* General resource {} */".format(resource))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */")
        gr.printFile ("        &ResourcesPriority_core0[({} & 0xffff)], /* celingPriority */".format(resource))
        gr.printFile ("        0,                            /* previousPriority */")
        gr.printFile ("        0,                            /* owner */")
        gr.printFile ("        "+ resource +",                    /* id */")
        gr.printFile ("    },")
    
    for resource in core0_general_resources:
        gr.printFile ("    /* General resource {} */".format(resource))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */")
        gr.printFile ("        &ResourcesPriority_core0[({} & 0xffff)], /* celingPriority */".format(resource))
        gr.printFile ("        0,                            /* previousPriority */")
        gr.printFile ("        0,                            /* owner */")
        gr.printFile ("        " + resource + ",                    /* id */")
        gr.printFile ("    },")
    
    for app in app_core0:
        gr.printFile ("    /* Sys resource resource{} */".format(app))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */")
        gr.printFile ("        &ResourcesPriority_core0[(resource{} & 0xffff)], /* celingPriority */".format(app))
        gr.printFile ("        0,                            /* previousPriority */")
        gr.printFile ("        0,                            /* owner */")
        gr.printFile ("        resource{}                            /* id */".format(app))
        gr.printFile ("    },")

    gr.printFile ("};\n")



if(len(core1_general_resources)>0 or schedulerpolicy=="TRUE"):
    gr.printFile ("/* brief Resources Priorities */")
    gr.printFile ("const TaskPriorityType ResourcesPriority_core1[RESOURCES_COUNT_CORE1] = {")
    if(schedulerpolicy=="TRUE"):
        Res_Scheduler_Priority = 0
        for resource in core1_general_resources:
            if Res_Scheduler_Priority < priority["{}".format(resource)]:
                Res_Scheduler_Priority = priority["{}".format(resource)]                   
            gr.printFile ("    {},".format( Res_Scheduler_Priority ) )

    for resource in core1_general_resources:
        gr.printFile ("    {},".format(priority["{}".format(resource)]))
    for app in app_core1:
        gr.printFile ("    {},".format(priority["{}".format(resource)]))
    gr.printFile ("};\n")


if(len(core1_general_resources)>0 or schedulerpolicy=="TRUE"):
    gr.printFile ("/* Brief ResourceVar Array */")
    gr.printFile ("ResourceVarType ResourceVar_core1[RESOURCES_COUNT_CORE1] = {\n")
    
    if(schedulerpolicy=="TRUE"):
        resource = "RES_SCHEDULER_core1"
        gr.printFile ("    /* General resource {} */".format(resource))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */")
        gr.printFile ("        &ResourcesPriority_core1[({} & 0xffff)], /* celingPriority */".format(resource))
        gr.printFile ("        0,                            /* previousPriority */")
        gr.printFile ("        0,                            /* owner */")
        gr.printFile ("        "+ resource +",                    /* id */")
        gr.printFile ("    },")
    
    for resource in core1_general_resources:
        gr.printFile ("    /* General resource {} */".format(resource))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */")
        gr.printFile ("        &ResourcesPriority_core1[({} & 0xffff)], /* celingPriority */".format(resource))
        gr.printFile ("        0,                            /* previousPriority */")
        gr.printFile ("        0,                            /* owner */")
        gr.printFile ("        " + resource + ",                    /* id */")
        gr.printFile ("    },")
    
    for app in app_core1:
        gr.printFile ("    /* Sys resource resource{} */".format(app))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */")
        gr.printFile ("        &ResourcesPriority_core1[(resource{} & 0xffff)], /* celingPriority */".format(app))
        gr.printFile ("        0,                            /* previousPriority */")
        gr.printFile ("        0,                            /* owner */")
        gr.printFile ("        resource{}                            /* id */".format(app))
        gr.printFile ("    },")
    gr.printFile ("};\n")

#application mask
if(len(core0_general_resources)>0 ):
    gr.printFile("ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0] = {")
    for resource in core0_general_resources:
        gr.printFile("    /* Resource {} */".format(resource))
        gr.printFile ("    {")
        apps = config.getList("/AUTOSAR/" + resource, "OsResourceAccessingApplication")
        if apps != []:
            gr.printFileSpace("        0 ")
            for app in apps:
                if app == apps[-1]:
                    gr.printFile("| (1 << {}) ".format(app))
                else:
                    gr.printFileSpace("| (1 << {}) ".format(app))
        else:
            gr.printFile("        0")           
        gr.printFile("    },")

    for app in app_core0:
        gr.printFile("    /* Resource resource{} */".format(app))
        gr.printFile ("    {")
        gr.printFileSpace("        0 ")
        for app_i in app_core0:
            if app_i == app_core0[-1]:
                gr.printFile("| (1 << {}) ".format(app_i))
            else:
                gr.printFileSpace("| (1 << {}) ".format(app_i))  
        gr.printFile("    },")
    gr.printFile("};\n")


if(len(core1_general_resources)>0 ):
    gr.printFile("ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1] = {")
    for resource in core1_general_resources:
        gr.printFile("    /* Resource {} */".format(resource))
        gr.printFile ("    {")
        apps = config.getList("/AUTOSAR/" + resource, "OsResourceAccessingApplication")
        if apps != []:
            gr.printFileSpace("        0 ")
            for app in apps:
                if app == apps[-1]:
                    gr.printFile("| (1 << {}) ".format(app))
                else:
                    gr.printFileSpace("| (1 << {}) ".format(app))
        else:
            gr.printFile("        0")           
        gr.printFile("    },")

    for app in app_core1:
        gr.printFile("    /* Resource resource{} */".format(app))
        gr.printFile ("    {")
        gr.printFileSpace("        0 ")
        for app_i in app_core1:
            if app_i == app_core1[-1]:
                gr.printFile("| (1 << {}) ".format(app_i))
            else:
                gr.printFileSpace("| (1 << {}) ".format(app_i))  
        gr.printFile("    },")
    gr.printFile("};\n")

gr.printFile("#pragma section")



# /* Internal Resources Priorities */
if(len(core0_internal_resources)>0):
    gr.printFile ("/* brief Internal Resources Priorities */\n")
    gr.printFile ("const TaskPriorityType InternalResourcesPriority_core0[INTERNAL_RESOURCES_COUNT_CORE0]  = {")
    for resource in core0_internal_resources:
        gr.printFile ("    {}".format(priority["{}".format(resource)]))
    gr.printFile ("};\n")


# /* generate the internalResourceVar structure */
if(len(core0_internal_resources)>0):
    gr.printFile ("/* Brief ResourceVar Array */\n")
    gr.printFile ("ResourceVarType ResourceVar_core0[RESOURCES_COUNT_core0] = {\n")
    count = 0
    for resource in core0_internal_resources:
        gr.printFile ("    /* Internal resource {} */".format(resource))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */\n")
        gr.printFile ("        &InternalResourcesPriority0[({} & 0xffff)], /* celingPriority */".format(resource))
        gr.printFile ("        0,                            /* previousPriority */\n")
        gr.printFile ("        0,                            /* owner */\n")
        gr.printFile ("        " + resource + ",                    /* id */\n")
        gr.printFile ("    }")
        if count == len(core0_internal_resources)-1 :
            gr.printFile ("    }")
        else:
            count += 1
            gr.printFile ("    },")
    gr.printFile ("};\n")

if(len(core1_internal_resources)>0):
    gr.printFile ("/* brief Internal Resources Priorities */\n")
    gr.printFile ("const TaskPriorityType InternalResourcesPriority_core1[INTERNAL_RESOURCES_COUNT_CORE1]  = {")
    for resource in core1_internal_resources:
        gr.printFile ("    {}".format(priority["{}".format(resource)]))
    gr.printFile ("};\n")


# /* generate the internalResourceVar structure */
if(len(core1_internal_resources)>0):
    gr.printFile ("/* Brief ResourceVar Array */\n")
    gr.printFile ("ResourceVarType ResourceVar_core1[RESOURCES_COUNT_core1] = {\n")
    count = 0
    for resource in core1_internal_resources:
        gr.printFile ("    /* Internal resource {} */".format(resource))
        gr.printFile ("    {")
        gr.printFile ("        NULL,                         /* NextResource pointer */\n")
        gr.printFile ("        &InternalResourcesPriority1[({} & 0xffff)], /* celingPriority */".format(resource))
        gr.printFile ("        0,                            /* previousPriority */\n")
        gr.printFile ("        0,                            /* owner */\n")
        gr.printFile ("        " + resource + ",                    /* id */\n")
        gr.printFile ("    }")
        if count == len(core1_internal_resources)-1 :
            gr.printFile ("    }")
        else:
            count += 1
            gr.printFile ("    },")
    gr.printFile ("};\n")


'''
# /* the ResourceVar structure of RES_SCHEDULER if need*/
    os = config.getList("/AUTOSAR","OsRESOURCE")
    schedulerpolicy = config.getValue("/AUTOSAR/" + os[0],"OsUseResScheduler")
    if(schedulerpolicy=="TRUE"):
        resource = "RES_SCHEDULER"
        if ( count != 0 ):
            gr.printFile (",\n")
        count += 1
        gr.printFile ("    /* General resource $resource */\n")
        gr.printFile ("    {\n")
        gr.printFile ("        NULL,                         /* NextResource pointer */\n")
        gr.printFile ("        &ResourcesPriority["+ resource +"], /* celingPriority */\n")
        gr.printFile ("        0,                            /* previousPriority */\n")
        gr.printFile ("        0,                            /* owner */\n")
        gr.printFile ("        "+ resource +",                    /* id */\n")
        gr.printFile ("    }")

    gr.printFile ("\n};\n\n")
'''

resource_core0 = core0_general_resources
for app in app_core0:
    resourceapp = 'reosurce' + app
    resource_core0.append(resourceapp)

resource_core1 = core1_general_resources
for app in app_core1:
    resourceapp = 'reosurce' + app
    resource_core1.append(resourceapp)
