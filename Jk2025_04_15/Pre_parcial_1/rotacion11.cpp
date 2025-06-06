#include<iostream>
#include<vector>
#include<cmath>

//1.DECLARACIONES 

//MATRICES DE ROTACION, SOBRE CADA EJE
std::vector<double>matrix_x(double thetax);
std::vector<double>matrix_y(double thetay);
std::vector<double>matrix_z(double thetaz);
//FUNCIONES
void multi_matrices(std::vector<double>&A, int filasA, int columnasA, 
                    std::vector<double>&B, int filasB, int columnasB,
                    std::vector<double>&C);

void print_matrizz(std::vector<double>&G, int filasG, int columnasG, std::vector<double>&F);


int main (int argc, char* argv[])
{
    double vx,vy,vz ;
    std::cout<<"ingrese vx: ";
    std::cin>> vx;
    std::cout<<"ingrese vy: ";
    std::cin>> vy;
    std::cout<<"ingrese vz: ";
    std::cin>> vz;

   double theta_x,theta_y, theta_z;
    std::cout<<"ingrese theta_x: ";
    std::cin>> theta_x;
    std::cout<<"ingrese theta_y: ";
    std::cin>> theta_y;
     std::cout<<"ingrese theta_z: ";
    std::cin>> theta_z;
    std::vector<double> V ={vx, vy, vz};
    std::vector<double>mx = matrix_x(theta_x);
    std::vector<double>my =matrix_y(theta_y);
    std::vector<double>mz =matrix_z(theta_z);
    std::vector<double>C;
    multi_matrices(mz, 3, 3, my, 3, 3, C); // aqui se multilica mz * my (matrices) y se guarda en C la "mzy"
    std::vector<double>B;  //se crea la B para guardar mzy * mx  
    multi_matrices(C, 3, 3, mx, 3, 3, B); // ahora B tiene a "mzyx"
    std::vector<double>D;
    multi_matrices(B, 3, 3, V, 3, 1, D);
    std::vector<double>E;
    print_matrizz(D, 3, 1, E);

                   
}
//IMPLEMENTACIONES

void multi_matrices(
     std::vector<double>&A, int filasA, int columnasA, 
     std::vector<double>&B, int filasB, int columnasB,
     std::vector<double>&C )
{ 
    
    if (columnasA != filasB)
    {
        std::cerr<< " Las filas de la primera matriz y la las columnas de la segunda no coinciden";
    }
    C.assign(filasA * columnasB, 0);
    for(int i = 0; i < filasA; i++ )
    {
        for (int j = 0; i < columnasB; j++)
        {
            for (int k = 0; k < filasB; k++)
            {
                C[i * columnasB + j] = A[i * columnasA + k] * B[k * columnasB+ j];
            }
            
        }
        
    }
    

}

void print_matrizz(std::vector<double>&G, int filasG, int columnasG, std::vector<double>&F)
{
    for (int i = 0; i < filasG; i++)
    {
        for(int j = 0; j < columnasG; j++)
        {
            std::cout << F[i * filasG + j] << " ";
        }
        std::cout << "\n";
    }
    
}
//MATRICES DE ROTACIONES.

std::vector<double>matrix_x(double thetax){
    std::vector<double> m_x={1.0, 0.0, 0.0, 
        0.0, std::cos(thetax), -std::sin(thetax), 
        0.0, std::sin(thetax), std::cos(thetax) };
        return m_x;

}

std::vector<double>matrix_y(double thetay){
    std::vector<double> m_y={std::cos(thetay), 0.0, std::sin(thetay), 
        0.0, 1.0, 0.0, 
        -std::sin(thetay), 0.0, std::cos(thetay) };
    return m_y;

}


std::vector<double>matrix_z(double thetaz){
    std::vector<double> m_z={std::cos(thetaz), -std::sin(thetaz), 0.0, 
        std::sin(thetaz), std::cos(thetaz), 0.0, 
        0.0, 0.0, 1 };
        return m_z;

}