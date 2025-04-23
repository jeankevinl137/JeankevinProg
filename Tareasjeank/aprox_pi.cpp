#include <iostream>
#include <cmath>

//se define la función para aproximar pi
double pi_aprox(int n);
//se define la función para la diferencia
double Diferencia (double N);
int main(){
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout <<pi_aprox(20) ;
for (int i = 1; i <= 20; i++ ){
    std::cout <<"iteracion: "<< i << "  Pi ~ "<< pi_aprox(i) <<" \t Diferencia: " << Diferencia(pi_aprox(i)) <<"\n" ; 
}
    return 0;
}

double pi_aprox(int n){
    double p = 0.0;
    for (int k = 0; k <= n ; k++){
       p += std::pow(16, k*(-1) )*((4.0/(8.0*k+1.0))-(2.0/(8.0*k+4.0))-(1.0/(8.0*k+5.0))-(1.0/(8.0*k+6.0)));
       
    }
    return p;
}

double Diferencia (double N){
    double d = std::abs(1-(N/M_PI));
    return d;
}