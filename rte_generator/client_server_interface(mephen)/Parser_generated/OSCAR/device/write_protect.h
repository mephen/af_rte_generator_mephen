/******************************************************************************
** Macro:       protected_write
** Description: This macro is used to write to a write-protected register.
**              Users should following the below protection unlock sequence.
**                  1. Write the fixed value 0000 00A5H to the protection command register.
**                  2. Write the desired value to the protected register.
**                  3. Write the bit-wise inversion of the desired value to the protected register.
**                  4. Write the desired value to the protected register.
**                  5. Verify that the desired value has been written to the protected register.
**                      Verify successful write of the desired value to the protected register by
**                      verifying that the error monitor bit in the protection status register is "0".
**                      In case the write was not successful, indicated by the error monitor bit set
**                      to "1", the entire sequence has to be restarted at step 1.
** Parameter:   preg: protection command register
**              pstatus: protection status register
**              reg: target register
**              value: the value that will be written to the target
** Return:      None
******************************************************************************/
#define protected_write(preg, pstatus, reg, value)  do {\
                                                        (preg)=0xa5u;\
                                                        (reg)=(value);\
                                                        (reg)=~(value);\
                                                        (reg)=(value);\
                                                    } while((pstatus)==1u)