/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 | Filename:	inputs.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide functions for main methods that involve inputting data and exiting.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 17th 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef INPUTS_H
#define INPUTS_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <inttypes.h>

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	input_int
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Prompts and retreives a user entered number. Sends -1 to signify close.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	integer_input,			The number the user entered.
 |				-1,						Close command issued.
 |				-2,						Memory Allocation Failed
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Prompts the user to enter a number. After an input has been made, it is
 |				checked to see if a close is desired. If so, it stores 0 and returns it. 
 |				Otherwise, it checks if valid number input. If so, it saves the integer 
 |				value of the data and returns it. Otherwise, it prompts the user again to
 |				input data.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Notes:		If a memory allocation fails, a value of -2 is returned.
 |				If a zero is wanted, it must be read as in string format before being 
 |				converted into an int, as atoi's error value is zero.
 | 	Errors:		If the inputted string is over 128 characters long, the program will crash.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int input_int();

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	input_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Prompts and retreives a user entered word. Sends -1 to signify close.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	string_input,			the first word that the user inputted.
 |				"close",				close command issued.
 |				NULL,					an error has occured while allocating memory
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Prompts the user to enter a word. If close or c was entered, it returns 0.
 |				If nothing was entered, it prompts the user to enter again. Otherwise, the
 |				inputted word is returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Note: 		If a memory allocation fails, a value of -2 is returned.
 |  Errors:		If the inputted string is over 128 characters long, the program will crash.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern char* input_string();

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	input_ull
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Prompts and retreives a user entered number. Sends -1 to signify close.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	ull_input,			The number the user entered.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 | 	Errors:		A non number value entered will cause unexpected results.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern unsigned long long input_ull();

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	another_input
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Asks the user to enter if they would like to enter another input. 
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	1,					Another input is desired.
 |				0,					Another input is not desired.
 |				-2,					A memory allocation was unsuccessful.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	The user will be continously prompted to enter yes or no until they do enter
 |				either yes, no, y, or n. Once they do, entering y or yes will result in 1
 |				being returned. no or n will result in 0 being returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Note: 		If a memory allocation fails, a value of -2 is returned.
 | 	Errors:		If the inputted string is over 128 characters long, the program will crash.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int another_input();

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	countdown
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	This function waits a given time in seconds, while displaying the time left
 |				in a countdown.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		timeout,			the number of seconds that will be counted down from.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Notes:		An additional second waited because if the computers time is close to 
 |				rolling over, a the full timout	time will not be waited.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern void countdown(int timeout);


#endif
