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
from Interface_config import CS_If1, CS_If1_OP_Add, CS_If1_OP_Sub, CS_If1_OP_Multiply

component_file = os.path.join(os.path.dirname(__file__), 'ARXML', 'SWC.arxml')

SWC_Composition_ARPackage = autosarfactory.new_file(component_file, defaultArPackage = 'SWC_Composition', overWrite = 'true')
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


#internal behavior
SWC_Client_IntBehav = SWC_Client.new_InternalBehavior('SWC_Client_SwcInternalBehavior')
SWC_Client_IntBehav_Rport1APIOption = SWC_Client_IntBehav.new_PortAPIOption('SWC_Client_IntBehav_Rport1_PortAPIOption')
SWC_Client_IntBehav_Rport1APIOption.set_port(SWC_Client_Rport1)
SWC_Client_IntBehav_Rport1APIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_NO_TRANSFORMER_ERROR_HANDLING) #no transformer error handling


#RTEEvent
InitEv_1 = SWC_Client_IntBehav.new_InitEvent('InitEvent_1')
InitEv_2 = SWC_Client_IntBehav.new_InitEvent('InitEvent_2')
InitEv_3 = SWC_Client_IntBehav.new_InitEvent('InitEvent_3')
OprInvokEv_1 = SWC_Client_IntBehav.new_OperationInvokedEvent('OperationInvokedEvent_1')
OprInvokEv_2 = SWC_Client_IntBehav.new_OperationInvokedEvent('OperationInvokedEvent_2')
OprInvokEv_3 = SWC_Client_IntBehav.new_OperationInvokedEvent('OperationInvokedEvent_3')
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
SWC_Client_IntBehav_CR1_SynSerCallPoint1_Add = SWC_Client_IntBehav_CR1_SynSerCallPoint1.new_Operation('Add_ImplUint16')
SWC_Client_IntBehav_CR1_SynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR1_SynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)
    # async Add
SWC_Client_IntBehav_CR1_AsynSerCallPoint1 = SWC_Client_IntBehav_CR1.new_AsynchronousServerCallPoint('CR1_AsynSerCallPoint_1')
SWC_Client_IntBehav_CR1_AsynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR1_AsynSerCallPoint1_Add = SWC_Client_IntBehav_CR1_AsynSerCallPoint1.new_Operation('Add_ImplUint16')
SWC_Client_IntBehav_CR1_AsynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR1_AsynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)
#rte event to task mapping ？

#Client_Response_Runnable_1
SWC_Client_IntBehav_CRR1 = SWC_Client_IntBehav.new_Runnable('Client_Response_1')
SWC_Client_IntBehav_CRR1.set_symbol('Client_Response_1')
    # blocking Rte_Result (waitPoint refer to AsynchronousServerCallReturnsEvent)
SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1 = SWC_Client_IntBehav_CRR1.new_AsynchronousServerCallResultPoint('CRR1_AsynSerCallResultPoint_1')
SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR1_AsynSerCallPoint1)
CRR1_WaitPoint_1 = SWC_Client_IntBehav_CRR1.new_WaitPoint('CRR1_WaitPoint_1')
CRR1_WaitPoint_1.set_timeout('60')
CRR1_WaitPoint_1.set_trigger(AsySerCallRetEv_1)
    # non-blocking Rte_Result
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
SWC_Client_IntBehav_CR2_SynSerCallPoint1_Add = SWC_Client_IntBehav_CR2_SynSerCallPoint1.new_Operation('Add_ImplUint16')
SWC_Client_IntBehav_CR2_SynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR2_SynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)
    # async Add
SWC_Client_IntBehav_CR2_AsynSerCallPoint1 = SWC_Client_IntBehav_CR2.new_AsynchronousServerCallPoint('CR2_AsynSerCallPoint_1')
SWC_Client_IntBehav_CR2_AsynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR2_AsynSerCallPoint1_Add = SWC_Client_IntBehav_CR2_AsynSerCallPoint1.new_Operation('Add_ImplUint16')
SWC_Client_IntBehav_CR2_AsynSerCallPoint1_Add.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR2_AsynSerCallPoint1_Add.set_targetRequiredOperation(CS_If1_OP_Add)

#Server_Runnable_1
#Add？

