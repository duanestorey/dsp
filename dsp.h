#ifndef __DSP_H__
#define __DSP_H__

#include "coefficients.h"
#include <stdlib.h>

namespace Audio {

class DSP {
    public:
        enum FILTER_TYPE {
            FILTER_LOWPASS,
            FILTER_HIGHPASS,
            FILTER_BANDPASS,
            FILTER_NOTCH,
            FILTER_ALLPASS,
            FILTER_PEAK,
            FILTER_LOWSHELF,
            FILTER_HIGHSHELF
        };

    public:
        DSP();

        void generate( DSP::FILTER_TYPE filter, __uint32_t samplingFreq, double centerFreq,Coefficients &coeff, double Q = 0.70710678f, double gainDb = 0 );
};

}

#endif