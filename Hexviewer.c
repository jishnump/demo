/**************************** File manipulation application ******************/
/* Copyright (c) 2021 Trenser Technology Solutions (P) Ltd					 */
/* All Rights Reserved														 */
/*****************************************************************************/
/* File		: Hexviewer.c													 */
/* Summary	: To create hex viewer											 */
/* Note		:																 */
/* Author	: Jishnu M P													 */
/* Date		: 23/11/2021													 */
/*****************************************************************************/
//test1

/* User Defined Header Files */
#include<stdio.h>
#include<string.h>

/* Macros */
#define COLUMN				(16)
#define PRINTABLE_ASCII		(32)
#define BUFFER_MAX_SIZE		(100000)

/* typedef */

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

/****************************** Hexviewer **************************************/
/* Purpose	: To create hex viewer											   */
/* Inputs	: pucHexfile : To open file										   */
/* Outputs	: None															   */
/* Return	: None															   */
/* Notes	: It create a hex view of file									   */
/*******************************************************************************/
void main()
{
	FILE* pstFilePointer = NULL;						/* File pointer */
	uint32 ulExitControl1 = 0;							/* Loop exit controller */
	uint32 ulExitControl2 = 0;							/* Loop exit controller */
	uint32 ulLoopCounter = 0;							/* Loop Counter */
	uint8 pucStringContent[BUFFER_MAX_SIZE] = {0};		/* String contain file content */
	uint32 ulFileSize = 0;								/* File size */
	uint8 ucSpaceCounter = 0;							/* Allignment controller */
	uint32 ulAddressCounter = 0;						/* Byte address */
	uint32 ulBufferSize = 0;							/* Buffer size */

		/* Checking the file open */
		if( (pstFilePointer = fopen("extension.jpeg", "rb")) != NULL )
		{
			/* FInding file size */
			fseek(pstFilePointer, 0, SEEK_END);
			ucBufferSize = ftell(pstFilePointer);
			fseek(pstFilePointer, 0, SEEK_SET);

			/* Storing file content to buffer */
			for(ucExitControl1=0;ucExitControl1 < ucBufferSize;ucExitControl1++)
			{
				pucStringContent[ucExitControl1] = fgetc(pstFilePointer);
			}
			
			/* File close */
			fclose(pstFilePointer);
			ucFileSize = ucBufferSize;
			printf("0X%08lx	", ucAddressCounter);

			/* Printing address, hex value and ASCII character */
			for(ucExitControl1 = 0, ucLoopCounter = 1; ucExitControl1 < ucFileSize ;ucExitControl1++, ucLoopCounter++)
			{
				printf("%02x ", pucStringContent[ucExitControl1]);
				
				if(ucLoopCounter % COLUMN == 0)
				{
					ucExitControl2 = (ucExitControl1 - (COLUMN - 1));
					printf("	");
					
					for(;ucExitControl2 <= ucExitControl1 ; ucExitControl2++)
					{
						
						if(pucStringContent[ucExitControl2] < PRINTABLE_ASCII)
						{
							pucStringContent[ucExitControl2] = '@';
						}
						
						printf("%c", pucStringContent[ucExitControl2]);
					}
					
					printf("\n");
					ucAddressCounter = ucAddressCounter + COLUMN;
					printf("0X%08lx	", ucAddressCounter);
				}
			}

			/* Making allignment */
			ucSpaceCounter = ((ucExitControl1 - ucExitControl2) - 1);
			ucSpaceCounter = (COLUMN - ucSpaceCounter);

			for(ucLoopCounter = 0 ; ucLoopCounter < ucSpaceCounter ; ucLoopCounter++)
			{
				printf("   ");
			}

			printf("	");

			/* printing ASCII character */
			for(; ucExitControl2 < ucExitControl1 ; ucExitControl2++)
			{
				if(pucStringContent[ucExitControl2] < PRINTABLE_ASCII)
				{
					pucStringContent[ucExitControl2] = '@';
				}
				printf("%c", pucStringContent[ucExitControl2]);
			}

		}
		else
		{
			printf("File opening failed");
		}
	
}
/* EOF */
