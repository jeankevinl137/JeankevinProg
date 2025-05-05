
#include <iostream>
#include <cstdlib>

bool esImpar(int n);
int sumaImparesFibonacci(int limite);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    std::cout << sumaImparesFibonacci(n) << std::endl;
    return 0;
}

bool esImpar(int n) {
    return n % 2 != 0;
}

int sumaImparesFibonacci(int limite) {
    int a = 1, b = 2, suma = 0;
    while (a <= limite) {
        if (esImpar(a)) suma += a;
        int temp = a + b;
        a = b;
        b = temp;
    }
    return suma;
}
