#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#ifndef TRUE
	#define TRUE ((boolean) 1)
#endif

#ifndef FALSE
	#define FALSE ((boolean) 0)
#endif

#ifndef S0
#define S0 0
#endif
#ifndef S1
#define S1 1
#endif
#ifndef S2
#define S2 2
#endif
#ifndef S3
#define S3 3
#endif
//typedef unsigned char	boolean;	/*		TRUE .. FALSE      */
typedef signed char 	sint8;		/*		-128 .. 127        */
typedef unsigned char	uint8;		/*		   0 .. 255        */
typedef signed short	sint16;		/*	      -32768 .. 32767      */
typedef unsigned short	uint16; 	/* 		   0 .. 65535  	   */
typedef signed long 	sint32;		/*	 -2147483648 .. 2147483647 */
typedef unsigned long 	uint32; 	/* 		   0 .. 4294967295 */

#endif