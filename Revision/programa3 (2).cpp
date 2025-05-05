

#include <iostream>
#include <string>
#include <cmath>

//  suma de impares menores a n en secuencia de fibonacci


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " \n";
        return 1;
    }
 

    int n = std::stoi(argv[1]); 

    if (n < 2) {
        std::cerr << "El número debe ser mayor o igual a 2" << "\n";
        return 1;
    }

  // definicion de variables

    int a = 1;
    int b = 2;
    int suma_impares = 0;

    while (a <= n) { // mientras que a sea menor igual a n
        if (a % 2 != 0) { // si el modulo de a con 2 es diferente de 0 ,,, osea si a es impar
            suma_impares = suma_impares + a;
        }

        int siguiente = a + b; // de esta manera se implementa la secuencia.

        a = b;

        b = siguiente;
    }

    std::cout << "La suma de los términos impares menores o iguales a " << n << " es: " << suma_impares << "\n";

    return 0;
}






/*

codigo fallido


#include <iostream>
#include <cmath>
#include <string>

void secuenciafibonacci(long n);


int main(int argc, char** argv){

    long input = std::stol(argv[1]);


    if(input < 2){
        std::cerr << "numero fuera de rango \n";
        return 0;
    }

    if(input == 2){
        std::cerr << " la suma de los impares es 1 \n";
        return 0;
    }else{
        std::cout << "1 \n2 \n";

    }

    secuenciafibonacci(input);

return 0;
}



//implementacion


void secuenciafibonacci(long n){
    
    long varsec = 1+2;

    for (long i = 3; i <= n; i++)
    {
        varsec = varsec + i;
        std::cout << varsec << "\n";
    }
    
   
    

}


*/