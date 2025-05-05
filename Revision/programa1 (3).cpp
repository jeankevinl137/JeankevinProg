
#include <iostream>
#include <cstdlib>

bool esPrimo(int n);
int sumaPrimos(int limite);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    std::cout << sumaPrimos(n) << std::endl;
    return 0;
}

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int sumaPrimos(int limite) {
    int suma = 0;
    for (int i = 2; i < limite; ++i) {
        if (esPrimo(i)) suma += i;
    }
    return suma;
}
