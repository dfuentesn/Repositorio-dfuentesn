#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>

using fptr = std::function<double(double)>; 
using algptr = std::function<double(int, fptr)>;

const double a = -5.0;
const double b = 5.0;
const double exact = 1.56898093601156;

// Función a integrar: sin(e^x)
double f(double x) {
    return std::sin(std::exp(x));
}

// Integración por método del trapecio
double trapezoid(int n, fptr sad) {
    double deltax = (b - a) / n;
    double sum = 0.0;
    for (int k = 1; k < n; k++) {
        double xk = a + k * deltax;
        sum += sad(xk);
    }   
    double result = deltax * (0.5 * sad(a) + sum + 0.5 * sad(b));
    return result;
}

// Integración por método de Simpson
double simpson(int n, fptr sad) {
    if (n % 2 != 0) n++;
    double deltax = (b - a) / n;
    double sum_odd = 0.0;
    double sum_even = 0.0;
    
    for (int k = 1; k < n; k++) {
        double xk = a + k * deltax;
        if (k % 2 == 1) {
            sum_odd += sad(xk);
        } else {
            sum_even += sad(xk);
        }
    }
    double result = (deltax / 3.0) * (sad(a) + 4.0 * sum_odd + 2.0 * sum_even + sad(b));
    return result;
}

double richardson(int n, fptr sad, algptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);
    double val1 = alg(n, sad);
    double val2 = alg(2 * n, sad);
    double result = (aux * val2 - val1) / (aux - 1.0);
    return result;
}

double trapezoid_richardson(int n, fptr sad) {
    return richardson(n, sad, trapezoid, 2);
}

double simpson_richardson(int n, fptr sad) {
    return richardson(n, sad, simpson, 4);
}

int main() {
    std::ofstream file("integral.txt");
    file.precision(15);
    
    for (int N = 2; N <= 2000000; N = (N < 100) ? N + 1 : static_cast<int>(N * 1.2)) {
        double trap = trapezoid(N, f);
        double simp = simpson(N, f);
        double trap_rich = trapezoid_richardson(N, f);
        double simp_rich = simpson_richardson(N, f);
        
        double error_trapezoid = std::fabs((trap - exact) / exact);
        double error_simpson = std::fabs((simp - exact) / exact);
        double error_trapezoid_richardson = std::fabs((trap_rich - exact) / exact);
        double error_simpson_richardson = std::fabs((simp_rich - exact) / exact);
        
        file << N << " " << error_trapezoid << " " << error_simpson << " " << error_trapezoid_richardson << " " << error_simpson_richardson << "\n";
        
        if (N % 10000 == 0) {
            std::cout << "Progreso: N = " << N << "/2000000\n";
        }
    }
    file.close();
    std::cout << "Datos guardados en integral.txt\n";   
    return 0;
}