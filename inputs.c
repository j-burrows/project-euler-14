/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Filename:	inputs.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "inputs.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Function:	input_int
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Function:	input_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Function:	input_ull
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
unsigned long long input_ull(){
	unsigned long long ull_input;
	fprintf(stdout, "\nPlease enter a value. A non number value will cause the "
					"unexpected behavour.\n\t\t\t\t->");
	scanf("%"SCNu64, &ull_input);
	
	return ull_input;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Function:	another_input
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Subroutine:	countdown
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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
