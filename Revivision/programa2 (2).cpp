
//factor primo mas grande para un numero que se escriba en la barra de comando

#include <iostream>
#include <cmath>
#include <string>




// el codigo funciona, pero no logre optimizarlo para el ultimo numero gigantesco.





// declaration
bool isItPrime(long long numberToCheck); // esta funcion evalua si el numero es primo


// main

int main(int argc, char **argv){

  if(argc != 2){
        std::cerr << "el programa requiere un imput \n";
        return 1;
    }

    long long vmax = std::stoll(argv[1]); // este coombierte el imput en la consola en un int

    long long primefactor;
    
    
    if (vmax <= 1)
        {
            std::cerr << "valor fuera de rango \n";
            return 1;
        }

    if(isItPrime(vmax) == true){

             std::cout << vmax << "\n" ;
            return 0;           
        }
  
    
    for ( long long idx_main = vmax ; idx_main >= 2 ; idx_main--)
    {
        
        if(isItPrime(idx_main) == true){

            std::cout << "primos encontrados :" << idx_main << "\n"; 

            if (vmax % idx_main == 0){

               primefactor = idx_main;
               //std::cout << "factor en if: " << primefactor << "\n" ;
               break;
            }
            
        }

    }
    
std::cout << "raiz del valor en terminal: " << std::sqrt(vmax) << "\n" ;

std::cout << "valor escrito en terminal: " << vmax << "\n" ;
std::cout << "mayor factor primo: " << primefactor << "\n" ;

return 0;
}



// implementation


bool isItPrime(long long numberToCheck){
    
    bool finalflag; 

    if (numberToCheck <= 1){
        std::cerr << "numero fuera de rango \n";
        return false;//  le dice a la funcion su valor que devuelve, entonces entrega su valor y para.
       }
       
    if (numberToCheck == 2){
        return true; // por que 2 es un primo que no cumple la regla del algoritmo.
       }

    if (numberToCheck % 2 == 0) { // si el numero es par, pues entonces es primo, asi que descartamos los pares. nos ahorramos un poco de tiempo
        return false;
    }

   for (long long Indx_isPrim_Fr = 3; Indx_isPrim_Fr <= std::sqrt(numberToCheck)+1 ; Indx_isPrim_Fr=Indx_isPrim_Fr+2){ // hacemos que el algoritmo solo revise impares.
       
       if(numberToCheck % Indx_isPrim_Fr == 0){
         return false;
        }// tambien se podria usar un else??? para que bote el return true?
    }
    
finalflag = true; // esta linea me dice que como no se encontro ningun caso falso entonces deve ser un numero primo y me devuelve verdadero.

return finalflag;
}
