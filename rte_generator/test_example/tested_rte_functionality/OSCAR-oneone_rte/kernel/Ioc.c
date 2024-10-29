#include "Ioc.h"
#include "os.h"
#include "system.h"
#include "application_Cfg.h"
#include "lock.h"
#include "os_Cfg.h"
#include "core.h"
#include "task_Cfg.h"
#include "task.h"
#include "scheduler.h"
#include "ISRInit.h"
#include "systemcall.h"

void memcpy_j(int id, void *data, int n, int flag)
{
    IOCCB *cb = &icb[id];
    char *src = (char *)data;
    switch (flag)
    {
    case PUSH:
        for (int i = 0; i < n; i++)
        {
            cb->buffer[cb->tail] = *src;
            cb->tail = (cb->tail + 1) % cb->length;
            src = src + 1;
        }
        break;
    case POP:
        for (int i = 0; i < n; i++)
        {
            *src = cb->buffer[cb->head];
            cb->head = (cb->head + 1) % cb->length;
            src = src + 1;
        }
        break;
    default:
        break;
    }
}

Std_ReturnType IOC_API(int id, void *input_data, int flag)
{
    switch (id)
    {
    case aa:
    {
        struct IOC_aa_struct *d = (struct IOC_aa_struct *)input_data;
        if (flag == IOC_SEND1)
        {
            return SysIocSend_aa(d->data);
        }
        else if (flag == IOC_RECEIVER1)
        {
            return SysIocReceive_aa(d->data_r);
        }
        else if (flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_aa();
        }
        break;
    }
    case bb:
    {
        struct IOC_bb_struct *d = (struct IOC_bb_struct *)input_data;

        if (flag == IOC_SEND1)
        {
            return SysIocSend_bb(d->ptr, d->length);
        }
        else if(flag == IOC_RECEIVER1)
        {
            return SysIocReceive_bb(d->ptr, d->length_r);
        }
        else if(flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_bb();
        }
        break;
    }
    case cc:
    {
        struct IOC_cc_struct *d = (struct IOC_cc_struct *)input_data;
        if (flag == IOC_SEND1)
        {
            return SysIocSend_cc(d->ptr);
        }
        else if(flag == IOC_RECEIVER1)
        {
            return SysIocReceive_cc(d->ptr);
        }
        else if(flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_cc();
        }
    }
    case dd:
    {
        struct IOC_dd_struct *d = (struct IOC_dd_struct *)input_data;
        if (flag == IOC_SEND1)
        {
            return SysIocSendGroup_dd(d->data, d->ptr, d->length);
        }
        else if(flag == IOC_RECEIVER1)
        {
            return SysIocReceiveGroup_dd(d->data_r, d->ptr, d->length_r);
        }
        else if(flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_dd();
        }
    }
    case ee:
    {
        struct IOC_ee_struct *d = (struct IOC_ee_struct *)input_data;
        if (flag == IOC_SEND1)
        {
            return SysIocWrite_ee_sender1(d->ptr, d->length);
        }
        if (flag == IOC_SEND2)
        {
            return SysIocWrite_ee_sender2(d->ptr, d->length);
        }
        if (flag == IOC_SEND3)
        {
            return SysIocWrite_ee_sender3(d->ptr, d->length);
        }
        if (flag == IOC_RECEIVER1)
        {
            return SysIocRead_ee_receiver1(d->ptr, d->length_r);
        }
        if (flag == IOC_RECEIVER2)
        {
            return SysIocRead_ee_receiver2(d->ptr, d->length_r);
        }
    }
    }
}
// PUSH info to systask
Std_ReturnType SetCallbackfunctionAction(ApplicationType reveiverID, void (*callback)(void))
{
    CoreIdType CoreID = (ApplicationVar[reveiverID].CoreRef);
    if (_CoreID == CoreID)
    {
        SysTaskInformationType info;
        info.ApplID = reveiverID;
        info.FunctionPointer = callback;
        info.SysTaskAction = IOCCALLBACK;
        EnSysTaskActionQueue(info);
        ActivateTaskInternal(SysTaskID[_CoreID]);
        ScheduleKernel();
    }
    else
    {
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_CALLBACKFUNCTION;
        CrossCoreServicePara[CoreID].para1 = reveiverID;
        CrossCoreServicePara[CoreID].para2 = callback;
        // CrossCoreServicePara[reveiverID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1)
            ;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
    }
}
uint16 lock_aa = 0;
uint16 lock_bb = 0;
uint16 lock_cc = 0;
uint16 lock_dd = 0;
uint16 lock_ee = 0;
uint8 buffer_aa[30];
uint8 buffer_bb[30];
uint8 buffer_cc[30];
uint8 buffer_dd[30];
uint8 buffer_ee[100];
extern CoreIdType _CoreID;
static uint16 lock_bit = 7;

