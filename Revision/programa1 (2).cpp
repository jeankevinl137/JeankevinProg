
#include <iostream>
#include <cmath>
#include <string>


// suma de numeros primos menores a n


// declaration
bool isItPrime(long n_number); // esta funcion evalua si el numero es primo
void isItprimePrint(long isItPrimeVariable); // esta funcion imprime el numero si es primo



// main

int main(int argc, char **argv){


    if(argc != 2){
        std::cerr << "el programa requiere un imput \n";
        return 1;
    }

    long vmax = std::stoi(argv[1]); // este coombierte el imput en la consola en un int
    long sumaPrimos = 0; // esta es la variable a la que se le van a empezar a sumar los numeros que se encuentren primos

    for ( int ii = 2 ; ii <= vmax; ii++)
    {
        isItprimePrint(ii); // imprime los primos que se encuentren.
        if(isItPrime(ii)==true){ //cuando se encuentre un primo se suma en la variable sumaPrimos
            sumaPrimos=sumaPrimos+ii;
        }
    }
    std::cout << "la suma de los primos por debajo de " << vmax << " " << "es: " << sumaPrimos << "\n";
    


}



// implementation

void isItprimePrint(long isItPrimeVariable){
       
    if(isItPrime(isItPrimeVariable) == true){

        std::cout << isItPrimeVariable << "\n";
        
    /*
    } else{
       std::cout << isItPrimeVariable << " " << "no es primo \n";
    */
        }
    
}


bool isItPrime(long n_number){

    bool flagg = true;

    if (n_number == 1){
        std::cerr << "numero fuera de rango \n";
        return false;
       }
       
     if (n_number == 2){
        return true;
       }

    if (n_number % 2 == 0) { // si el numero es par, pues entonces es primo, asi que descartamos los pares. nos ahorramos un poco de tiempo
        return false;
    }

    for (long ii = 3; ii <= std::sqrt(n_number)+1 ; ii=ii+2){
       
       if(n_number % ii == 0){
         flagg = false;
         break;
        }
    }

    return flagg ;
}
