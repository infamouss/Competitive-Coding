/* Author : Avinash Awate, Contest Co-ordinator */
/*****************************************************************************
*               Programming Contest IITBombayX JEEadvRanking                *
*               --------------------------------------------                *
* Produce an industry standard program to output IIT JEE ranking            *
* Inputs : I.1) A file containing Roll number (7 digits) and marks in PCM   *
*          I.2) Cutoff percentage (Qualifying top %ile in each rank)        *
*          I.3) Number of merit list ranks to be output                     *
* Outputs: O.1) Merit list comprising Rank and roll number                  *
*          O.2) Total number of candidates in merit list                    *
*          O.3) Errors (invalid input and abnormal conditions)              *
*                                                                           *
*****************************************************************************/

/*****************************************************************************
*                                  Sample                                   *
*                                  ------                                   *
* Sample input file:                                                        *
* 1010101,60,75,55                                                          *
* 2010101,55,60,56                                                          *
* 3010101,50,65,45                                                          *
* 4010101,45,70,40                                                          *
* 5010101,53,68,64                                                          *
* 6010101,61,76,50                                                          *
* 7010101,69,84,48                                                          *
* 8010101,62,77,57                                                          *
* 9010101,55,70,50                                                          *
*                                                                           *
* Cutoff %ile = 50  (Choose top 50% i.e  top 5 students)                    *
* Required Ranks = 2 (Print the top two ranks)                              *
*                                                                           *
* Cutoff for Physics = 55 (marks of 5th student)                            *
* Cutoff for Chemistry = 70 (marks of 5th student)                          *
* Cutoff for Maths = 50 (marks of 5th student)                              *
*                                                                           *
* Average for maths < Average for physics < Average for chemistry           *
*                                                                           *
* Students selected :                                                       *
* 1010101,60,75,55                                                          *
* 6010101,61,76,50                                                          *
* 8010101,62,77,57                                                          *
* 9010101,55,70,50                                                          *
*                                                                           *
* Merit list printed :                                                      *
* 1 8010101                                                                 *
* 2 1010101                                                                 *
*                                                                           *
* No errors in input and processing                                         *
* No need for tie break                                                     *
*                                                                           *
*****************************************************************************/

/*****************************************************************************
*                              Ranking Rules                                *
*                              -------------                                *
* Tie Break Rules (In case of equal marks)                                  *
*          T.1) marks of subject with least average                         *
*          T.2) marks of subject with second least average                  *
*          T.3) roll number in ascending order                              *
* In case of equal marks at last place:                                     *
*     All candidates with marks equal to the last merit list candidate to   *
*     be printed. If 9000 ranks are required, then if merit list 9000 has   *
*     196 marks then all candidates with marks 196 to be included till we   *
*     reach 9900 (10% above). Report error if 9901 rank also has 196 marks. *
*                                                                           *
*****************************************************************************/

/*****************************************************************************
*                          Errors to be spotted                             *
*                          --------------------                             *
* 1) Invalid roll number            (contains errors such as non digits)    *
* 2) Roll number out of range       (has to be exactly 7 digits)            *
* 3) Invalid marks                  (contains errors such as non digits)    *
* 4) Marks out of range             (marks must be between -40 and 160)     *
* 5) Extra characters after record  (non blank characters after marks)      *
* 6) No valid records in input      (All input records are invalid)         *
* 7) Insufficient qualifying students after cutoff (as stated)              *
* 8) Merit list exceeds 10% of required ranks      (as stated)              *
*                                                                           *
*****************************************************************************/

