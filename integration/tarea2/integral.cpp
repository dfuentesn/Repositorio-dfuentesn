#include <iostream>
#include <cmath>
#include <functional>
#include <fstream>

using fptr = std::function<double(double)>;                          //Esto es para poder crear funciones en los double "fptr sad"
using algptr = std::function<double(int, fptr)>;                     //Este va para el algoritmo que usaremos en Richardson

double a = -5.0;                                                     //Acá defino el inicio del intervalo
double b = 5.0;                                                      //Acá defino el final del intervalo
double exact = 1.56898093601156;                                     //Acá defino el valor real de la integral como lo indico el profe en moodle

// Función a integrar: sin(e^x)                                      //Acá defino la función por integrar, si quisiera reusar el código la podría cambiar sin afectar nada
double f(double x) {
    return std::sin(std::exp(x));
}

// Integración por método del trapecio
double trapezoid(int n, fptr sad) {                                  //Acá defino la integral por el método del trapezio, para esta me guié por la realizada en clase 
    double deltax = (b - a) / n;                                     //Está línea define el ancho de los intervalos, en este caso [-5, 5]
    double sum = 0.0;
    for (int k = 1; k < n; k++) {                                    //Aquí pido que se sumen los puntos intermedio entre el intervalo, en este caso NO uso k menor igual a n
        double xk = a + k * deltax;                                  //Le pido que evalue la función en xk en el for, si se cumple entonces se vuelve un acumulador "+="
        sum += sad(xk);
    }   
    double result = deltax * (0.5 * sad(a) + sum + 0.5 * sad(b));    //El resultado entonces será el ancho del intervalo multiplicado por la suma de las sumatorias de cada función por los pesos que son 1/2
    return result;                                                   //Acá nos retornará entonces los valores finales para este método de integración
}

// Integración por método de Simpson
double simpson(int n, fptr sad) {                                    //Acá defino la integral por el método de Simpson, use de referencia la anterior + información del materiak de github
    if (n % 2 != 0) n++;                                             //Está línea verifica que n sea PAR
    double deltax = (b - a) / n;                                   
    double sum_odd = 0.0;                                            //Ya que use trapezoid como referencia, defino entonces por separado la sumas para impares y pares de K (no de n)
    double sum_even = 0.0;
    
    for (int k = 1; k < n; k++) {                                  
        double xk = a + k * deltax;
        if (k % 2 == 1) {                                            //Si K es impar, entonces sumara los valores en la sumatoria de impares
            sum_odd += sad(xk);
        } else {                                                     //Si k es par, la sumará en la otra sumatoria (está distinción es importante pues el peso será 4 para impares, 2 para pares)
            sum_even += sad(xk);                                     //Lo anterior lo podemos ver pues al ser aproximación por parábolas es más preciso si son diferentes puntos de ponderación
        }
    }
    double result = (deltax / 3.0) * (sad(a) + 4.0 * sum_odd + 2.0 * sum_even + sad(b));
    return result;
}

double richardson(int n, fptr sad, algptr alg, int alpha) {          //Acá defino a richardson por aparte para poder acortar las subsecuentes simpson y trapezoid
    double aux = std::pow(2.0, alpha);                               //Este es el factor de correlación de error de Richardson
    double val1 = alg(n, sad);                                       //Primera aproximación con n intervalos
    double val2 = alg(2 * n, sad);                                   //Segunda aproximación con el doble de intervalos
    double result = (aux * val2 - val1) / (aux - 1.0);               //Uso la fórmula de extrapolación para obtener Richardson
    return result;
}

double trapezoid_richardson(int n, fptr sad) {                       //Acá defino trapezoid a partir de Richardson
    return richardson(n, sad, trapezoid, 2);                         //Uso las particiones, la función fptr sad, trapezoid y el orden 2 
}

double simpson_richardson(int n, fptr sad) {                         //Acá defino simpson a partir de Richardson
    return richardson(n, sad, simpson, 4);                           //Uso las particiones, la función fptr sad, simpson y el orden 4
}

int main() {
    std::ofstream file("integral_errors.txt");                       //Con esto creo entonces el archivo de texto (para eso uso la libreria fstream)
    file.precision(15);                                              //El número de valores que quiero que me imprima
    
    for (int N = 2; N <= 2000000; N *= 2.0) {                        //En vez de N++ uso 2 para no aumentarlo en 1 a 1. Si quisiera que imprimiera mas o menos datos solo cambio el 2.0
        double trap = trapezoid(N, f);                               //Vuelvo a definir las funciones PERO esta vez con el N pedido en las instrucciones y la función sin
        double simp = simpson(N, f);
        double trap_rich = trapezoid_richardson(N, f);
        double simp_rich = simpson_richardson(N, f);
        
        double error_trapezoid = std::fabs((trap - exact) / exact);  //En este caso use fabs en vez de abs por los flotantes, con esto entonces defino el error absoluto
        double error_simpson = std::fabs((simp - exact) / exact);    //EL error absoluto es valor obtenido - valor real divido en valor real. Hago esto para todas las funciones
        double error_trapezoid_richardson = std::fabs((trap_rich - exact) / exact);
        double error_simpson_richardson = std::fabs((simp_rich - exact) / exact);

        //Ya aquí le digo que me imprima a mi archivo las cuatro líneas anteriores más las particiones N 
        file << N << " " << error_trapezoid << " " << error_simpson << " " << error_trapezoid_richardson << " " << error_simpson_richardson << "\n";
    }
    
    file.close();                                                      //Le pido que cierre el archivo
    std::cout << "Datos guardados en integral_errors.txt\n";           //Si corre el código y crea el texto entonces nos dirá esto en consola
    return 0;
}