#arxml generator
#-----------------------------------------------------------------------------------------
#此檔案配置是 async Rte_call + non-blocking Rte_Result case。(inter-Ecu, inter-partition, intra-partition 要從 application_Rte_ecuc.arxml 的 rteEventToTaskMapping 來看)
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
    , DataTransformationStatusForwardingEnum, RteApiReturnValueProvisionEnum

"""
上面的導入語句將直接導入 "autosarfactory.autosarfactory" 模塊中的特定元素。
在這種情況下，你可以直接使用 "SwImplPolicyEnum"，而無需前綴 "autosarfactory."。

如果沒有上面的 導入語句 就是需要寫成 autosarfactory.SwImplPolicyEnum
"""
from Arxml_Interface_config import CS_If1, CS_If1_OP_Add, CS_If1_OP_Sub, CS_If1_OP_Multiply

component_file = os.path.join(os.path.dirname(__file__), './swc', 'SWC.arxml')

SWC_Composition_ARPackage = autosarfactory.new_file(component_file, defaultArPackage = 'CS_Composition', overWrite = 'true')

SWC_ARPackage = SWC_Composition_ARPackage.new_ARPackage('SWCs')

SWC_Client = SWC_ARPackage.new_ApplicationSwComponentType('SWC_Client')
SWC_Client_Rport1 = SWC_Client.new_RPortPrototype('SWC_Client_Rport1')
SWC_Client_Rport1.set_requiredInterface(CS_If1)

#SWC_Client_Rport1 can use Add, Sub, and Multiply.
SWC_Client_Rport1_ClientComSpec_Add = SWC_Client_Rport1.new_ClientComSpec('SWC_Client_Rport1_ClientComSpec_Add')
SWC_Client_Rport1_ClientComSpec_Add.set_endToEndCallResponseTimeout('50') #only for sync c/s comm.
SWC_Client_Rport1_ClientComSpec_Add.set_operation(CS_If1_OP_Add)

SWC_Client_Rport1_ClientComSpec_Sub = SWC_Client_Rport1.new_ClientComSpec('SWC_Client_Rport1_ClientComSpec_Sub')
SWC_Client_Rport1_ClientComSpec_Sub.set_endToEndCallResponseTimeout('50')
SWC_Client_Rport1_ClientComSpec_Sub.set_operation(CS_If1_OP_Sub)

SWC_Client_Rport1_ClientComSpec_Multiply = SWC_Client_Rport1.new_ClientComSpec('SWC_Client_Rport1_ClientComSpec_Multiply')
SWC_Client_Rport1_ClientComSpec_Multiply.set_endToEndCallResponseTimeout('50')
SWC_Client_Rport1_ClientComSpec_Multiply.set_operation(CS_If1_OP_Multiply)

#LSA spec.p129：一個 SWC 的 Runnables 只能映射到同 core 且同 app。
#所以提供 inter-partition 和 intra-partition 需要的 C/S operation 的 SWC 是不同的。
SWC_Server1 = SWC_ARPackage.new_ApplicationSwComponentType('SWC_Server_1')
SWC_Server1_Pport1 = SWC_Server1.new_PPortPrototype('SWC_Server1_Pport1')
SWC_Server1_Pport1.set_providedInterface(CS_If1)
SWC_Server1_Pport1_ServerComSpec_Add = SWC_Server1_Pport1.new_ServerComSpec('SWC_Server1_Pport1_ServerComSpec_Add')
SWC_Server1_Pport1_ServerComSpec_Add.set_operation(CS_If1_OP_Add)
SWC_Server1_Pport1_ServerComSpec_Add.set_queueLength('20')

SWC_Server2 = SWC_ARPackage.new_ApplicationSwComponentType('SWC_Server_2')
SWC_Server2_Pport1 = SWC_Server1.new_PPortPrototype('SWC_Server2_Pport1')
SWC_Server2_Pport1.set_providedInterface(CS_If1)
SWC_Server2_Pport1_ServerComSpec_Multiply = SWC_Server2_Pport1.new_ServerComSpec('SWC_Server2_Pport1_ServerComSpec_Multiply')
SWC_Server2_Pport1_ServerComSpec_Multiply.set_operation(CS_If1_OP_Multiply)
SWC_Server2_Pport1_ServerComSpec_Multiply.set_queueLength('20')

