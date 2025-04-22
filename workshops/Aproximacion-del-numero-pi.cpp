//Version beta del codigo para aproximacion de pi

#include <iostream>
#include <cmath>  // Para std::pow y M_PI

// Función que aproxima π usando la fórmula de Bailey-Borwein-Plouffe
double pi_aprox(int n) {
    double pi = 0.0;
    for (int k = 0; k <= n; ++k) {
        double term = 1.0 / std::pow(16, k) * (
            4.0 / (8 * k + 1) -
            2.0 / (8 * k + 4) -
            1.0 / (8 * k + 5) -
            1.0 / (8 * k + 6)
        );
        pi += term;
    }
    return pi;
}

int main() {
    std::cout.precision(16);              // Precisión de 16 cifras decimales
    std::cout.setf(std::ios::scientific); // Notación científica

    for (int n = 1; n <= 20; ++n) {
        double pi_est = pi_aprox(n);
        double rel_error = std::abs(1.0 - pi_est / M_PI);

        std::cout << "n = " << n
                  << ", pi_aprox(n) = " << pi_est
                  << ", error relativo = " << rel_error << std::endl;
    }

    return 0;
}
