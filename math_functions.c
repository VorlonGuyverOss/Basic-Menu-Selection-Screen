//
//  math_functions.c
//  
//
//  Created by Forrest Green on 8/30/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "math_functions.h"

#define MACRO_MULTIPLY_NUMBERS ( first * last )

float exx = 10.11;

int add ( int first, int last ) {
    //Demonstrate a macro in a header file
    return ( MACRO_ADD_NUMBERS );
}

int subtract ( int first, int last ) {
    return ( first - last );
}

int multiply ( int first, int last ) {
    // Demonstrate a macro in C file
    return ( MACRO_MULTIPLY_NUMBERS );
}

float divide ( int first, int last ) {
    // Demonstrate how to retun a type case math operation
    return ( ( float ) first / (float ) last );
}
