/******************************************************/
/* Author    : Ahmed Assaf                            */
/* Date      : 14 SEP 2020                            */
/* Version   : V02                                    */
/* LOG       : V01 -> Initial Creation                */
/*           : V02 -> Add to singed data              */
/******************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char         u8 ;
typedef unsigned short int    u16;
typedef unsigned  int 		  u32;
typedef unsigned  long long   u64;

typedef signed char        s8 ;
typedef signed short int   s16;
typedef signed long  int   s32; 

typedef enum
{
	NOT_OK,
	OK,

}ReturnStatus;

#ifndef NULL
#define NULL (void *) 0
#endif


#endif
