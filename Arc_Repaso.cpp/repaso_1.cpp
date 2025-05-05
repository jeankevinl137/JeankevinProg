#include <iostream>
#include <cmath>
#include <string> 

int sum_divisor( int n);

int main(int argc, char const *argv[]){
   int n = std::stoi(argv[1]);
   
}
int sum_divisor(int n){
    int sum = 0;
    for (size_t i = 1; i <= n; i++){
      int a = i% 3; int b = i%5;
      if (a ==0 or b == 0)
      {
        sum+=i;
      }
        
    }
    return sum

}