#include"Std_Type.h"
#include"Stack_Types.h"

/*
 * This section documents the API functions used to start and stop the RTE.
 * RTE Lifecycle API functions are not invoked from AUTOSAR software-components instead they are invoked from other basic software module(s).
 */

Std_ReturnType Rte_Start (void)
/* Description: Rte_Start is intended to allocate and initialize system resources and communication resources used by the RTE.
 * Note: Rte_Start is declared in the lifecycle header file Rte_Main.h.
 *  The initialization of AUTOSAR software-components takes place after the termination of Rte_Start and is triggered by a mode change event on entering run state.
 *
 * [SWS_Rte_01309] ⌈The Rte_Start API is always created.⌋(SRS_Rte_00051)
 *
 * [SWS_Rte_CONSTR_09035] Rte_Start shall be called only once
 *  ⌈Rte_Start shall be called only once by the EcuStateManager from trusted OS context on a core after the basic software modules required by RTE are initialized.⌋()
 *  These modules include: OS, COM, memory services
 *  The Rte_Start API shall not be invoked from AUTOSAR software components.
 *
 * [SWS_Rte_CONSTR_09036] Rte_Start API may only be used after call of SchM_Init
 *  ⌈The Rte_Start API may only be used after the Basic Software Scheduler is initialized (after termination of the SchM_Init).⌋()
 *
 * [SWS_Rte_CONSTR_09037] Rte_Start API shall be called on every core
 *  ⌈The Rte_Start API shall be called on every core that hosts AUTOSAR software components of the ECU.⌋()
 *
 *  [SWS_Rte_02585] ⌈Rte_Start shall return within finite execution time – it must not enter an infinite loop.⌋(SRS_Rte_00116)
 *
 *  Rte_Start may be implemented as a function or a macro.
 *
 * [SWS_Rte_01261] ⌈RTE_E_OK – No error occurred.⌋(SRS_Rte_00094)
 * [SWS_Rte_01262] ⌈RTE_E_LIMIT – An internal limit has been exceeded. The allocation of a required resource has failed.⌋(SRS_Rte_00094)
 */

Std_ReturnType Rte_Stop(void)
/* Description: Rte_Stop is used to finalize the RTE on the core it is called. This service releases all system and communication resources allocated by the RTE on that core.
 * Note: Rte_Stop is declared in the lifecycle header file Rte_Main.h.
 *
 * [SWS_Rte_CONSTR_09038] Rte_Stop shall be called before BSW shutdown
 *  ⌈ Rte_Stop shall be called by the EcuStateManager before the basic software modules required by RTE are shut down.⌋()
 *  These modules include: OS, COM, memory services
 *  Rte_Stop shall be called from trusted context and not by an AUTOSAR software component.
 *
 *  [SWS_Rte_02584] ⌈Rte_Stop shall return within finite execution time.⌋(SRS_Rte_00116)
 *
 *  Rte_Stop may be implemented as a function or a macro.
 *
 *  [SWS_Rte_01259] ⌈RTE_E_OK – No error occurred.⌋(SRS_Rte_00094)
 *  [SWS_Rte_01260] ⌈RTE_E_LIMIT – a resource could not be released.⌋(SRS_- Rte_00094)
 */

void Rte_PartitionTerminated_<PID>(void)

void Rte_PartitionRestarting_<PID>(void)

Std_ReturnType Rte_RestartPartition_<PID>(void)

void Rte_Init_<InitContainer>(void)
