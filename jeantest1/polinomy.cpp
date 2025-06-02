#include <iostream>
#include <cmath>
#include <vector>
double eval (std::vector<double> S, double(x));
int main(){
    std::vector<double> V = {2,3,4,5} ;
    std::vector<double> A (V.size()-1);
    for(int ii= 1; ii<V.size(); ii++){
        //A.push_back(V[ii]*ii);
        A[ii-1] = V[ii] * (ii);

        std::cout << A[ii-1] <<"\n";
    }
   double x = 2.0; //ejemplo x = 2 si se quiere se puede poner el x desde alas consola
    std::cout << eval(A, x);
    return 0;
}
double eval (std::vector<double> S, double(x)){
    double sum=0.0;
    for(int ii = 0; ii< S.size(); ii++ ){
        sum += S[ii]*std::pow(x, S[ii]);
    }
    return sum;
}