/*****************************************************************************
*                       Source Code Organisation                            *
*                       ------------------------                            *
* testJEEadvRanking.cpp                                                     *
* This file contains C++ code which opens the input stream, obtains cutoff  *
* percentage and required merit list ranks from the command line. The file  *
* contains the main function as well as functions which print output/error. *
*                                                                           *
* JEEadvRanking.cpp                           (to be submitted by students) *
* This file contains 2 C++ functions.                                       *
*     readInput() : This function reads the input file by calling a         *
*                   readInputLine function interatively. It checks the      *
*                   syntax of each line (record). In case, any line has     *
*                   errors, the erroneous line is printed (by calling a     *
*                   function in contest.cpp) and the line is ignored. The   *
*                   input data is stored in appropriate data structures.    *
*     meritList() : This function processes accepted input and prepares     *
*                   the JEE merit list. It uses cutoff percentile as input. *
*                   Cutoff marks are calculated, for each subject. A        *
*                   student getting marks less than the cutoff in any       *
*                   subject is eliminated. The remaining students are       *
*                   sorted into a merit list. The function also uses        *
*                   number of students in merit list. The function calls    *
*                   printMerit function in (in a loop) to print the merit   *
*                   list one line at a time. The function spots two errors; *
*                   Insufficient number of students after cutoff and        *
*                   exceeding the required ranks in merit list              *
*                                                                           *
*****************************************************************************/

/* System Includes */
#include <stdio.h>
#include <stdlib.h>           /* to use atoi for converting string to integer */
#include "unistd.h"     //<unistd.h>           /* to use getopt fo processing command line */
#include <malloc.h>
#include <string.h>

/* External function prototypes */
extern int readInput();
extern int meritList();

/* Local #defines */
#define MAXLENGTH	(100)
#define SUCCESS		(0)
#define FAILURE		(-1)
#define TRUE		(1)
#define FALSE		(0)

/* External Globals */
int   cutoffPercentile;       /* Cutoff percentage */
int   ranksRequired;          /* Required number of merit rank holders */
float pAverage;               /* Average marks in Physics */
float cAverage;               /* Average marks in Chemistry */
float mAverage;               /* Average marks in Mathematics */
int   pCutoff;                /* Cutoff marks in Physics */
int   cCutoff;                /* Cutoff marks in Chemistry */
int   mCutoff;                /* Cutoff marks in Mathematics */

/* Accessible function prototypes */
char *readInputLine();
void printError(int, int);
void printMerit(int, long);

/* Local Globals */
static FILE *inputfp = NULL;    /* Input file pointer */
static FILE *outputfp = NULL;   /* Output file pointer */
static FILE *errorfp = NULL;    /* Error file pointer */

