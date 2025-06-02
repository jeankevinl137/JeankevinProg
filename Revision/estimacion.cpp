#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>

// Función para calcular el promedio
double promedio(const std::vector<double>& datos) {
    return std::accumulate(datos.begin(), datos.end(), 0.0) / datos.size();
}

// Función principal de ajuste lineal
void ajuste_lineal(const std::vector<double>& x, const std::vector<double>& y,
                   double& m, double& b, double& dm, double& db) {
    int N = x.size();
    double Ex = promedio(x);
    double Ey = promedio(y);

    double Exx = 0.0, Eyy = 0.0, Exy = 0.0;
    for (int i = 0; i < N; ++i) {
        Exx += x[i] * x[i];
        Eyy += y[i] * y[i];
        Exy += x[i] * y[i];
    }
    Exx /= N;
    Eyy /= N;
    Exy /= N;

    m = (Exy - Ex * Ey) / (Exx - Ex * Ex);
    b = (Exx * Ey - Ex * Exy) / (Exx - Ex * Ex);

    double s2 = (Eyy - Ey * Ey - m * m * (Exx - Ex * Ex)) * N / (N - 2);
    dm = std::sqrt(s2 / (N * (Exx - Ex * Ex)));
    db = std::sqrt(dm * dm * Exx);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_datos.txt" << std::endl;
        return 1;
    }

    std::string fname = argv[1];
    std::ifstream fin(fname);
    if (!fin) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<double> xdata, ydata;
    double x, y;
    while (fin >> x >> y) {
        xdata.push_back(x);
        ydata.push_back(y);
    }
    fin.close();

    double m, b, dm, db;
    ajuste_lineal(xdata, ydata, m, b, dm, db);

    const double e = 1.602176634e-19; // Carga elemental

    double h = m * e;
    double phi = -b * e;

    std::cout << "Pendiente m = " << m << " \u00b1 " << dm << std::endl;
    std::cout << "Ordenada b = " << b << " \u00b1 " << db << std::endl;
    std::cout << "h estimado = " << h << " J\u00b7s" << std::endl;
    std::cout << "\u03d5 estimado = " << phi << " J" << std::endl;

    return 0;
}