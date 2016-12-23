#ifndef SIMILARWORDS
#define SIMILARWORDS
/* Author : Avinash Awate */
/*****************************************************************************
*                                                                           *
* This file cotains the global definitions which can be used by the code    *
* submitted by the participants                                             *
* It specifies the data communication between the participant function and  *
* the calling code                                                          *
* The participant code must include this file for it to compile successfully*
*                                                                           *
*****************************************************************************/

/* Limit #defines to be used by participant submission */
#define SUCCESS		(0)
#define FAILURE		(-1)
#define TRUE		(1)
#define FALSE		(0)

/* Globals */
extern int    inputWords;       /* Number of input words */
extern char **inputArray;       /* Array of input words */
extern int  *firstWordIndex;    /* Index of the first word of a similar pair */
extern int  *similarWordIndex;  /* Index of the second word of a similar pair */

#endif
