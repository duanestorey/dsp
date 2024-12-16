#include "coefficients.h"
#include <stdio.h>

using namespace Audio;

Coefficients::Coefficients() {
     a0 = 0;
     a1 = 0;
     a2 = 0;
     b0 = 0;
     b1 = 0;
     b2 = 0;
}

void
Coefficients::normalize() {
    if ( a0 == 1 ) {
        return;
    }

    a1 = a1 / a0;
    a2 = a2 / a0;
    
    b0 = b0 / a0;
    b1 = b1 / a0;
    b2 = b2 / a0;

    a0 = 1;
}

void
Coefficients::print() {
    printf( "\n" );
    printf( "b0: %.15lf\n", b0 );
    printf( "b1: %.15lf\n", b1 );
    printf( "b2: %.15lf\n", b2 );

    printf( "a0: %.15lf\n", a0 );
    printf( "a1: %.15lf\n", a1 );
    printf( "a2: %.15lf\n", a2 );
}

double *
Coefficients::merged() {
    data[0] = b0;
    data[1] = b1;
    data[2] = b2;
    data[3] = a1;
    data[4] = a2;

    return data;
}