int arr_bb[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
ReceiverType receiver_aa[1] = {
    {
        .appID = app3,
        .callback = callback_aa,
    }};
ReceiverType receiver_bb[1] = {
    {
        .appID = app_lion,
        .callback = callback_bb,
    }};
ReceiverType receiver_cc[1] = {
    {
        .appID = app2,
        .callback = callback_cc,
    }};
ReceiverType receiver_dd[1] = {
    {
        .appID = app2,
        .callback = callback_dd,
    }};
ReceiverType receiver_ee[2] = {
    {
        .appID = app3,
        .callback = callback_ee_1,
    },
    {
        .appID = app3,
        .callback = callback_ee_2,
    }};
/*applicatzion mask*/
// app0
IocAutosarType Ioc_channel_sender[IOCID_COUNT] = {
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion),
    0 | (1 << app_lion) | (1 << app2)};
IocAutosarType Ioc_channel_receiver[IOCID_COUNT] = {
    0 | (1 << app3),
    0 | (1 << app2),
    0 | (1 << app3),
    0 | (1 << app2),
    0 | (1 << app3)};

IOCCB icb[IOCID_COUNT] = {
    {.head = 0,
     .tail = 0,
     .length = 10,
     .channel_receive_num = 1,
     .receiver = receiver_aa,
     .callbackFlag = 1,
     .lostFlag = 0,
     .buffer = buffer_aa},
    {.head = 0,
     .tail = 0,
     .length = 30,
     .channel_receive_num = 1,
     .receiver = receiver_bb,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_bb},

    {.head = 0,
     .tail = 0,
     .length = 30,
     .channel_receive_num = 1,
     .receiver = receiver_cc,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_cc},
    {.head = 0,
     .tail = 0,
     .length = 30,
     .channel_receive_num = 1,
     .receiver = receiver_dd,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_dd},
    {.head = 0,
     .tail = 0,
     .length = 100,
     .channel_receive_num = 2,
     .receiver = receiver_ee,
     .callbackFlag = 1,
     .lostFlag = 0,
     .buffer = buffer_ee}};