#internal behavior
SWC_Client_IntBehav = SWC_Client.new_InternalBehavior('SWC_Client_SwcInternalBehavior')
SWC_Client_IntBehav_Rport1APIOption = SWC_Client_IntBehav.new_PortAPIOption('SWC_Client_IntBehav_Rport1_PortAPIOption')
SWC_Client_IntBehav_Rport1APIOption.set_port(SWC_Client_Rport1)
SWC_Client_IntBehav_Rport1APIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_NO_TRANSFORMER_ERROR_HANDLING) #no transformer error handling

SWC_Server1_IntBehav = SWC_Server1.new_InternalBehavior('SWC_Server1_SwcInternalBehavior')
SWC_Server2_IntBehav = SWC_Server2.new_InternalBehavior('SWC_Server2_SwcInternalBehavior')

#RTEEvent
InitEv_1 = SWC_Client_IntBehav.new_InitEvent('InitEvent_1')
InitEv_2 = SWC_Client_IntBehav.new_InitEvent('InitEvent_2')
InitEv_3 = SWC_Client_IntBehav.new_InitEvent('InitEvent_3')
OprInvokEv_1 = SWC_Server1_IntBehav.new_OperationInvokedEvent('OperationInvokedEvent_1')
OprInvokEv_2 = SWC_Server1_IntBehav.new_OperationInvokedEvent('OperationInvokedEvent_2')
OprInvokEv_3 = SWC_Server2_IntBehav.new_OperationInvokedEvent('OperationInvokedEvent_3')
AsySerCallRetEv_1 = SWC_Client_IntBehav.new_AsynchronousServerCallReturnsEvent('AsynchronousServerCallReturnsEvent_1')
AsySerCallRetEv_2 = SWC_Client_IntBehav.new_AsynchronousServerCallReturnsEvent('AsynchronousServerCallReturnsEvent_2')
AsySerCallRetEv_3 = SWC_Client_IntBehav.new_AsynchronousServerCallReturnsEvent('AsynchronousServerCallReturnsEvent_3')


#Runnable
#Client_Runnable_1
SWC_Client_IntBehav_CR1 = SWC_Client_IntBehav.new_Runnable('Client_1')
SWC_Client_IntBehav_CR1.set_symbol('Client_1')
    # sync Add
SWC_Client_IntBehav_CR1_SynSerCallPoint1 = SWC_Client_IntBehav_CR1.new_SynchronousServerCallPoint('CR1_SynSerCallPoint_1')
SWC_Client_IntBehav_CR1_SynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR1_SynSerCallPoint1.set_timeout('50')
SWC_Client_IntBehav_CR1_SynSerCallPoint1_Add = SWC_Client_IntBehav_CR1_SynSerCallPoint1.new_Operation('CR1_Sync_Add_ImplUint16')
SWC_Client_IntBehav_CR1_SynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR1_SynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)
    # async Add
SWC_Client_IntBehav_CR1_AsynSerCallPoint1 = SWC_Client_IntBehav_CR1.new_AsynchronousServerCallPoint('CR1_AsynSerCallPoint_1')
SWC_Client_IntBehav_CR1_AsynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR1_AsynSerCallPoint1_Add = SWC_Client_IntBehav_CR1_AsynSerCallPoint1.new_Operation('CR1_Async_Add_ImplUint16')
SWC_Client_IntBehav_CR1_AsynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR1_AsynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)

#Client_Response_Runnable_1
SWC_Client_IntBehav_CRR1 = SWC_Client_IntBehav.new_Runnable('Client_Response_1')
SWC_Client_IntBehav_CRR1.set_symbol('Client_Response_1')
    # blocking Rte_Result (waitPoint refer to AsynchronousServerCallReturnsEvent)
# SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1 = SWC_Client_IntBehav_CRR1.new_AsynchronousServerCallResultPoint('CRR1_AsynSerCallResultPoint_1')
# SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
# SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR1_AsynSerCallPoint1)
# CRR1_WaitPoint_1 = SWC_Client_IntBehav_CRR1.new_WaitPoint('CRR1_WaitPoint_1')
# CRR1_WaitPoint_1.set_timeout('60')
# CRR1_WaitPoint_1.set_trigger(AsySerCallRetEv_1)
#     # 一個 CRR 在 blocking / non-blocking 只能二選一：因為兩者的差異在於此 CRR 的 waitPoint 是否引用了 AsynchronousServerCallReturnsEvent，是的話就代表此 CRR 都使用 blocking Rte_Result。
#     # non-blocking Rte_Result
SWC_Client_IntBehav_CRR1_AsynSerCallResPoint2 = SWC_Client_IntBehav_CRR1.new_AsynchronousServerCallResultPoint('CRR1_AsynSerCallResultPoint_2')
SWC_Client_IntBehav_CRR1_AsynSerCallResPoint2.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR1_AsynSerCallResPoint2.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR1_AsynSerCallPoint1)

