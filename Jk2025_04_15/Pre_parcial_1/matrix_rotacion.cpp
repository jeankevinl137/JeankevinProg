#include <cmath>
#include <iostream>
#include <vector>

std::vector<double>matrix_x(double thetax);
std::vector<double>matrix_y(double thetay);
std::vector<double>matrix_z(double thetaz);

std::vector<double>product_matrix(std::vector<double>&A, std::vector<double>&B, int fil_A, int col_A, int fil_B, int col_B);

void print_matrix(const std::vector<double> & data, int m, int n);

int main(int argc, char **argv){
    const double vx = std::stoi(argv[1]);
    const double vy = std::stoi(argv[2]);
    const double vz = std::stoi(argv[3]);
    const double thetax = std::stoi(argv[4]);
    const double thetay = std::stoi(argv[5]);
    const double thetaz = std::stoi(argv[6]);
    std::vector<double>V = {vx, vy, vz};
    std::vector<double>m_x = matrix_x(thetax);
    std::vector<double>m_y =matrix_y(thetay);
    std::vector<double>m_z =matrix_z(thetaz);
    std::vector<double>m_zy =product_matrix(m_z, m_y, 3,3,3,3);
    std::vector<double>m_zyx =product_matrix(m_zy, m_x, 3,3,3,3);
    std::vector<double>m_zyxv =product_matrix(m_zyx, V, 3,3,3,1);

    print_matrix(m_zyxv, 3, 1);
    return 0;

}




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

std::vector<double>product_matrix(std::vector<double>&A, std::vector<double>&B,int fil_A, int col_A, int fil_B, int col_B ){
    std::vector<double>C(fil_A * col_B);
    for (int ii = 0; ii < fil_A; ii++)
    {
     double g = 0.0;
     for ( int jj = 0; jj < col_A; jj++)
     {   double g = 0.0;
         for(int kk = 0; kk < fil_B; kk++  )
           {
              g += A[ii * col_A + kk] * B[jj * fil_B + kk ];
           }
           C[ii * col_A + jj] = g;

        //g += A[ii * col_A + jj] * B[ii * col_A + jj];  //B[kk * fil_B + hh] B[kk * fil_B + jj]
        //jj++  ;   /* code */
     }
       //C[ii * col_A + jj] += g;
    }
    return C;
    
}


void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}