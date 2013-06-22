/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	inputs.c
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Provide functions for main methods that involve inputting data and exiting.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		November 17th 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#include "inputs.h"

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	input_int
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prompts and retreives a user entered number. Sends -1 to signify close.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@return:	integer_input,			The number the user entered.
 *				-1,						Close command issued.
 *				-2,						Memory Allocation Failed
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Prompts the user to enter a number. After an input has been made, it is
 *				checked to see if a close is desired. If so, it stores 0 and returns it. 
 *				Otherwise, it checks if valid number input. If so, it saves the integer 
 *				value of the data and returns it. Otherwise, it prompts the user again to
 *				input data.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Notes:		If a memory allocation fails, a value of -2 is returned.
 *				If a zero is wanted, it must be read as in string format before being 
 *				converted into an int, as atoi's error value is zero.
 * 	Errors:		If the inputted string is over 128 characters long, the program will crash.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int input_int(){
	int integer_input;								/*Will hold the inputted digit.*/
	char *string_input, *close;						/*raw data from command line inputted.*/
	int i;											/*Loop control.*/
	
	/*	Allocates memory for the the strings, checks if allocation was successful.	*/
	if( (string_input = malloc(128*sizeof(char))) == NULL){
		/*	Allocation failed, begin closing operations.	*/
		return -2;
	}
	if((close = malloc(129*sizeof(char))) == NULL){
		/*	Allocation failed, begin closing operations.	*/
		free(string_input);
		string_input = NULL;
		return -2;
	}
	
	/*	Prompts the user to enter new data until a valid input has been entered.	*/
	fprintf(stdout, "\nPlease input the desired digit, followed by the enter key. "
					"Inputting the word \"close\", or 'c', will close the program.");
	while(1){
		fprintf(stdout, "\n\t\t\t\t->");
		scanf("%s",string_input);
		
		/*	Converts the close string into lowercase version of the input.	*/
		for(i=0;i<strlen(string_input);i++){
			close[i] = tolower(string_input[i]);
		}
		close[strlen(string_input)] = '\0';
		
		/*	Checks to see if a valid input has been entered.	*/
		/*	Was close or c entered?	*/
		if((strcmp(close,"close") == 0) || (strcmp(close,"c")==0)){
			integer_input = -1;			/*The value for close command is stored.*/
			break;
		}
		if( strcmp(string_input,"0") == 0){		/*Needs to check if zero is entered.*/
			integer_input = 0;
		}
		/*	Was the input a valid digit?	*/
		if((integer_input = atoi(string_input))!=0){
			break;						/*Inputted number is stored and the loop breaks.*/
		}
		/*	The input was not valid and it prompts the user to enter another.	*/
		fprintf(stdout, "\nInvalid input, try again:");
	}
	
	free(string_input);
	string_input = NULL;
	free(close);
	close = NULL;
	
	return integer_input;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	input_string
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prompts and retreives a user entered word. Sends -1 to signify close.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@return:	string_input,			the first word that the user inputted.
 *				"close",				close command issued.
 *				NULL,					an error has occured while allocating memory
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Prompts the user to enter a word. If close or c was entered, it returns 0.
 *				If nothing was entered, it prompts the user to enter again. Otherwise, the
 *				inputted word is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Note: 		If a memory allocation fails, a value of -2 is returned.
 *  Errors:		If the inputted string is over 128 characters long, the program will crash.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
char* input_string(){
	char* string_input, *close;						/*string from command line inputted.*/
	int i;											/*Used for loop control.*/
	
	/*	Allocates memory for the the strings, checks if allocation was successful.	*/
	if( (string_input = malloc(128*sizeof(char))) == NULL){
		/*	Allocation failed, begin closing operations.	*/
		return "error";
	}
	if((close = malloc(129*sizeof(char))) == NULL){
		/*	Allocation failed, begin closing operations.	*/
		free(string_input);
		string_input = NULL;
		return NULL;
	}
	
	/*	Prompts the user to enter input. Continues to prompt if nothing was entered.	*/
	while(1){
		fprintf(stdout, "\n\nPlease input the desired word, followed by the enter key."
					   " Inputting the word \"close\" will close the program.\n\t\t\t\t->");
		scanf("%s",string_input);							/*Stores input in string.*/
		
		/*	Converts the close string into lowercase version of the input.	*/
		for(i=0;i<strlen(string_input);i++){
			close[i] = tolower(string_input[i]);
		} 
		close[strlen(string_input)] = '\0';
		
		/*	Is a close program desired?	*/
		if((strcmp(close,"close") == 0) || (strcmp(close,"c")==0)){
			string_input = "close";
			break;
		}
		/*	Checks if nothing was added, and prompts again if so.	*/
		if(strlen(string_input)==0){
			fprintf(stdout, "\nNothing entered, try again:");
			continue;
		}
		
		/*	Desired input was correct and valid, breaks and returns.	*/
		break;	
	}
	
	free(close);
	close = NULL;
	
	return string_input;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	input_ull
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prompts and retreives a user entered number. Sends -1 to signify close.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@return:	ull_input,			The number the user entered.
 === === === === === === === === === === === === === === === === === === === === === === ===
 * 	Errors:		A non number value entered will cause unexpected results.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
unsigned long long input_ull(){
	unsigned long long ull_input;
	fprintf(stdout, "\nPlease enter a value. A non number value will cause the "
					"unexpected behavour.\n\t\t\t\t->");
	scanf("%"SCNu64, &ull_input);
	
	return ull_input;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	another_input
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Asks the user to enter if they would like to enter another input. 
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@return:	1,					Another input is desired.
 *				0,					Another input is not desired.
 *				-2,					A memory allocation was unsuccessful.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	The user will be continously prompted to enter yes or no until they do enter
 *				either yes, no, y, or n. Once they do, entering y or yes will result in 1
 *				being returned. no or n will result in 0 being returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Note: 		If a memory allocation fails, a value of -2 is returned.
 * 	Errors:		If the inputted string is over 128 characters long, the program will crash.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int another_input(){
	char* string_input;							/*Buffer for the inputted word.*/
	int another;								/*Boolean value for to continue or not*/
	int i;										/*Loop control.*/
	
	/*	Allocates memory, checks if successful.	*/
	if( (string_input = malloc(128*sizeof(char))) == NULL){
		/*	Unsuccessful, return error value.	*/
		return -2;
	}
	
	/*	Asks the user to enter yes or no until they do enter yes, no, y, or n.	*/
	while(1){
		fprintf(stdout, "\n\nWould you like to do another process,"
						" enter yes or no?:\n\t\t\t\t->");
		
		scanf("%s", string_input);
		
		/*	Sets to lower case to make commands not case sensitive.	*/
		for(i=0;i<strlen(string_input);i++){
			string_input[i] = tolower(string_input[i]);
		}
		
		/*	Checks if a valid command was entered.	*/
		if(strcmp(string_input,"yes")==0 || strcmp(string_input,"y")==0){
			another = 1;						/*Given value for another input wanted.*/
			break;
		}
		if(strcmp(string_input,"no")==0 || strcmp(string_input,"n")==0){
			another = 0;						/*Given value for another input not wanted*/
			break;
		}
		else{									/*Invalid command, prompted again.*/
			fprintf(stdout, "\nInvalid input...");
		}
	}
	
	free(string_input);							/*string_input is never used again.*/
	string_input = NULL;
	
	return another;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	countdown
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	This function waits a given time in seconds, while displaying the time left
 *				in a countdown.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		timeout,			the number of seconds that will be counted down from.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Notes:		An additional second waited because if the computers time is close to 
 *				rolling over, a the full timout	time will not be waited.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
void countdown(int timeout){
	time_t current_second, next_second;
	
	/*	Finds the value of the next second according to the internal clock.	*/
	current_second = time(NULL);
	next_second = current_second + 1;
	
	/*	Waits till the clock rolls over to the next second before countdown.	*/
	while( (current_second = time(NULL)) < next_second);
	
	/*	Counts down in seconds the time remaining.	*/
	while(timeout > 0){
		/*	Time left until timeout is displayed.	*/
		fprintf(stdout, "%d...",timeout);
		/*	Waits until a until the time is the next second.	*/
		current_second = time(NULL);
		next_second = current_second + 1;
		while((current_second = time(NULL)) < next_second);
		/*	A second has been waited, timeout left is decrimented.	*/
		timeout--;
	}
}
