import os, sys
import pdb
from autosarfactory import autosarfactory

interface_file = os.path.join(os.path.dirname(__file__), 'swc', 'Interface.arxml')

from autosarfactory.autosarfactory import SwImplPolicyEnum ,HandleInvalidEnum\
    , SwCalibrationAccessEnum, ArgumentDirectionEnum, ServerArgumentImplPolicyEnum

#App_uint16 maps to Impl_uint16
from DataType_config import App_uint16

Interface_Composition_ARPackage = autosarfactory.new_file(interface_file, defaultArPackage = 'CS_Composition', overWrite = 'true')
Interfaces_ARPackage = Interface_Composition_ARPackage.new_ARPackage('Interfaces') 
CS_If1 = Interfaces_ARPackage.new_ClientServerInterface('CS_If1')
#Add Operation
CS_If1_OP_Add = CS_If1.new_Operation('Add_ImplUint16')
CS_If1_OP_Add_Arg1 = CS_If1_OP_Add.new_Argument('Add_ImplUint16_Arg1')
CS_If1_OP_Add_Arg1.set_direction(ArgumentDirectionEnum.VALUE_IN)
CS_If1_OP_Add_Arg1.set_serverArgumentImplPolicy(ServerArgumentImplPolicyEnum.VALUE_USE_ARGUMENT_TYPE)
CS_If1_OP_Add_Arg1.set_type(App_uint16)
CS_If1_OP_Add_Arg2 = CS_If1_OP_Add.new_Argument('Add_ImplUint16_Arg2')
CS_If1_OP_Add_Arg2.set_direction(ArgumentDirectionEnum.VALUE_IN)
CS_If1_OP_Add_Arg2.set_serverArgumentImplPolicy(ServerArgumentImplPolicyEnum.VALUE_USE_ARGUMENT_TYPE)
CS_If1_OP_Add_Arg2.set_type(App_uint16)

#Sub Operation
CS_If1_OP_Sub = CS_If1.new_Operation('Sub_ImplUint16')
CS_If1_OP_Sub_Arg1 = CS_If1_OP_Sub.new_Argument('Sub_ImplUint16_Arg1')
CS_If1_OP_Sub_Arg1.set_direction(ArgumentDirectionEnum.VALUE_IN)
CS_If1_OP_Sub_Arg1.set_serverArgumentImplPolicy(ServerArgumentImplPolicyEnum.VALUE_USE_ARGUMENT_TYPE)
CS_If1_OP_Sub_Arg1.set_type(App_uint16)
CS_If1_OP_Sub_Arg2 = CS_If1_OP_Sub.new_Argument('Sub_ImplUint16_Arg2')
CS_If1_OP_Sub_Arg2.set_direction(ArgumentDirectionEnum.VALUE_IN)
CS_If1_OP_Sub_Arg2.set_serverArgumentImplPolicy(ServerArgumentImplPolicyEnum.VALUE_USE_ARGUMENT_TYPE)
CS_If1_OP_Sub_Arg2.set_type(App_uint16)

#Multiply Operation
CS_If1_OP_Multiply = CS_If1.new_Operation('Multiply_ImplUint16')
CS_If1_OP_Multiply_Arg1 = CS_If1_OP_Multiply.new_Argument('Multiply_ImplUint16_Arg1')
CS_If1_OP_Multiply_Arg1.set_direction(ArgumentDirectionEnum.VALUE_IN)
CS_If1_OP_Multiply_Arg1.set_serverArgumentImplPolicy(ServerArgumentImplPolicyEnum.VALUE_USE_ARGUMENT_TYPE)
CS_If1_OP_Multiply_Arg1.set_type(App_uint16)
CS_If1_OP_Multiply_Arg2 = CS_If1_OP_Multiply.new_Argument('Multiply_ImplUint16_Arg2')
CS_If1_OP_Multiply_Arg2.set_direction(ArgumentDirectionEnum.VALUE_IN)
CS_If1_OP_Multiply_Arg2.set_serverArgumentImplPolicy(ServerArgumentImplPolicyEnum.VALUE_USE_ARGUMENT_TYPE)
CS_If1_OP_Multiply_Arg2.set_type(App_uint16)

autosarfactory.save()