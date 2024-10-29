import os, sys
import pdb
from autosarfactory import autosarfactory

import ControlSWC_config
import ControlSWC2_config
import ObservationSWC_config
import ObservationSWC2_config
 
composition_file = os.path.join(os.path.dirname(__file__), 'swc', 'tpc_composition.arxml')

TPC_Composition_ARPackage= autosarfactory.new_file(composition_file, defaultArPackage = 'TPC_Composition', overWrite = 'true')
Components_ARPackage = TPC_Composition_ARPackage.new_ARPackage('Components') 
composition_swc = Components_ARPackage.new_CompositionSwComponentType('TPC_Composition')
composition_swc_swc_prototype_ctrl = composition_swc.new_Component('Ctrl')
composition_swc_swc_prototype_ctrl.set_type(ControlSWC_config.SWC_Controller)

composition_swc_swc_prototype_ctrl = composition_swc.new_Component('Ctrl2')
composition_swc_swc_prototype_ctrl.set_type(ControlSWC2_config.SWC_Controller2)

composition_swc_swc_prototype_obv = composition_swc.new_Component('Obv')
composition_swc_swc_prototype_obv.set_type(ObservationSWC_config.SWC_Observation)


conn1_1 = composition_swc.new_AssemblySwConnector('conn1_1')
provider = conn1_1.new_Provider()
provider.set_contextComponent(composition_swc_swc_prototype_ctrl)
provider.set_targetPPort(ControlSWC_config.PpIfVehSpd)
required = conn1_1.new_Requester()
required.set_contextComponent(composition_swc_swc_prototype_obv)
required.set_targetRPort(ObservationSWC_config.RpIfVehSpd)

conn1_2 = composition_swc.new_AssemblySwConnector('conn1_2')
provider = conn1_2.new_Provider()
provider.set_contextComponent(composition_swc_swc_prototype_ctrl)
provider.set_targetPPort(ControlSWC_config.PpIfVehAcc)
required = conn1_2.new_Requester()
required.set_contextComponent(composition_swc_swc_prototype_obv)
required.set_targetRPort(ObservationSWC_config.RpIfVehAcc)

conn1_3 = composition_swc.new_AssemblySwConnector('conn1_3')
provider = conn1_3.new_Provider()
provider.set_contextComponent(composition_swc_swc_prototype_ctrl)
provider.set_targetPPort(ControlSWC_config.PpIfTemperature)
required = conn1_3.new_Requester()
required.set_contextComponent(composition_swc_swc_prototype_obv)
required.set_targetRPort(ObservationSWC_config.RpIfTemperature)

conn2_1 = composition_swc.new_AssemblySwConnector('conn2_1')
provider = conn2_1.new_Provider()
provider.set_contextComponent(composition_swc_swc_prototype_ctrl)
provider.set_targetPPort(ControlSWC2_config.PpIfVehSpd2)
required = conn2_1.new_Requester()
required.set_contextComponent(composition_swc_swc_prototype_obv)
required.set_targetRPort(ObservationSWC_config.RpIfVehSpd)
# required.set_contextComponent(composition_swc_swc_prototype_obv2)
# required.set_targetRPort(ObservationSWC2_config.RpIfVehSpd2)

conn2_2 = composition_swc.new_AssemblySwConnector('conn2_2')
provider = conn2_2.new_Provider()
provider.set_contextComponent(composition_swc_swc_prototype_ctrl)
provider.set_targetPPort(ControlSWC2_config.PpIfVehAcc2)
required = conn2_2.new_Requester()
required.set_contextComponent(composition_swc_swc_prototype_obv)
required.set_targetRPort(ObservationSWC_config.RpIfVehAcc)
# required.set_contextComponent(composition_swc_swc_prototype_obv2)
# required.set_targetRPort(ObservationSWC2_config.RpIfVehAcc2)

conn2_3 = composition_swc.new_AssemblySwConnector('conn2_3')
provider = conn2_3.new_Provider()
provider.set_contextComponent(composition_swc_swc_prototype_ctrl)
provider.set_targetPPort(ControlSWC2_config.PpIfTemperature2)
required = conn2_3.new_Requester()
required.set_contextComponent(composition_swc_swc_prototype_obv)
required.set_targetRPort(ObservationSWC_config.RpIfTemperature)
# required.set_contextComponent(composition_swc_swc_prototype_obv2)
# required.set_targetRPort(ObservationSWC2_config.RpIfTemperature2)

autosarfactory.save()
