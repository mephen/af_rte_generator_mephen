#arxml generator
#-----------------------------------------------------------------------------------------
#此檔案配置是 Sync Rte_call。(inter-Ecu, inter-partition, intra-partition 要從 application_Rte_ecuc.arxml 的 rteEventToTaskMapping 來看)
import os, sys
import pdb
from autosarfactory import autosarfactory
"""
導入 autosarfactory 包中的 autosarfactory 模塊，
而不是頂層的 autosarfactory 包。

這是因為 autosarfactory 檔案結構為這樣
autosarfactory/  <- folder
|-- __init__.py
|-- autosarfactory.py  <- target
|-- other_module.py
"""

"""
如果是寫入 import autosarfactory
則 new_file 要這樣寫 autosarfactory.autosarfactory.new_file

from autosarfactory import autosarfactory
上面的導入語句將導入名為 "autosarfactory" 的模塊，
該模塊可能是 "autosarfactory" 包中的一個模塊，或者是根級別(root level)的模塊。
在這種情況下，如果你想使用 "SwImplPolicyEnum"，需要使用
autosarfactory.SwImplPolicyEnum 的形式來訪問它。
"""
from autosarfactory.autosarfactory import DataTransformationErrorHandlingEnum\
    , DataTransformationStatusForwardingEnum, RteApiReturnValueProvisionEnum, ModeActivationKind

"""
上面的導入語句將直接導入 "autosarfactory.autosarfactory" 模塊中的特定元素。
在這種情況下，你可以直接使用 "SwImplPolicyEnum"，而無需前綴 "autosarfactory."。

如果沒有上面的 導入語句 就是需要寫成 autosarfactory.SwImplPolicyEnum
"""

component_file = os.path.join(os.path.dirname(__file__), './swc', 'SWC.arxml')

#First ARPackage
SWC_Composition_ARPackage = autosarfactory.new_file(component_file, defaultArPackage = 'CS_Composition', overWrite = 'true')
#ARPackage
SWC_ModeGroup_ARPackage = SWC_Composition_ARPackage.new_ARPackage('ModeGroup_ARPackage')
SWC_ARPackage = SWC_Composition_ARPackage.new_ARPackage('SWCs')

#ModeDeclarationGroup
SWC_ModeGroup = SWC_ModeGroup_ARPackage.new_ModeDeclarationGroup('ModeGroup')
    #ModeDeclaration
initMode_def = SWC_ModeGroup.new_ModeDeclaration('INITMODE')
    #ModeDeclarationGroup set initMode attr.
SWC_ModeGroup_initMode = SWC_ModeGroup.set_initialMode(initMode_def)

#SWC
SWC_LifeCycle = SWC_ARPackage.new_ApplicationSwComponentType('SWC_LifeCycle')
SWC_Mode_A = SWC_ARPackage.new_ApplicationSwComponentType('SWC_Mode_A')

#internal behavior
SWC_LifeCycle_IntBeh = SWC_LifeCycle.new_InternalBehavior('SWC_LifeCycle_InternalBehavior')
SWC_Mode_A_IntBeh = SWC_Mode_A.new_InternalBehavior('SWC_Mode_A_InternalBehavior')


#RTEEvent
BackgroundEv_1 = SWC_LifeCycle_IntBeh.new_BackgroundEvent('RteBackgroundEvent_1')
TimingEv_1 = SWC_LifeCycle_IntBeh.new_TimingEvent('RteTimingEvent_1')
InitEv_1 = SWC_LifeCycle_IntBeh.new_InitEvent('RteInitEvent_1')
InitEv_2 = SWC_LifeCycle_IntBeh.new_InitEvent('RteInitEvent_2')

ModeSwitchEv_1 = SWC_Mode_A_IntBeh.new_SwcModeSwitchEvent('RteModeSwitchEvent_1')
ModeSwitchEv_2 = SWC_Mode_A_IntBeh.new_SwcModeSwitchEvent('RteModeSwitchEvent_2')


#LSA spec.p129：一個 SWC 的 Runnables 只能映射到同 core 且同 app。
#Runnable
Runnable_background_1 = SWC_LifeCycle_IntBeh.new_Runnable('Runnable_background_1')
Runnable_background_1.set_symbol('Runnable_background_1')
Runnable_timing_1 = SWC_LifeCycle_IntBeh.new_Runnable('Runnable_timing_1')
Runnable_timing_1.set_symbol('Runnable_timing_1')
Runnable_init_1 = SWC_LifeCycle_IntBeh.new_Runnable('Runnable_init_1')
Runnable_init_1.set_symbol('Runnable_init_1')
Runnable_init_2 = SWC_LifeCycle_IntBeh.new_Runnable('Runnable_init_2')
Runnable_init_2.set_symbol('Runnable_init_2')

Runnable_modeSwitch_1 = SWC_Mode_A_IntBeh.new_Runnable('Runnable_modeSwitch_1')
Runnable_modeSwitch_1.set_symbol('Runnable_modeSwitch_1')
Runnable_modeSwitch_2 = SWC_Mode_A_IntBeh.new_Runnable('Runnable_modeSwitch_2')
Runnable_modeSwitch_2.set_symbol('Runnable_modeSwitch_2')


# RTEEvent configuration
BackgroundEv_1.set_startOnEvent(Runnable_background_1)
TimingEv_1.set_startOnEvent(Runnable_timing_1)
TimingEv_1.set_period(15) #second
InitEv_1.set_startOnEvent(Runnable_init_1)
InitEv_2.set_startOnEvent(Runnable_init_2)

ModeSwitchEv_1.set_startOnEvent(Runnable_modeSwitch_1)
ModeSwitchEv_1.set_activation(ModeActivationKind.VALUE_ON_ENTRY)
ModeSwitchEv_1_initMode = ModeSwitchEv_1.new_Mode("initmode")
ModeSwitchEv_1_initMode.set_targetModeDeclaration(initMode_def)

ModeSwitchEv_2.set_startOnEvent(Runnable_modeSwitch_2)
ModeSwitchEv_2_initMode = ModeSwitchEv_2.new_Mode("initmode")
ModeSwitchEv_2_initMode.set_targetModeDeclaration(initMode_def)
ModeSwitchEv_2.add_disabledMode(ModeSwitchEv_2_initMode)



autosarfactory.save()