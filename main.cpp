#include "dsp.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace Audio;

int main(int argc, char* argv[]) {
    printf( "\n" );
    printf( "DSP testing algorithms\n" );
    printf( "----------------------\n" );

    DSP *dsp = new DSP();
    Coefficients coeff;

    dsp->generate( DSP::FILTER_LOWPASS, 48000, 2000, coeff );
    coeff.print();
    dsp->generate( DSP::FILTER_HIGHPASS, 48000, 2000, coeff );
    coeff.print();
    dsp->generate( DSP::FILTER_BANDPASS, 48000, 2000, coeff );
    coeff.print();
    dsp->generate( DSP::FILTER_ALLPASS, 48000, 2000, coeff );
    coeff.print();    
    dsp->generate( DSP::FILTER_NOTCH, 48000, 2000, coeff );
    coeff.print();  
    dsp->generate( DSP::FILTER_PEAK, 48000, 2000, coeff, 0.7071, 6 );
    coeff.print();    
    dsp->generate( DSP::FILTER_LOWSHELF, 48000, 2000, coeff, 0.7071, 1 );
    coeff.print();    
    dsp->generate( DSP::FILTER_HIGHSHELF, 48000, 2000, coeff, 0.7071, 1 );
    coeff.print();  

    dsp->generate( DSP::FILTER_LOWPASS, 48000, 80, coeff );
    coeff.print();  
    dsp->generate( DSP::FILTER_HIGHPASS, 48000, 80, coeff );
    coeff.print(); 

    double *merged = coeff.merged();
    printf( "%lf %lf %lf %lf %lf\n", merged[0], merged[1], merged[2], merged[3], merged[4]);

    delete dsp;
    dsp = 0;

    return 0;
}