int main(int argc, char *argv[])
{
	int retval;                   /* Return value of function */
	char *inputfile = NULL;         /* Input file name */
	char *outputfile = NULL;        /* Output file name */
	char *errorfile = NULL;         /* Error file name */
	int totalStudents;            /* Total number of valid student marks */
	int totalRanks;               /* Actual number of merit rank holders */
	int index;                    /* To traverse arrays */
	char optionchar;              /* Option chracter returned by getopt */

	/* Set return value to SUCCESS */
	retval = SUCCESS;

	/* Set default value of cutoff and ranksRequired */
	cutoffPercentile = 100;   /* Accept top 100%. No cutoff. */
	ranksRequired = 0;        /* Default is 2% of total students */

	/* Process command line options */
	while ((optionchar = getopt(argc, argv, "i:o:e:c:r:")) != -1)
	{
		switch (optionchar)
		{
		case 'i':
			inputfile = optarg;
			break;
		case 'o':
			outputfile = optarg;
			break;
		case 'e':
			errorfile = optarg;
			break;
		case 'c':
			cutoffPercentile = atoi(optarg);
			break;
		case 'r':
			ranksRequired = atoi(optarg);
			break;
		case '?':
			if ((optopt == 'i') || (optopt == 'o') || (optopt == 'f'))
			{
				//fprintf(stderr, "Option -%c requires an argument.\n", optopt);
				printf("Option -%c requires an argument.\n", optopt);
			}
			else
			{
				//fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
				printf("Unknown option character `\\x%x'.\n", optopt);
			}
			retval = FAILURE;
		default:
			//fprintf(stderr, "Usage : testJEEadvRankingEntry [-i inputfile] [-o outputfile] [-e errorfile] [-c cutoff] [-r ranksRequired]\n");
			printf("Usage : testJEEadvRankingEntry [-i inputfile] [-o outputfile] [-e errorfile] [-c cutoff] [-r ranksRequired]\n");
			break;
		}
	}

	/* Ignore all non option arguments */
	if (retval == SUCCESS)
	{
		for (index = optind; index < argc; index++)
		{
			//fprintf(stderr, "Non-option argument %s\n", argv[index]);
			printf("Non-option argument %s\n", argv[index]);
		}
	}

	/* If everything OK so far, check validity of cutoff and required ranks */
	if (retval == SUCCESS)
	{   /* Correct command line syntax */
		if ((cutoffPercentile < 1) || (cutoffPercentile > 100))
		{
			//fprintf(stderr, "Invalid cutoff %d. Must be between 1 and 100.\n", cutoffPercentile);
			printf("Invalid cutoff %d. Must be between 1 and 100.\n", cutoffPercentile);
			retval = FAILURE;
		}
		if (ranksRequired < 0)
		{
			//fprintf(stderr, "Invalid required merit ranks %d. Must be > 0.\n", ranksRequired);
			printf("Invalid required merit ranks %d. Must be > 0.\n", ranksRequired);
			retval = FAILURE;
		}
	}

	/* If everything OK so far, open input, output and error files */
	if (retval == SUCCESS)
	{   /* Correct Options specified */
		/* Open input file */
		inputfp = stdin;      /* Default is standard input */
		if (inputfile != NULL)
		{
			inputfp = fopen(inputfile, "r");
			if (inputfp == NULL)
			{
				//fprintf(stderr, "Unable to open input file %s.\n", inputfile);
				printf("Unable to open input file %s.\n", inputfile);
				retval = FAILURE;
			}
		}
		/* Open output file */
		outputfp = stdout;    /* Default is standard output */
		if (outputfile != NULL)
		{
			outputfp = fopen(outputfile, "w");
			if (outputfp == NULL)
			{
				//fprintf(stderr, "Unable to open output file %s.\n", outputfile);
				printf("Unable to open output file %s.\n", outputfile);
				retval = FAILURE;
			}
		}
		/* Open error file */
		errorfp = stderr;     /* Default is standard error */
		if (errorfile != NULL)
		{
			errorfp = fopen(errorfile, "w");
			if (errorfp == NULL)
			{
				//fprintf(stderr, "Unable to open error file %s.\n", errorfile);
				printf("Unable to open error file %s.\n", errorfile);
				retval = FAILURE;
			}
		}
	}

	/* If everything OK so far, call function to read JEE student marks */
	if (retval == SUCCESS)
	{
		totalStudents = readInput();
		if (totalStudents < 0) { retval = FAILURE; }
	}

	/* If everything OK so far, call function to produce merit list */
	if (retval == SUCCESS)
	{
		if (ranksRequired == 0)
		{   /* Set default as 2% of students (rounded up) */
			ranksRequired = totalStudents / 50 + 1;
		}
		totalRanks = meritList();
		if (totalRanks < 0) { retval = FAILURE; }
	}

	/* Return from function */
	return(retval);
}

static char readBuffer[MAXLENGTH]; /* To read the inlut line */
static char *lastPointer;          /* Return Pointer to allocated string */

/*****************************************************************************
* The function reads an input line, allocates memeory, stores the line and  *
* returns a pointer                                                         *
* It returns a NULL pointer when EOF is reached                             *
*****************************************************************************/
char *readInputLine()
{
	int   inputChar;              /* Input Character */
	int   index;                  /* To update array */

	/* Initialise */
	if (lastPointer != NULL) { free(lastPointer); lastPointer = NULL; }
	index = 0;
	/* Read Line */
	while (((inputChar = fgetc(inputfp)) != EOF) && (inputChar != '\n'))
	{
		/* Update Array */
		if (index < MAXLENGTH) { readBuffer[index] = inputChar; }
		index++;
	}
	readBuffer[index] = 0;
	/* Store Line */
	if ((inputChar != EOF) || (index != 0))
	{
		lastPointer = (char *)malloc(strlen(readBuffer) + 1);
		strcpy(lastPointer, readBuffer);
	}

	return(lastPointer);
}

