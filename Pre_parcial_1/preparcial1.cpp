#include <cmath>
#include <iostream>
#include <fstream>

bool is_prime(long n)
{ bool flag = true;
    if (n%2 == 0)
    {
        flag = false; 
      return flag ;
    }
    else{
        for (int ii = 3; ii < std::sqrt(n)+1; ii = ii + 2){
    
            if(n%ii == 0)
            {
                flag = false;
                return flag;
            }
       }
    }
 
return flag;
}

void nth_twin_primes(long n){
    int k = 0, ii = 2;
    while ( k != n)
    { 
        if (is_prime(ii) == true and is_prime(ii+2) == true ){
            k++ ;    
        }
        ii++ ;
    }
   std::cout << "("<< ii-1  <<","<<ii+1 <<")";
}

void nth_twin_primes22(){
    std::ofstream file1("magnitud_primes.txt");
    int k = 0, ii = 2;
    for (int N = 1; N<=100; N++ )
    {
        while ( k != N)
        { 
            if (is_prime(ii) == true and is_prime(ii+2) == true ){
                k++ ;    
            }
            ii++ ;
        }
        double y = std::sqrt((ii-1)*(ii-1) + (ii+1)*(ii+1));
        file1 << N <<"  "
              << y
              <<std::endl;   
    }
    
   file1.close();
}
/*
int main (){
    nth_twin_primes22();
   
}
*/

/*
int main (){
    int n ;
    std::cout << "escribe el numero:  ";
    std::cin >> n;
    std::cout << "esta patreja es de primos gemelos: " ;
    nth_twin_primes(n);
    }
*/


