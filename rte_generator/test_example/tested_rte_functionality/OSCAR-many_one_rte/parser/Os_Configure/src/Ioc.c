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
    case QUE:
    {
        struct IOC_QUE_struct *d = (struct IOC_QUE_struct *)input_data;
        if (flag == IOC_SEND_QUE_SND0)
        {
            return SysIocSend_QUE_SND0(d-> data_1);
        }
        if (flag == IOC_SEND_QUE_SND1)
        {
            return SysIocSend_QUE_SND1(d-> data_1);
        }
        if (flag == IOC_RECEIVER_QUE_RCV)
        {
            return SysIocReceive_QUE_RCV(d-> data_1_r);
        }
        else if(flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_QUE();
        }
        break;
    }
    case DEQUE:
    {
        struct IOC_DEQUE_struct *d = (struct IOC_DEQUE_struct *)input_data;
        if (flag == IOC_SEND_DEQUE_SND)
        {
            return SysIocSendGroup_DEQUE_SND(d-> ptr_1, d->length_1, d-> data_2, d-> data_3);
        }
        if (flag == IOC_RECEIVER_DEQUE_RCV)
        {
            return SysIocReceiveGroup_DEQUE_RCV(d-> ptr_1_r,d->length_1_r, d-> data_2_r, d-> data_3_r);
        }
        else if(flag == IOC_EMPTY)
        {
            return SysIocEmptyQueue_DEQUE();
        }
        break;
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


uint16 lock_QUE = 0;
uint8 buffer_QUE[3];
uint16 lock_DEQUE = 0;
uint8 buffer_DEQUE[5];
extern CoreIdType _CoreID;
static uint16 lock_bit = 7;

ReceiverType receiver_QUE[1] = {
    {
        .appID = App2,
        .callback = callback_QUE_QUE,
    },
};
ReceiverType receiver_DEQUE[1] = {
    {
        .appID = App2,
    },
};
IocAutosarType Ioc_channel_sender[IOCID_COUNT] = {
    0 | (1 << App1) | (1 << App2),
    0 | (1 << App1),
};

IocAutosarType Ioc_channel_receiver[IOCID_COUNT] = {
    0 | (1 << App2),
    0 | (1 << App2),
};

IOCCB icb[IOCID_COUNT] = {
    {.head = 0,
     .tail = 0,
     .length = 3,
     .channel_receive_num = 1,
     .receiver = receiver_QUE,
     .callbackFlag = 1,
     .lostFlag = 0,
     .buffer = buffer_QUE},
    {.head = 0,
     .tail = 0,
     .length = 5,
     .channel_receive_num = 1,
     .receiver = receiver_DEQUE,
     .callbackFlag = 0,
     .lostFlag = 0,
     .buffer = buffer_DEQUE},
};

#define OS_OSAPP_App1_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSend_QUE_SND0(int data_1)
{
    struct IOC_QUE_struct d;
    d.data_1 = data_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = QUE; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_QUE_SND0;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_App1_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocSend_QUE_SND0(int data_1)
{
    Std_ReturnType ret = IOC_E_OK;

    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[QUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_QUE, lock_bit);
        IOCCB *cb = &icb[QUE];
        int data_size = sizeof(int);
        int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
        if (data_size > remain_size)
        {
            ret = IOC_E_LOST_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(QUE, &data_1, sizeof(int), PUSH);

            if (ret == IOC_E_OK && icb[QUE].callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_QUE, lock_bit);
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

#define OS_OSAPP_App2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSend_QUE_SND1(int data_1)
{
    struct IOC_QUE_struct d;
    d.data_1 = data_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = QUE; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_QUE_SND1;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_App2_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocSend_QUE_SND1(int data_1)
{
    Std_ReturnType ret = IOC_E_OK;

    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[QUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_QUE, lock_bit);
        IOCCB *cb = &icb[QUE];
        int data_size = sizeof(int);
        int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
        if (data_size > remain_size)
        {
            ret = IOC_E_LOST_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(QUE, &data_1, sizeof(int), PUSH);

            if (ret == IOC_E_OK && icb[QUE].callbackFlag == 1)
            {
                for (int i = 0; i < cb->channel_receive_num; i++)
                {
                    SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
                }
            }
        }
        ReleaseLock(&lock_QUE, lock_bit);
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

#define OS_OSAPP_App2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceive_QUE_RCV(int *data_1)
{
    struct IOC_QUE_struct d;
    d.data_1_r = data_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = QUE; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_QUE_RCV;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_QUE_QUE(void)
{
    int data;
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_App2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReceive_QUE_RCV(int *data_1)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[QUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_QUE, lock_bit);
        IOCCB *cb = &icb[QUE];
        int data_size = sizeof(int);
        int stored_size = (cb->tail - cb->head + cb->length) % cb->length;
        if (data_size > remain_size)
        {
            ret = IOC_E_LOST_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(QUE, data_1, sizeof(int), POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_QUE, lock_bit);
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

Std_ReturnType IocEmptyQueue_QUE()
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = QUE;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY; // flag 0: send / 1: receive
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

Std_ReturnType SysIocEmptyQueue_QUE(void)
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[QUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_QUE, 1);
        IOCCB *cb = &icb[QUE];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_QUE, 1);
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
#define OS_OSAPP_App1_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocSendGroup_DEQUE_SND(void* ptr_1, int length_1, int data_2, uint8 data_3)
{
    struct IOC_DEQUE_struct d;
    d.ptr_1 = ptr_1;
    d.length_1 = length_1;
    d.data_1 = data_1;
    d.data_1 = data_1;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = DEQUE; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_SEND_DEQUE_SND;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

#define OS_OSAPP_App1_STOP_SEC_CODE
#include "OS_MemMap.h"

Std_ReturnType SysIocSend_DEQUE_SND(void* ptr_1, int length_1, int data_2, uint8 data_3)
{
    Std_ReturnType ret = IOC_E_OK;

    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_s[DEQUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_DEQUE, lock_bit);
        IOCCB *cb = &icb[DEQUE];
        if (length == 0 || length > cb->length)
        {
            ret = IOC_E_LENGTH;
        }
        if (ret == IOC_E_OK)
        {
            int data_size = length_1 + sizeof(int) + sizeof(int) + sizeof(uint8);
            int remain_size = (cb->head - cb->tail + cb->length - 1) % cb->length;
            if (data_size > remain_size)
            {
                cb->lostFlag = 1;
                ReleaseLock(&lock_dd, lock_bit);
                ret = IOC_E_LOST_DATA;
            }
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(DEQUE, &length_1, sizeof(int), PUSH);
            memcpy_j(DEQUE, ptr_1, length_1, PUSH);
            memcpy_j(DEQUE, &data_2, sizeof(int), PUSH);
            memcpy_j(DEQUE, &data_3, sizeof(uint8), PUSH);
        }
        if (ret == IOC_E_OK && icb[DEQUE].callbackFlag == 1)
        {
            for (int i = 0; i < cb->channel_receive_num; i++)
            {
                SetCallbackfunctionAction(cb->receiver[i].appID, cb->receiver[i].callback);
            }
        }
        ReleaseLock(&lock_DEQUE, lock_bit);
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

#define OS_OSAPP_App2_START_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType IocReceiveGroup_DEQUE_RCV(void* ptr_1, int *length_1, int *data_2, uint8 *data_3)
{
    struct IOC_DEQUE_struct d;
    d.ptr_1 = ptr_1;
    d.length_1_r = length_1;
    d.data_2_r = data_2;
    d.data_3_r = data_3;
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = DEQUE; // ioc channel
    para.para2 = &d; // parameter
    para.para3 = IOC_RECEIVER_DEQUE_RCV;
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

void callback_DEQUE_False(void)
{
    int data;
    PrintText("callback sucess\r\n\0");
}

#define OS_OSAPP_App2_STOP_SEC_CODE
#include "OS_MemMap.h"
Std_ReturnType SysIocReceiveGroup_DEQUE_RCV(void* ptr_1, int *length_1, int *data_2, uint8 *data_3)
{
    Std_ReturnType ret = IOC_E_OK;
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[DEQUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == IOC_E_OK)
    {
        GetLock(&lock_DEQUE, 1);
        IOCCB *cb = &icb[DEQUE];
        if (cb->head == cb->tail)
        {
            ReleaseLock(&lock_DEQUE, lock_bit);
            ret = IOC_E_NO_DATA;
        }
        if (ret == IOC_E_OK)
        {
            memcpy_j(DEQUE, length_1, sizeof(int), POP);
            memcpy_j(DEQUE, ptr_1, *length_1, POP);
            memcpy_j(DEQUE, data_2, sizeof(int), POP);
            memcpy_j(DEQUE, data_3, sizeof(uint8), POP);
            if (cb->lostFlag == 1)
            {
                cb->lostFlag = 0;
                ret = IOC_E_LOST_DATA;
            }
        }
        ReleaseLock(&lock_DEQUE, lock_bit);
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

Std_ReturnType IocEmptyQueue_DEQUE()
{
    SysServiceParaType para;
    para.serviceID = SERVICE_IOC;
    para.para1 = DEQUE;        // ioc channel
    para.para2 = NULL;      // parameter
    para.para3 = IOC_EMPTY; // flag 0: send / 1: receive
    para.result = IOC_E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack(&para);
    return para.result;
}

Std_ReturnType SysIocEmptyQueue_DEQUE(void)
{
    Std_ReturnType ret = IOC_E_OK;
    // how to get appID
    if (ret == IOC_E_OK && (~(SystemObjectAutosar[_CoreID]->IocAutosar_r[DEQUE].applicationsMask) & (1 << ExecutingApp[_CoreID])))
    {
        ret = IOC_E_NOK;
    }
    if (ret == E_OK)
    {
        GetLock(&lock_DEQUE, lock_bit);
        IOCCB *cb = &icb[DEQUE];
        cb->head = cb->tail = 0;
        ReleaseLock(&lock_DEQUE, 1);
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
