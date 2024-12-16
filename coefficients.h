#ifndef __COEFFICIENTS_H__
#define __COEFFICIENTS_H__

namespace Audio {

class Coefficients {
    public:
        double a0;
        double a1;
        double a2;
        
        double b0;
        double b1;
        double b2;

        double data[5];

        Coefficients();
    
        void normalize();
        void print();
        double *merged();
};

}

#endif