// #pragma section OSAPP_A01_SEC
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSend_aa(int data)
{
    struct IOC_aa_struct d;
    d.data = data;

    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = aa; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_A01_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocSend_aa(int data)
{
    Std_ReturnType ret = IOC_E_OK;
    
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[aa].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_aa, lock_bit);
        IOCCB *cb = &icb[aa];
        int data_size = sizeof(int);
        int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
        if (data_size > remain_size)
        {
            ret = IOC_E_LOST_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(aa, &data, sizeof(int), PUSH);

            if (ret == IOC_E_OK && icb[aa].callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_aa, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif

    return ret;
}
// #pragma section OSAPP_A03_SEC
#define OS_OSAPP_A03_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceive_aa(int *data)
{
    struct IOC_aa_struct d;
    d.data_r = data;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = aa;
    para.para2 = &d;
    para.para3 = IOC_RECEIVER1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
}
void callback_aa(void)
{
    int data;
    IocReceive_aa(&data);
    int k = data;
    data = k + 1;
    PrintText("callback sucess\r\n\0");
}
#define OS_OSAPP_A03_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocReceive_aa(int *data)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[aa].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_aa, lock_bit);
        IOCCB *cb = &icb[aa];
        int data_size = sizeof(int);
        int stored_size = (cb->tail - cb->head + cb->length) % cb->length;
        if (data_size > stored_size)
        {
            ret = IOC_E_NO_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(aa, data, sizeof(int), POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_aa, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
Std_ReturnType IocEmptyQueue_aa()
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = aa;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY; // flag 0: send / 1: receive
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

Std_ReturnType SysIocEmptyQueue_aa(void)
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[aa].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_aa, 1);
        IOCCB *cb = &icb[aa];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_aa, 1);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}

/***********************************************/
//(*arr,length)
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSend_bb(void *ptr, uint16 length)
{
    struct IOC_bb_struct d;
    d.ptr = ptr;
    d.length = length;

    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = bb;
    para.para2 = &d;
    para.para3 = IOC_SEND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_A01_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocSend_bb(void *ptr, uint16 length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[bb].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_bb, lock_bit);
        IOCCB *cb = &icb[bb];
        if (length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            int data_size = length + sizeof(uint16);
            int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
            if (data_size > remain_size)
            {
                ret = IOC_E_LIMIT;
                cb->lostFlag = 1;
            }
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(bb, &length, sizeof(uint16), PUSH);
            memcpy_j(bb, ptr, length, PUSH);
        }
        if (ret == IOC_E_OK && icb[bb].callbackFlag == 1)
        {
            for (int i = 0; i < cb->channel_receive_num; i++)
            {
                SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
            }
        }
        ReleaseLock(&lock_bb, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
// 
#define OS_OSAPP_A02_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceive_bb(void *ptr, uint16 *length)
{
    struct IOC_bb_struct d;
    d.ptr = ptr;
    d.length_r = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = bb;
    para.para2 = &d;
    para.para3 = IOC_RECEIVER1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
void callback_bb(void)
{
    int data;
    PrintText("callback sucess\r\n\0");
}
#define OS_OSAPP_A02_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReceive_bb(void *ptr, uint16 *length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[bb].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_bb, 1);
        IOCCB *cb = &icb[bb];
        if (cb->tail == cb->head)
        {
            ret = IOC_E_NO_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(bb, length, sizeof(uint16), POP);
            memcpy_j(bb, ptr, *length, POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_bb, 1);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

        // 
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
Std_ReturnType IocEmptyQueue_bb()
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = bb;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
Std_ReturnType SysIocEmptyQueue_bb(void)
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[bb].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_bb, 1);
        IOCCB *cb = &icb[bb];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_bb, 1);
    }
}

/***********************************************/
//(struct type* ptr)
// 不知道pack會不會影響
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSend_cc(str_cc *ref)
{
    struct IOC_cc_struct d;
    d.ptr = ref;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = cc;
    para.para2 = &d;
    para.para3 = IOC_SEND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
void callback_cc(void)
{
    int data;
    PrintText("callback sucess\r\n\0");
}
#define OS_OSAPP_A01_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocSend_cc(str_cc *ref)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[cc].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_cc, lock_bit);
        IOCCB *cb = &icb[cc];
        if (ret == IOC_E_OK)
        {
            int data_size = sizeof(str_cc);
            // full check
            // real length  = confuigure length - 1
            int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
            if (data_size > remain_size)
            {
                cb->lostFlag = 1;
                ret = IOC_E_LIMIT;
            }
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(cc, ref, sizeof(str_cc), PUSH);
        }
        if (ret == IOC_E_OK && icb[cc].callbackFlag == 1)
        {
            for (int i = 0; i < cb->channel_receive_num; i++)
            {
                SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
            }
        }
        ReleaseLock(&lock_cc, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
#define OS_OSAPP_A03_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceive_cc(str_cc *ref)
{
    struct IOC_cc_struct d;
    d.ptr = ref;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = cc;
    para.para2 = &d;
    para.para3 = IOC_RECEIVER1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
#define OS_OSAPP_A03_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReceive_cc(str_cc *ref)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[cc].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret = IOC_E_OK)
    {
        GetLock(&lock_cc, lock_bit);
        IOCCB *cb = &icb[cc];
        if (ret == IOC_E_OK)
        {
            if (cb->tail == cb->head)
            {
                ret = IOC_E_NO_DATA;
            }
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(cc, ref, sizeof(str_cc), POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_cc, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
Std_ReturnType IocEmptyQueue_cc(void)
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = cc;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY; 

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
Std_ReturnType SysIocEmptyQueue_cc()
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[cc].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_cc, lock_bit);
        IOCCB *cb = &icb[cc];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_cc, lock_bit);
    }
}

/***********************************************/
//(data,*arr,length)
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSendGroup_dd(int data, void *ptr, uint16 length)
{
    struct IOC_dd_struct d;
    d.data = data;
    d.ptr = ptr;
    d.length = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = dd;
    para.para2 = &d;
    para.para3 = IOC_SEND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
#define OS_OSAPP_A01_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocSendGroup_dd(int data, void *ptr, uint16 length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[dd].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_dd, lock_bit);
        IOCCB *cb = &icb[dd];
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            // data_size = (data + length + length
            int data_size = sizeof(int) + length + sizeof(uint16);
            int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
            if (data_size > remain_size)
            {
                cb->lostFlag = 1;
                ReleaseLock(&lock_dd, lock_bit);
                ret = IOC_E_LIMIT;
            }
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(dd, &data, sizeof(int), PUSH);
            memcpy_j(dd, &length, sizeof(uint16), PUSH);
            memcpy_j(dd, ptr, length, PUSH);
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_dd, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
#define OS_OSAPP_A02_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceiveGroup_dd(int *data, void *ptr, uint16 *length)
{
    struct IOC_dd_struct d;
    d.data_r = data;
    d.ptr = ptr;
    d.length_r = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = dd;
    para.para2 = &d;
    para.para3 = IOC_RECEIVER1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
void callback_dd(void)
{
    int data;
    int arr[10];
    int length;
    IocReceiveGroup_dd(&data, arr, &length);
    PrintText("callback sucess\r\n\0");
}
#define OS_OSAPP_A02_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReceiveGroup_dd(int *data, void *ptr, uint16 *length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[dd].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_dd, 1);
        IOCCB *cb = &icb[dd];
        if (cb->head == cb->tail)
        {
            ReleaseLock(&lock_dd, lock_bit);
            return IOC_E_NO_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(dd, data, sizeof(int), POP);
            memcpy_j(dd, length, sizeof(uint16), POP);
            memcpy_j(dd, ptr, *length, POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_dd, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
Std_ReturnType IocEmptyQueue_dd()
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = dd;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY; // flag 0: send / 1: receive
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
Std_ReturnType SysIocEmptyQueue_dd()
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[dd].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_dd, lock_bit);
        IOCCB *cb = &icb[dd];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_dd, lock_bit);
    }
}

/***********************************************/
// N:M　read write
// 3:2
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWrite_ee_sender1(void *ptr, uint16 length)
{
    struct IOC_ee_struct d;
    d.ptr = ptr;
    d.length = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = ee;
    para.para2 = &d;
    para.para3 = IOC_SEND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
#define OS_OSAPP_A01_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocWrite_ee_sender1(void *ptr, uint16 length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[ee].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_ee, lock_bit);
        IOCCB *cb = &icb[ee];
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(ee, &length, sizeof(uint16), PUSH);
            memcpy_j(ee, ptr, length, PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_ee, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWrite_ee_sender2(void *ptr, uint16 length)
{
    struct IOC_ee_struct d;
    d.ptr = ptr;
    d.length = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = ee;
    para.para2 = &d;
    para.para3 = IOC_SEND2;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
#define OS_OSAPP_A01_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocWrite_ee_sender2(void *ptr, uint16 length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[ee].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_ee, lock_bit);
        IOCCB *cb = &icb[ee];
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(ee, &length, sizeof(uint16), PUSH);
            memcpy_j(ee, ptr, length, PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_ee, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
#define OS_OSAPP_A01_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocWrite_ee_sender3(void *ptr, uint16 length)
{
    struct IOC_ee_struct d;
    d.ptr = ptr;
    d.length = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = ee;
    para.para2 = &d;
    para.para3 = IOC_SEND3;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

Std_ReturnType SysIocWrite_ee_sender3(void *ptr, uint16 length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[ee].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_ee, lock_bit);
        IOCCB *cb = &icb[ee];
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(ee, &length, sizeof(uint16), PUSH);
            memcpy_j(ee, ptr, length, PUSH);
            cb->tail = cb->head = 0;
            if (cb->callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_ee, lock_bit);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
#define OS_OSAPP_A03_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocRead_ee_receiver1(void *ptr, uint16 *length)
{
    struct IOC_ee_struct d;
    d.ptr = ptr;
    d.length_r = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = ee;
    para.para2 = &d;
    para.para3 = IOC_RECEIVER1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
void callback_ee_1(void)
{
    // int data;
    // SysIocReceive_ee(&data);
    // int k = data;
    // data = k+1;
    int td[10];
    int len_e1;
    IocRead_ee_receiver1(td, &len_e1);
    PrintText("callback sucess ee1\r\n\0");
}

#define OS_OSAPP_A03_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocRead_ee_receiver1(void *ptr, uint16 *length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[ee].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_ee, 1);
        IOCCB *cb = &icb[ee];
        memcpy_j(ee, length, sizeof(uint16), POP);
        memcpy_j(ee, ptr, *length, POP);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_ee, 1);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */

#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
#define OS_OSAPP_A03_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocRead_ee_receiver2(void *ptr, uint16 *length)
{
    struct IOC_ee_struct d;
    d.ptr = ptr;
    d.length_r = length;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = ee;
    para.para2 = &d;
    para.para3 = IOC_RECEIVER2;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}
void callback_ee_2(void)
{
    int td[10];
    int len_e2;
    IocRead_ee_receiver2(td, &len_e2);
    PrintText("callback sucess ee2\r\n\0");
}
#define OS_OSAPP_A03_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocRead_ee_receiver2(void *ptr, uint16 *length)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[ee].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_ee, 1);
        IOCCB *cb = &icb[ee];
        if (ret == IOC_E_OK)
        memcpy_j(ee, length, sizeof(uint16), POP);
        memcpy_j(ee, ptr, *length, POP);
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_ee, 1);
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)

    if (ret != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(ret);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if (ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(ret);
        }
#endif
    }
#endif
    return ret;
}
