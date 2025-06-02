#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

double prom(std::vector<double> v);

int main(int argc, char **argv){
    std::vector<double> xdata;
    std::vector<double> ydata;
    std::vector<double> xx;
    std::vector<double> xy;
    std::vector<double> yy;

    double x = 0.0, y = 0.0;
    
    std::ifstream fin (argv[1]);
    while (fin >> x >> y){
        xdata.push_back(x);
        ydata.push_back(y);
        xx.push_back(x*x);
        xy.push_back(x*y);
        yy.push_back(y*y);
    }

    double sum_x = prom(xdata), sum_y = prom(ydata), sum_xx = prom(xx), sum_xy = prom(xy), sum_yy = prom(yy);
    double m = 0.0, b = 0.0, delta_m = 0.0, delta_b = 0.0, s = 0.0;
    int N = xdata.size();

    double div = sum_xx - std::pow(sum_x, 2);
    m = ((sum_xy)-(sum_x*sum_y))/div;
    b = ((sum_xx*sum_y)-(sum_x*sum_xy))/div;
    s =(sum_yy - std::pow(sum_y, 2) - (std::pow(m, 2)*(sum_xx - pow(sum_x, 2)))) * (N/(N-2));
    delta_m = s/(N*(sum_xx - std::pow(sum_x, 2)));
    delta_b = delta_m*sum_xx;
    s = sqrt(s);
    delta_m = sqrt(delta_m);
    delta_b = sqrt(delta_b);

    const double h = 6.62607015*std::pow(10, -34);
    const double e = 1.602176634*pow(10, -19);

    std::ofstream data("Data.txt");
    for(int ii = 0; ii < N; ++ii){
    data << xdata[ii] << "\t" << ydata[ii] << "\t" << xdata[ii]*(m) + b << "\n";

   }
    data.close();
}

double prom(std::vector<double> v){
    double sum = 0.0;
    for(auto val : v){
        sum += val;
    }
    return sum/v.size();
}
