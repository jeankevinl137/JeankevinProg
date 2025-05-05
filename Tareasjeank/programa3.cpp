#include <iostream>
#include <cmath>
#include <string>

/* declaración de la función de sum fibonachi, nos da
 la suma de los # fibonachi impares  menor igual a n.*/


long long sum_imp_fibonachi(long long n);


int main(int argc, char const *argv[] ){
    long long N = std::stoll(argv[1]);  // entrada de los valores por el usuario.
std::cout << sum_imp_fibonachi(N) ;      // se imprime el valor de dicha suma.
}

// se crea la función anteriormente mencionadaa apartir del siguiente algoritmo.

long long sum_imp_fibonachi(long long n){
    long a = 1 , b = 0 ,c = 0, sum_f = 0;
    for (long long i = 1; a+b <= n; i++)
    {
        c = a + b; //aqui se crea el siguiente numero de la serie de fibonachi
        b = a;     // se guarda el valor anterior de a en b, osea b_i+1 = a_i
        a = c;     // y aqui se guarda el valor de a_i+1 = c_i
        if (c%2 != 0) //se toman solo los valores impares osea con residuo diferente de cero repecto a 2
        {
            sum_f+=c; // se suman los valores impares
        }
        
    }
    return sum_f ; // se guarda el valor en la función.
    
}
