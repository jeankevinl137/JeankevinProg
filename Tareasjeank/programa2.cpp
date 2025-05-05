
#include <iostream>
#include <cmath>
#include <string> 

/*Declaración de la función que identifca si su  esntrada es primo y en dicho caso 
lo retorna y en caso contrario retorna cero 
*/
long long id_prime(long long n);


long long ult_fact_prime(long long N);

int main(int argc, char const *argv[] ){
long long N = std::stoll(argv[1]);
std::cout << ult_fact_prime(N);
}

/*esta función identifica si un numero n es primo o no, si o es lo imprime
y en caso contrario imprime cero, esto para facilitar la suma de solo primos*/

long long id_prime(long long n){      
    for (long long i = 2  ; i <= std::sqrt(n); i++){
      long long a = n%i;
      if (a == 0)   // si el residuo es cero entonces no es un primo y retorna cero
      {
        return 0;
      }
    }    
    return n;   // en caso de que ninguno lo divida (residuo cero) entences es primo y se imprime (n).

}

//funcion quese encarga de hallar el ultimo factor primo de N.
long long ult_fact_prime(long long N){
      long long A= id_prime(N); long long g = 1;
     if (A != 0){  // se descarta que sea primo para no hacer calculos demas en caso de que lo sea.
      return N;
     }
     else{
      for (long long i = 2; i <=  N/2 ; i++){ //el mayor numero que lo podria divir es N/2(cota superior)                                           por eso es la cota superior */
         if (id_prime(i) != 0) {
          long long a = N%i;
          if (a == 0){
            g = i ;    /* se guarda en g el factor primo como es un bucle y solo se puede guardar 1
           dato, asi el que se imprime es el mas grande; cumpliendo nuestro objetivo*/
  
         }
       
        }
       
      }
     }
     return g;
}

