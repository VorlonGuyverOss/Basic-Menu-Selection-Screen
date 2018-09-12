//
//  menu.c
//  
//
//  Created by Forrest Green on 8/30/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "math_functions.h"

#define RECURSIVE_COUNT 5
#define SIZE            256
#define MAX_MENU_ITEMS  5

struct tm *clocker_time;

enum menu_process {
    e_case_0,             //enum value 0
    e_add,                //enum value 1
    e_subtract,           //enum value 2
    e_multiply,           //ends value 3
    e_divide,             //enum value 4
    e_menu_proces_count   //enum value 5
};

extern float exx; //found in math_functions.c

// Method to release all or try to recover gracefully from an unkwon error.
void release_all ( void ) {
    //release all statements here such as pointers, memory, open files, etc.
}


int menu                ( void );
void menu_actions       ( int replay );
void check_for_error    ( int choice );

//remove recursion to illustrate call compile process
//void count_out ( int count );

int main ( int argc, const char *argv[ ] ) {

    int replay = 1;
    
    do {
        printf ( "\n\n\tMAKE A SELECTION: \n");
        replay = menu ( );
        
        menu_actions ( replay );
        
        check_for_error ( replay );
        
    }while ( replay != 0);
    
    return ( 0 );
}

/*
 *
 *  Another way to create a method in a secure file. No need to create a prototype method if calling
 *  routine is after the compiler has had a chance to create a pionter in the compliation.
 *
 */

// Recursive function
void count_out ( int count ) {
    printf ( "EXITING PROGRAM!!!\n" );
    
    --count;
    
    if ( count > 0 ) {
        count_out ( count ); // Call recursion
    }
}

// Display menu items
int menu ( void ) {
    int choice = 0;
    
    printf ( "\n");
    printf ( "1. Add two numbers.\n" );
    printf ( "2. Subtract two numbers.\n" );
    printf ( "3. Multply two numbers.\n" );
    printf ( "4. Divide two numbers.\n" );
    printf ( "5. EXIT PROGRAM!!!\n" );
    printf ( "\n\t8. To demonstrate external varialble printout and cause exception due to not a valid menu choice.\n");
    
    printf ( "\n\n\t\tYour selection is: " );
    scanf ( "%d", &choice );
    
    if ( choice == 5 ) {
        choice = 0; // Set to zero for switch control demonstration and exit main program
        
        printf ( "\n\n" );
        
        count_out ( RECURSIVE_COUNT );
    }
    
    return ( choice );
}

void check_for_error ( int choice ) {
    
    // C does not provide direct support for error handling. It is expeceted for the engineer/developer/programmer
    // to test the return at each method call. One such way is:
    
    if ( !( choice >= 1 && choice <= MAX_MENU_ITEMS  ) ) {
        printf( "\n\nERROR, need a vaild menu selection!\t\t" );
    }
    
    if ( choice > MAX_MENU_ITEMS || choice < 0 ) {
        
        time_t timer_count;
        int count_down = 10; // timer is set for 10 seconds
        
        printf ("\n\n\t\tTry something else statment due to unknown error in system.\n\t\tTrying to recover..\n\n");
        
        release_all (); //release memory
        
        do {
            //DELAY for X seconds;
            timer_count = ( clock ( ) + ( CLOCKS_PER_SEC ) ); //timer is per second
            while ( timer_count > clock() ) {
            };
            
            // print out a timer to let user know status. Notice the "timer_count" output and how it counts to
            // create a delay structure
            printf("timer_count: %ld\tTimeout in: %d seconds.\n", timer_count, count_down);
            
            count_down--;
            
        }while ( count_down > 0 );
        
        // Either exit or place another method here to try something different
        exit ( 123 ) ;
    }
}

/*
 * Will get an implicite error if prototype function declariation is not before the calling method
 *
 * left here to demostrate where in other code it could cause issues if not having a prtotype function
 **/
/*
void count_out ( int count ) {
    printf ( "EXITING PROGRAM!!!\n" );
    
    --count;
    
    if ( count > 0 ) {
        count_out ( count );
    }
}
 */


/*
 *
 *  Below the switch case can be controlled via ENUM declaration in C due to how ENUM is processed. All enum
 *  names are actually in order of int number value. See enum above...
 *
 */
void menu_actions ( int replay ) {
    int first, second, result = 0;
    float result_f = 0.0;
    
    switch ( replay ) {
        defalut: break;
        
        //Added case to indicate numberical value of ENUM structure
        case e_case_0: {
            printf("\n\n\t\tCase enum value %d, ACTIVATE!\n\n", e_case_0);
            break;
        }
        
        case 1: {
            printf ( "\nYour first number: " );
            scanf ( "%d", &first );
            printf ( "\nYour second number: " );
            scanf ( "%d", &second );
            
            result = add ( first, second );
            
            printf ( "\n\tResult: %d", result );
            
            break;
        }
        
        case 2: {
            printf ( "\nYour first number: " );
            scanf ( "%d", &first );
            printf ( "\nYour second number: " );
            scanf ( "%d", &second );
            
            result = subtract ( first, second );
            
            printf ( "\n\tResult: %d", result );
            
            break;
        }
            
        //case 3: {
        case e_multiply: {
            printf ( "\nYour first number: " );
            scanf ( "%d", &first );
            printf ( "\nYour second number: " );
            scanf ( "%d", &second );
            
            result = multiply ( first, second );
            
            printf ( "\n\tResult: %d", result );
            
            break;
        }
            
        case 4: {
            printf ( "\nYour first number: " );
            scanf ( "%d", &first );
            printf ( "\nYour second number: " );
            scanf ( "%d", &second );
            
            result_f = divide ( first, second );
            
            printf ( "\n\tResult: %0.3f", result_f );
            
            break;
        }
            
        case 8: {
            printf( "Demonstrate an exteranl gloabal varialbe being changed by code:\n\n\tBefore change: %f", exx);
            
            exx = 22.55;
            
            printf( "\n\t\tChanged external gloabal varialbe to: %f", exx);
            
            printf( "\n\t\t\tChanged to format external gloabal varialbe to: %0.3f", exx);
        }
    }
}
