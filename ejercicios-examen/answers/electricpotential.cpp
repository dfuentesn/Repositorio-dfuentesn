#include <fstream>
#include <iostream>
#include <cmath>

double potential(double x);
double dev_central(double x, double h);
double dev_central_richardson(double x, double h);
double electricfield(double x, double h);
double exact_derivative(double x);

int main(void){
    const double h = 0.02;

    std::ofstream file("campo.txt");
    file.precision(16);
    file.setf(std::ios::scientific);

    
    for (int ii = 0; ii <= 25; ii++){
        double x = ii*h;
        double exact= -exact_derivative(x);
        double numeric= electricfield(x,h);

        file << x << " " << exact << " " << numeric << std::endl;
    }
    file.close();
    return 0;
}

double potential(double x){
        double vx = 2*x*std::sin(x);
        return vx;
}

double dev_central(double x, double h){
    return (potential(x+h) - potential(x-h)) / (2*h);
}

double dev_central_richardson(double x, double h){
    double dev1 = dev_central(x, h);
    double dev2 = dev_central(x, h/2);
    return (4*dev2-dev1)/3;
}

double electricfield(double x, double h){
    return -dev_central_richardson(x,h);
}

double exact_derivative(double x){
    return (2*std::sin(x))+2*x*std::cos(x);
}