#Client_Runnable_2
SWC_Client_IntBehav_CR2 = SWC_Client_IntBehav.new_Runnable('Client_2')
SWC_Client_IntBehav_CR2.set_symbol('Client_2')
    # sync Add
SWC_Client_IntBehav_CR2_SynSerCallPoint1 = SWC_Client_IntBehav_CR2.new_SynchronousServerCallPoint('CR2_SynSerCallPoint_1')
SWC_Client_IntBehav_CR2_SynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR2_SynSerCallPoint1.set_timeout('50')
SWC_Client_IntBehav_CR2_SynSerCallPoint1_Add = SWC_Client_IntBehav_CR2_SynSerCallPoint1.new_Operation('CR2_Sync_Add_ImplUint16')
SWC_Client_IntBehav_CR2_SynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR2_SynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)
    # async Add
SWC_Client_IntBehav_CR2_AsynSerCallPoint1 = SWC_Client_IntBehav_CR2.new_AsynchronousServerCallPoint('CR2_AsynSerCallPoint_1')
SWC_Client_IntBehav_CR2_AsynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR2_AsynSerCallPoint1_Add = SWC_Client_IntBehav_CR2_AsynSerCallPoint1.new_Operation('CR2_Async__Add_ImplUint16')
SWC_Client_IntBehav_CR2_AsynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR2_AsynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)

#Client_Response_Runnable_2
SWC_Client_IntBehav_CRR2 = SWC_Client_IntBehav.new_Runnable('Client_Response_2')
SWC_Client_IntBehav_CRR2.set_symbol('Client_Response_2')
    # blocking Rte_Result (waitPoint refer to AsynchronousServerCallReturnsEvent)
# SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1 = SWC_Client_IntBehav_CRR2.new_AsynchronousServerCallResultPoint('CRR2_AsynSerCallResultPoint_1')
# SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
# SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR2_AsynSerCallPoint1)
# CRR2_WaitPoint_1 = SWC_Client_IntBehav_CRR2.new_WaitPoint('CRR2_WaitPoint_1')
# CRR2_WaitPoint_1.set_timeout('60')
# CRR2_WaitPoint_1.set_trigger(AsySerCallRetEv_2)
#     # 一個 CRR 在 blocking / non-blocking 只能二選一：因為兩者的差異在於此 CRR 的 waitPoint 是否引用了 AsynchronousServerCallReturnsEvent，是的話就代表此 CRR 都使用 blocking Rte_Result。
#     # non-blocking Rte_Result
SWC_Client_IntBehav_CRR2_AsynSerCallResPoint2 = SWC_Client_IntBehav_CRR2.new_AsynchronousServerCallResultPoint('CRR2_AsynSerCallResultPoint_2')
SWC_Client_IntBehav_CRR2_AsynSerCallResPoint2.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR2_AsynSerCallResPoint2.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR2_AsynSerCallPoint1)

#Client_Runnable_3
SWC_Client_IntBehav_CR3 = SWC_Client_IntBehav.new_Runnable('Client_3')
SWC_Client_IntBehav_CR3.set_symbol('Client_3')
    # sync Multiply
SWC_Client_IntBehav_CR3_SynSerCallPoint1 = SWC_Client_IntBehav_CR3.new_SynchronousServerCallPoint('CR3_SynSerCallPoint_1')
SWC_Client_IntBehav_CR3_SynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR3_SynSerCallPoint1.set_timeout('50')
SWC_Client_IntBehav_CR3_SynSerCallPoint1_Multiply = SWC_Client_IntBehav_CR3_SynSerCallPoint1.new_Operation('CR3_Sync_Multiply_ImplUint16')
SWC_Client_IntBehav_CR3_SynSerCallPoint1_Multiply.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR3_SynSerCallPoint1_Multiply.set_targetRequiredOperation(CS_If1_OP_Multiply)
    # async Multiply
SWC_Client_IntBehav_CR3_AsynSerCallPoint1 = SWC_Client_IntBehav_CR3.new_AsynchronousServerCallPoint('CR3_AsynSerCallPoint_1')
SWC_Client_IntBehav_CR3_AsynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR3_AsynSerCallPoint1_Multiply = SWC_Client_IntBehav_CR3_AsynSerCallPoint1.new_Operation('CR3_Async_Multiply_ImplUint16')
SWC_Client_IntBehav_CR3_AsynSerCallPoint1_Multiply.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR3_AsynSerCallPoint1_Multiply.set_targetRequiredOperation(CS_If1_OP_Multiply)

