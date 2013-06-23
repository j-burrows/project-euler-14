/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemFourteen.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	A program that can take a user inputted value and finds and displays the
 |				starting number, under that value, which produces the longest Collatz chain.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		December 14th 2012.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef PROBLEMFOURTEEN_H
#define PROBLEMFOURTEEN_H 1

#include <stdio.h>

#include "inputs.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	collatz_chain_length
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Finds the number of terms in the collatz chain given a starting value.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		starting_value,		The value which the collatz chain will be based off.
 |	@return:	chain_length,		The length of the produced collatz chain.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Until the starting value equals one, if even it becomes n= n/2, if it is 
 |				even, it becomes n =3n+1, and the number of terms are incremented each 
 |				iteration. The total terms evaluated is returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int collatz_chain_length(unsigned long long starting_value);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	largest_collatz_chain
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Finds the largest collatz chain with numbers below a given number.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		below,				All starting values for checked collatz chains must be
 |									below this value.
 |	@return:	largest,			The length of the largest produced collatz chain.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	goes through every number below the given number, and checks the length. The
 |				term length is compared to the largest value, and swapped if larger. The 
 |				largest is then returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int largest_collatz_chain(int below);

#endif
