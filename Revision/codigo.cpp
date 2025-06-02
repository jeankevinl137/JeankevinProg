#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>


double e(const std::vector<double> n);
double e2(const std::vector<double> n, const std::vector<double> m);

int main(){
    std::vector<double> x;
    std::vector<double> y;
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    
    std::ifstream fin ("datos.txt");
    std::ofstream file("grafica.txt");

    double ee = 1.602176634e-19;
    

    double xv;
    double yv;

    while ( fin >> xv >> yv){
        x.push_back(xv);
        y.push_back(yv);
        
    }
    for (size_t i = 0; i < x.size(); ++i) {
        
    
     double N = x.size();
     double Ex = e(x);
     double Ey = e(y); 
     double Exx = e2(x,x);
     double Exy = e2(x,y);
     double Eyy = e2(y,y); 
     double m = (Exy- Ex*Ey)/(Exx-Ex*Ex);
     double b = (Exx*Ey-Ex*Exy)/(Exx-Ex*Ex);
     double aux= N/(N-2);
     double s2 = aux * (Eyy-Ey*Ey-m*m*(Exx-Ex*Ex));
     double dm2 = s2/(N*(Exx-Ex*Ex));
     double db2 = dm2*Exx;
     double dm = sqrt(dm2);
     double db = sqrt(db2);
     double h = m * ee;
     double dh = dm * ee;
     double y_fit = m * x[i] + b;
      file << x[i] << " " 
                << y[i] << " "
                << y_fit << " "
                << m << " "
                << b << " "
                << dm << " "
                << db << " "
                << h << " "
                << dh << " "
                << std::endl;
        
     
    
    
    
    }
    
  


    fin.close();
    file.close(); 
    

    return 0;

}


double e(const std::vector<double> n){
    double N = n.size();
    double suma = 0.0;
    for( size_t i = 0; i < n.size(); ++i){
        suma = suma + n[i];
    }
    return suma / N;
}

double e2(const std::vector<double> n, const std::vector<double> m){
    double N = n.size();
    double suma = 0.0;
    for( size_t i = 0; i < n.size(); ++i){
        suma = suma + n[i] * m[i];

    }
    return suma / N;
}