#Client_Response_Runnable_3
SWC_Client_IntBehav_CRR3 = SWC_Client_IntBehav.new_Runnable('Client_Response_3')
SWC_Client_IntBehav_CRR3.set_symbol('Client_Response_3')
    # blocking Rte_Result (waitPoint refer to AsynchronousServerCallReturnsEvent)
# SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1 = SWC_Client_IntBehav_CRR3.new_AsynchronousServerCallResultPoint('CRR3_AsynSerCallResultPoint_1')
# SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
# SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR3_AsynSerCallPoint1)
# CRR3_WaitPoint_1 = SWC_Client_IntBehav_CRR3.new_WaitPoint('CRR3_WaitPoint_1')
# CRR3_WaitPoint_1.set_timeout('60')
# CRR3_WaitPoint_1.set_trigger(AsySerCallRetEv_3)
#     # 一個 CRR 在 blocking / non-blocking 只能二選一：因為兩者的差異在於此 CRR 的 waitPoint 是否引用了 AsynchronousServerCallReturnsEvent，是的話就代表此 CRR 都使用 blocking Rte_Result。
#     # non-blocking Rte_Result
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint2 = SWC_Client_IntBehav_CRR3.new_AsynchronousServerCallResultPoint('CRR3_AsynSerCallResultPoint_3')
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint2.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint2.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR3_AsynSerCallPoint1)

#Server_Runnable_1
Server1_SR1 = SWC_Server1_IntBehav.new_Runnable('Server1_SR1')
Server1_SR1.set_symbol('Server1_SR1')
Server1_SR1.set_canBeInvokedConcurrently(True)

#Server_Runnable_2
Server2_SR1 = SWC_Server2_IntBehav.new_Runnable('Server2_SR1')
Server2_SR1.set_symbol('Server2_SR1')
Server2_SR1.set_canBeInvokedConcurrently(True)

# RTEEvent configuration
InitEv_1.set_startOnEvent(SWC_Client_IntBehav_CR1)
InitEv_2.set_startOnEvent(SWC_Client_IntBehav_CR2)
InitEv_3.set_startOnEvent(SWC_Client_IntBehav_CR3)
#SWC_Server1 provides Add for intra-partition comm., and SWC_Server2 provides Multiply for inter-partition comm.
OprInvokEv_1.set_startOnEvent(Server1_SR1)
OprInvokEv1_Add_ImplUint16 = OprInvokEv_1.new_Operation('OprInvokEv1_Add_ImplUint16')
OprInvokEv1_Add_ImplUint16.set_contextPPort(SWC_Server1_Pport1)
OprInvokEv1_Add_ImplUint16.set_targetProvidedOperation(CS_If1_OP_Add)

OprInvokEv_2.set_startOnEvent(Server1_SR1)
OprInvokEv2_Add_ImplUint16 = OprInvokEv_2.new_Operation('OprInvokEv2_Add_ImplUint16')
OprInvokEv2_Add_ImplUint16.set_contextPPort(SWC_Server1_Pport1)
OprInvokEv2_Add_ImplUint16.set_targetProvidedOperation(CS_If1_OP_Add)

OprInvokEv_3.set_startOnEvent(Server2_SR1)
OprInvokEv3_Multiply_ImplUint16 = OprInvokEv_3.new_Operation('OprInvokEv3_Multiply_ImplUint16')
OprInvokEv3_Multiply_ImplUint16.set_contextPPort(SWC_Server2_Pport1)
OprInvokEv3_Multiply_ImplUint16.set_targetProvidedOperation(CS_If1_OP_Multiply)
# for blocking Rte_Result (wake up the blocked CRR)
AsySerCallRetEv_1.set_startOnEvent(SWC_Client_IntBehav_CRR1)
AsySerCallRetEv_1.set_eventSource(SWC_Client_IntBehav_CRR1_AsynSerCallResPoint2)

AsySerCallRetEv_2.set_startOnEvent(SWC_Client_IntBehav_CRR2)
AsySerCallRetEv_2.set_eventSource(SWC_Client_IntBehav_CRR2_AsynSerCallResPoint2)

AsySerCallRetEv_3.set_startOnEvent(SWC_Client_IntBehav_CRR3)
AsySerCallRetEv_3.set_eventSource(SWC_Client_IntBehav_CRR3_AsynSerCallResPoint2)

autosarfactory.save()