
#include <iostream>
#include <cstdlib>

bool esPrimo(long n);
long mayorFactorPrimo(long n);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }
    long n = std::stol(argv[1]);
    std::cout << mayorFactorPrimo(n) << std::endl;
    return 0;
}

bool esPrimo(long n) {
    if (n < 2) return false;
    for (long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

long mayorFactorPrimo(long n) {
    long mayor = 0;
    for (long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mayor = i;
            n /= i;
        }
    }
    if (n > 1) mayor = n;
    return mayor;
}
