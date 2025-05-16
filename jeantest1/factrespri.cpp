#include <iostream>
#include <cmath>
#include <string>

#include "prime_utils.h"


int main(int argc, char **argv){

    // ./a.out -> argc = 1, argv = ["./a.out"]
    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]
    // ./a.out 10 0.55 -> argc = 3, argv = ["./a.out", "10", "0.55"]
    // ./a.out 300 400 -> argc = 3, argv = ["./a.out", "300", "400"]

    int valor = std::stoi(argv[1]);
   for (int ii = valor; ii<=50 ){
      if(isprime(ii)==true and ){

      }
   }
    std::cout << "\n";

    return 0;
}

