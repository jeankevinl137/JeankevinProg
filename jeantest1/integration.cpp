#include "integration.h"

double trapezoid(double a, double b, int N, fptr fun){
    double delta_x = (b - a)/N; double extrem_f = ((fun(a) + fun(b))/2.0);
    double sum_f = 0.0;
    for(int k = 1; k <= N-1; k++){
        fun(a + (k*delta_x));
        sum_f = sum_f + fun(a + (k*delta_x));
    }
    return delta_x*(sum_f + extrem_f);
}