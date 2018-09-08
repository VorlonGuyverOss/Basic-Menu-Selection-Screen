#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "math_functions.h"

#define RECURSIVE_COUNT 5 


int menu ( void );
void count_out ( int count );
void menu_actions ( int replay );

int main ( int argc, char *argv[ ] )
{
	int replay = 1; 

	do
	{
		printf ( "\n\n\t\tMAKE A SELECTION: \n" );
	    	replay = menu ( );
	  
	        menu_actions ( replay );
       	       
	}while ( replay != 0 );


	return ( 0 );
}


int menu ( void )
{
	int choice = 0;

	printf ( "\n" );
	printf ( "1. Add two numbers.\n" );
	printf ( "2. Subtract two numbers.\n" );
	printf ( "3. Multiply two numbers.\n" );
	printf ( "4. Divide two numbers.\n" );
	printf ( "5. EXIT PROGRAM!!!\n");

	printf ( "\n\n\t\tYour selection is: " );
	scanf ( "%d", &choice );

	if ( choice == 5 )
	{
		choice = 0;
	
		printf ( "\n\n" );

		count_out ( RECURSIVE_COUNT );		
	}

	return ( choice );
}

void count_out ( int count )
{
	printf ( "EXITING PROGRAM!!!\n" );

	--count;
	
	if ( count > 0 )
	{
		count_out ( count );
	}
}

void menu_actions ( int replay )
{
	int first, second, result = 0;
	float result_f = 0.0;

	switch ( replay )
	{
		defalut: break;
	
		case 1:
			 {
				 printf ( "\nYour first number: " );
				 scanf ( "%d", &first );
				 printf ( "\nYour second number: " );
				 scanf ( "%d", &second );

				 result = add ( first, second );

				 printf ( "\n\tResult: %d", result );

				 break;
			 }
	 	
		case 2:
			 {
				 printf ( "\nYour first number: " );
				 scanf ( "%d", &first );
				 printf ( "\nYour second number: " );
				 scanf ( "%d", &second );

				 result = subtract ( first, second );

				 printf ( "\n\tResult: %d", result );

				 break;
			 }
		
		case 3:
			 {
				 printf ( "\nYour first number: " );
				 scanf ( "%d", &first );
				 printf ( "\nYour second number: " );
				 scanf ( "%d", &second );

				 result = multiply ( first, second );

				 printf ( "\n\tResult: %d", result );

				 break;
			 }
			 
		
		case 4:
			 {
				 printf ( "\nYour first number: " );
				 scanf ( "%d", &first );
				 printf ( "\nYour second number: " );
				 scanf ( "%d", &second );

				 result_f = divide ( first, second );

				 printf ( "\n\tResult: %0.3f", result_f );

				 break;
			 
			 }
	}
}
