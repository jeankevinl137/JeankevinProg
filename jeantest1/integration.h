#pragma once
#include <cmath>
#include <functional>

using fptr = std::function<double(double)>; //std::function<double(double)>;
//trapezoid(0.0, 1.0, 10, fun)
double trapezoid(double a, double b, int N, fptr fun);

double gauss7(double a, double b, fptr fun);