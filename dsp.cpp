#include "dsp.h"
#include <math.h>

using namespace Audio;

DSP::DSP() {

}

void 
DSP::generate( DSP::FILTER_TYPE filter, __uint32_t samplingFreq, double centerFreq, Coefficients &coeff, double Q, double gainDb ) {
    double omega = 2*M_PI*centerFreq/samplingFreq;
    double alpha = sin( omega ) / ( 2*Q );
    double A = sqrt( pow( (double)10.0, gainDb/(double)20.0 ) );

    switch( filter ) {
        case DSP::FILTER_LOWPASS:
            coeff.b0 = ( 1 - cos( omega ) ) / 2;
            coeff.b1 = 1 - cos( omega );
            coeff.b2 = ( 1 - cos( omega ) ) / 2;
            coeff.a0 = 1 + alpha;
            coeff.a1 = -2*cos( omega );
            coeff.a2 = 1 - alpha;

            break;
        case DSP::FILTER_HIGHPASS:
            coeff.b0 = ( 1 + cos( omega ) ) / 2;
            coeff.b1 = -(1 + cos( omega ) );
            coeff.b2 = ( 1 + cos( omega ) ) / 2;
            coeff.a0 = 1 + alpha;
            coeff.a1 = -2*cos( omega );
            coeff.a2 = 1 - alpha;

            break; 
        case DSP::FILTER_BANDPASS:
            coeff.b0 = Q*alpha;
            coeff.b1 = 0;
            coeff.b2 = -Q*alpha;
            coeff.a0 = 1 + alpha;
            coeff.a1 = -2*cos( omega );
            coeff.a2 = 1 - alpha;

            break;   
        case DSP::FILTER_NOTCH:
            coeff.b0 = 1;
            coeff.b1 = -2*cos( omega );
            coeff.b2 = 1;
            coeff.a0 = 1 + alpha;
            coeff.a1 = -2*cos( omega );
            coeff.a2 = 1 - alpha;

            break;
        case FILTER_ALLPASS:
            coeff.b0 = 1 - alpha;
            coeff.b1 = -2*cos( omega );
            coeff.b2 = 1 + alpha;
            coeff.a0 = 1 + alpha;
            coeff.a1 = -2*cos( omega );
            coeff.a2 = 1 - alpha;

            break;
        case FILTER_PEAK:
            coeff.b0 = 1 + A*alpha;
            coeff.b1 = -2*cos( omega );
            coeff.b2 = 1 - A*alpha;
            coeff.a0 = 1 + alpha/A;
            coeff.a1 = -2*cos( omega );
            coeff.a2 = 1 - alpha/A;

            break;  
        case FILTER_LOWSHELF:
            coeff.b0 = A*((A+1)-(A-1)*cos(omega)+2*sqrt(A)*alpha);
            coeff.b1 = 2*A*((A-1)-(A+1)*cos(omega));
            coeff.b2 = A*((A+1)-(A-1)*cos(omega)-2*sqrt(A)*alpha);
            coeff.a0 = (A+1)+(A-1)*cos(omega)+2*sqrt(A)*alpha;
            coeff.a1 = -2*((A-1)+(A+1)*cos(omega));
            coeff.a2 = (A+1)+(A-1)*cos(omega)-2*sqrt(A)*alpha;

            break;
        case FILTER_HIGHSHELF:
            coeff.b0 = A*((A+1)+(A-1)*cos(omega)+2*sqrt(A)*alpha);
            coeff.b1 = -2*A*((A-1)+(A+1)*cos(omega));
            coeff.b2 = A*((A+1)+(A-1)*cos(omega)-2*sqrt(A)*alpha);
            coeff.a0 = (A+1)-(A-1)*cos(omega)+2*sqrt(A)*alpha;
            coeff.a1 = 2*((A-1)-(A+1)*cos(omega));
            coeff.a2 = (A+1)-(A-1)*cos(omega)-2*sqrt(A)*alpha;

            break;          
    }

    coeff.normalize();
}