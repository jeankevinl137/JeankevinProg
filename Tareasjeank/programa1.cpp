#include <iostream>
#include <cmath>
#include <string> 
/*se declara una funcion que identifica si su entrada es primo o no
si lo es se imprime este mismo numero y si no lo es se imprime cero,
 esto para facilitar la suma de solo primos*/

long long id_prime(long long n);


int main( int argc, char const *argv[]){
  long long N = std::stoi(argv[1]), sum_prime = 0;
  for (long  i = 2  ; i <= N; i++)
  {
    sum_prime += id_prime(i); // aqui por medio de un bucle for sumamos los primos y guardamos en sum_prime.
  }
  
  std::cout << sum_prime;   
}
long long id_prime(long long n){
    for (long long i = 2  ; i <= std::sqrt(n); i++){  
      long long a = n%i;
      if (a == 0)  // si el residuo es cero entonces no es un primo y retorna cero.
      {
        return 0;
      }
    }
    return n; // en caso de que ninguno lo divida (residuo cero) entences es primo y se imprime (n).


}