#Client_Response_Runnable_2
SWC_Client_IntBehav_CRR2 = SWC_Client_IntBehav.new_Runnable('Client_Response_2')
SWC_Client_IntBehav_CRR2.set_symbol('Client_Response_2')
    # blocking Rte_Result (waitPoint refer to AsynchronousServerCallReturnsEvent)
SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1 = SWC_Client_IntBehav_CRR2.new_AsynchronousServerCallResultPoint('CRR2_AsynSerCallResultPoint_1')
SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR2_AsynSerCallPoint1)
CRR2_WaitPoint_1 = SWC_Client_IntBehav_CRR2.new_WaitPoint('CRR2_WaitPoint_1')
CRR2_WaitPoint_1.set_timeout('60')
CRR2_WaitPoint_1.set_trigger(AsySerCallRetEv_2)
    # non-blocking Rte_Result
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
SWC_Client_IntBehav_CR3_SynSerCallPoint1_Multiply = SWC_Client_IntBehav_CR3_SynSerCallPoint1.new_Operation('Multiply_ImplUint16')
SWC_Client_IntBehav_CR3_SynSerCallPoint1_Multiply.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR3_SynSerCallPoint1_Multiply.set_targetRequiredOperation(CS_If1_OP_Multiply)
    # async Multiply
SWC_Client_IntBehav_CR3_AsynSerCallPoint1 = SWC_Client_IntBehav_CR3.new_AsynchronousServerCallPoint('CR3_AsynSerCallPoint_1')
SWC_Client_IntBehav_CR3_AsynSerCallPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CR3_AsynSerCallPoint1_Multiply = SWC_Client_IntBehav_CR3_AsynSerCallPoint1.new_Operation('Multiply_ImplUint16')
SWC_Client_IntBehav_CR3_AsynSerCallPoint1_Multiply.set_contextRPort(SWC_Client_Rport1)
SWC_Client_IntBehav_CR3_AsynSerCallPoint1_Multiply.set_targetRequiredOperation(CS_If1_OP_Multiply)

#Client_Response_Runnable_3
SWC_Client_IntBehav_CRR3 = SWC_Client_IntBehav.new_Runnable('Client_Response_3')
SWC_Client_IntBehav_CRR3.set_symbol('Client_Response_3')
    # blocking Rte_Result (waitPoint refer to AsynchronousServerCallReturnsEvent)
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1 = SWC_Client_IntBehav_CRR3.new_AsynchronousServerCallResultPoint('CRR3_AsynSerCallResultPoint_1')
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR3_AsynSerCallPoint1)
CRR3_WaitPoint_1 = SWC_Client_IntBehav_CRR3.new_WaitPoint('CRR3_WaitPoint_1')
CRR3_WaitPoint_1.set_timeout('60')
CRR3_WaitPoint_1.set_trigger(AsySerCallRetEv_3)
    # non-blocking Rte_Result
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint3 = SWC_Client_IntBehav_CRR3.new_AsynchronousServerCallResultPoint('CRR3_AsynSerCallResultPoint_3')
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint3.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
SWC_Client_IntBehav_CRR3_AsynSerCallResPoint3.set_asynchronousServerCallPoint(SWC_Client_IntBehav_CR3_AsynSerCallPoint1)

#Server_Runnable_2
#Multiply？

# RTEEvent configuration
InitEv_1.set_startOnEvent(SWC_Client_IntBehav_CR1)
InitEv_2.set_startOnEvent(SWC_Client_IntBehav_CR2)
InitEv_3.set_startOnEvent(SWC_Client_IntBehav_CR3)
#？
    # OprInvokEv_1/2/3.set_startOnEvent(server_runnable)
    # OprInvokEv_1/2/3.set_operation(client_server_operation)
# for blocking Rte_Result (wake up the blocked CRR)
AsySerCallRetEv_1.set_startOnEvent(SWC_Client_IntBehav_CRR1)
AsySerCallRetEv_1.set_eventSource(SWC_Client_IntBehav_CRR1_AsynSerCallResPoint1)
AsySerCallRetEv_2.set_startOnEvent(SWC_Client_IntBehav_CRR2)
AsySerCallRetEv_1.set_eventSource(SWC_Client_IntBehav_CRR2_AsynSerCallResPoint1)
AsySerCallRetEv_3.set_startOnEvent(SWC_Client_IntBehav_CRR3)
AsySerCallRetEv_1.set_eventSource(SWC_Client_IntBehav_CRR3_AsynSerCallResPoint1)

autosarfactory.save()