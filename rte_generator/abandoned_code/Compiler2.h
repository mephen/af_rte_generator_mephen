#include "Compiler_Cfg.h" 
/***************************************************************************************/
/*2種 Memory class 的定義 */
/* 記憶體類AUTOMATIC應作為空定義提供，用於聲明本地指標。*/
#define AUTOMATIC 
/*
記憶體類TYPEDEF應作為空定義提供。此記憶體類應在類型定義中使用，其中不能指定記憶體限定符。
這對於定義指標類型(例如P2VAR)是必要的，其中巨集需要兩個參數。
可以在類型定義中指定第一個參數(到指標引用的記憶體位置的距離)，但此時不能定義第二個參數(指標本身的記憶體分配)。
因此，應用記憶體類TYPEDEF。
*/
#define TYPEDEF 
/***************************************************************************************/
/*1種 空指標 的定義*/
#define NULL_PTR                      ((void *)0) 
/***************************************************************************************/
/*內聯定義 inline */
#define INLINE                        inline
/*靜態定義 static */
#define LOCAL_INLINE                  static
/***************************************************************************************/
/*3種 Function 的定義*/

/*返回值不是指標的函數定義*/
#define FUNC(rettype, memclass)                                 rettype memclass
/*用於聲明和定義返回常量指標的函數的巨集*/
#define FUNC_P2CONST(rettype, ptrclass, memclass)               const rettype* ptrclass memclass
/*用於聲明和定義返回變量指標的函數的巨集*/
#define FUNC_P2VAR(rettype, ptrclass, memclass)                 rettype* ptrclass memclass
/***************************************************************************************/
/* 6種 Pointer 的定義*/

/*定義P2VAR巨集，用於聲明和定義RAM中的指標，指向變量。
指標本身是可修改的(例如ExamplePtr++)。指標的目標是可修改的(例如*ExamplePtr=5)。*/
#define P2VAR(ptrtype, memclass, ptrclass)                      ptrtype * ptrclass memclass

/*定義P2CONST巨集，用於聲明和定義RAM中指向指標本身可修改的常量的指標(例如ExamplePtr++)。
    指標的目標不可修改(唯讀)。*/
#define P2CONST(ptrtype, memclass, ptrclass)                    const ptrtype ptrclass * memclass

/* */
#define CONSTP2VAR(ptrtype, memclass, ptrclass)  ptrtype* const memclass ptrclass

/* 宣告和定義訪問常量的常量指標定義CONSTP2CONST巨集。
指標本身不可修改(固定地址)。指標的目標不可修改(唯讀)。 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const memclass ptrclass

/* 指向函數的指標的類型定義定義P2FUNC巨集。 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*ptrclass fctname)

/*指向函數的常量指標的類型定義定義CONSTP2FUNC巨集*/
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const ptrclass fctname) 

/***************************************************************************************/

/* 1種 常量 的定義*/

/* 定義常量宣告和定義的常量巨集。 */
#define CONST(type, memclass) memclass const type 

/***************************************************************************************/
/* 1種 變量 的定義*/

/* 定義變量宣告和定義的變量巨集。 */
#define VAR(type, memclass) memclass type 

/***************************************************************************************/
