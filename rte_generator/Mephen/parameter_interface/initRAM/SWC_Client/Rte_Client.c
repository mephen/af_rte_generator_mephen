#define RTE_CLIENT_C
#include "Rte_Client.h"

Impl_uint8 Rte_Prm_ClientRport_speed(){
    return get_speed();
}

Impl_uint16 Rte_Prm_ClientRport_height(){
    return get_height();
}