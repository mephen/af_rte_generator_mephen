#include "Rte_Cs_Data_Management.h"
/*****************************************************************************/
/*for:
1. server_side_fn.
2. initEv & async_return_Ev case of for-loop event_check_fn. in os-task-body
*/
#include "Rte_Event_Cfg.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"