/* Error Number Definitions */
#define INVROLLNO       (1)   /* Invalid roll number           */
#define ROLLRANGE       (2)   /* Roll number out of range      */
#define INVMARKS        (3)   /* Invalid marks                 */
#define MARKSRANGE      (4)   /* Marks out of range            */
#define EXTRACHARS      (5)   /* Extra characters after record */
#define NORECORDS       (6)   /* No valid records in input (return value 0) */
#define LESSSTUDENTS    (7)   /* Less qualifying students after cutoff (Warning) */
#define MORESTUDENTS    (8)   /* Merit list exceeds 10% of required ranks (Warning) */

/*****************************************************************************
* The function prints errors. It accepts an error number.                   *
* Errors to be spotted:                                                     *
*     1) Invalid roll number                                                *
*     2) Roll number out of range                                           *
*     3) Invalid marks                                                      *
*     4) Marks out of range                                                 *
*     5) Extra characters after record                                      *
*     6) No valid records in input                                          *
*     7) Insufficient qualifying students after cutoff                      *
*     8) Merit list exceeds 10% of required ranks                           *
*****************************************************************************/
void printError(int errorNumber, int lineNumber)
{
	switch (errorNumber)
	{
	case INVROLLNO:
		//fprintf(errorfp, "%s. Error in line %d.\n", "Invalid roll number", lineNumber);
		printf("%s. Error in line %d.\n", "Invalid roll number", lineNumber);
		break;
	case ROLLRANGE:
		//fprintf(errorfp, "%s. Error in line %d.\n", "Roll number out of range", lineNumber);
		printf("%s. Error in line %d.\n", "Roll number out of range", lineNumber);
		break;
	case INVMARKS:
		//fprintf(errorfp, "%s. Error in line %d.\n", "Invalid marks", lineNumber);
		printf("%s. Error in line %d.\n", "Invalid marks", lineNumber);
		break;
	case MARKSRANGE:
		//fprintf(errorfp, "%s. Error in line %d.\n", "Marks out of range", lineNumber);
		printf("%s. Error in line %d.\n", "Marks out of range", lineNumber);
		break;
	case EXTRACHARS:
		//fprintf(errorfp, "%s. Error in line %d.\n", "Extra characters after record", lineNumber);
		printf("%s. Error in line %d.\n", "Extra characters after record", lineNumber);
		break;
	case NORECORDS:
		//fprintf(errorfp, "%s. Error.\n", "No valid records in input");
		printf("%s. Error.\n", "No valid records in input");
		break;
	case LESSSTUDENTS:
		//fprintf(errorfp, "%s. Error.\n", "Insufficient qualifying students after cutoff");
		printf("%s. Error.\n", "Insufficient qualifying students after cutoff");
		break;
	case MORESTUDENTS:
		//fprintf(errorfp, "%s. Error.\n", "Merit list exceeds 10% of required ranks");
		printf("%s. Error.\n", "Merit list exceeds 10% of required ranks");
		break;
	default:
		//fprintf(errorfp, "%s. Error.\n", "************ Unknown Error ************");
		printf("%s. Error.\n", "************ Unknown Error ************");
		break;
	}
}

/*****************************************************************************
* The function prints one line of the merit list. It accepts a rank and a   *
* roll number.                                                              *
*****************************************************************************/
void printMerit(int rank, long rollNumber)
{
	fprintf(outputfp, "%d %ld\n", rank, rollNumber);
}
