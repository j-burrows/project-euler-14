/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemFourteen.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	A program that can take a user inputted value and finds and displays the
 |				starting number, under that value, which produces the longest Collatz chain.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		December 14th 2012.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "ProblemFourteen.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	collatz_chain_length
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int collatz_chain_length(unsigned long long starting_value){
	int terms = 1;
	/*while not equal to one, the next term is evaluated*/
	while(starting_value != 1){
		/* if odd, next term is n = n/2*/
		if(starting_value % 2 == 0){
			starting_value /= 2;
		}
		/* if evem, next term is n = 3n+1*/
		else{
			starting_value = (3*starting_value) + 1;
		}
		terms++;
	}
	return terms;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	largest_collatz_chain
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int largest_collatz_chain(int below){
	int largest = 0, largest_terms = 0, terms;
	unsigned long long i;
	
	/*	Every possible starting value's length is calculated and compared agianst the current
	 *	largest collatz chain.	*/
	for(i=below-1;i>=1;i--){
		terms = collatz_chain_length(i);	/*Finds current values collatz chain length.*/
		/*Compares the current length to the largest length.*/
		if(terms>largest_terms){			/*Current is larger, sets largest to current.*/
			largest = i;
			largest_terms = terms;
		}
	}
	return largest;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	main
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Retrieves a user inputted value, and finds and displays the starting number,
 |				under that value, which produces the longest Collatz chain. Can detect
 |				close commands.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Errors:		If there was an error whilst retrieving the input, the program closes.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int main(int argc, char** argv){
	int largest, below;
	
	fprintf(stdout, "This Program will show the starting value that produces the largest"
					" Collatz chain below an entered number.");
	/*	Continously prompts the user for a value to operate on, until an error or close
	 *	command is issued.	*/
	while(1){
		below = input_int();
		
		/* Checks if an error or close command occured whilst getting input.	*/
		if( below == -2){
			fprintf( stderr, "\nAn error occured whilst getting input.");
			break;
		}
		if( below == -1){
			fprintf(stdout, "\nA close command was issued.");
			break;
		}
		
		/*	Calculates and displays the starting value which produces largest chain.	*/
		largest = largest_collatz_chain(below);
		fprintf(stdout, "The starting value, below %d, which produces the most terms is:"
						"\n\t%d\n\n\n\n", below, largest);
		
		/*	Asks the user if they would like to perform another operation.	*/
		if( another_input() == 1){			/*They would, so repeat prompt.*/
			continue;
		}
		else break;							/*No more desired, break prompt and close.*/
	}
	
	countdown(5);
	return 0;
}
