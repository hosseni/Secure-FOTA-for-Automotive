/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char         u8 ;
typedef unsigned short int    u16;
typedef unsigned  int         u32;
typedef unsigned  long long   u64;

typedef signed char        s8 ;
typedef signed short int   s16;
typedef signed long  int   s32; 

typedef bool Command_Return_Type;
typedef bool BL_Return_Type;

#define OK 0 
#define NOT_OK 1


#ifndef NULL
#define NULL (void *) 0
#endif

typedef enum 
{
  No_Version_Exist = 0,
  Current_Version,
  New_Version
}Version_Status_Type;


 
#endif  /* STD_TYPES.h */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
