#include <iostream>                                                                 //Entradas y salidas
#include <fstream>                                                                  //Para los txt
#include <vector>                                                                   //Para los vectores
#include <numeric>                                                                  //Para el accumulate
#include <cmath>                                                                    //Para sqrt, pow y demás funciones matemáticas

double promedio(const std::vector<double>& v) {                                     //En está función calculo el promedio de los vectores para la regresión lineal
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();                     
}

void ajuste_lineal(const std::vector<double>& x, const std::vector<double>& y,      //Aquí realizo la regresión lineal
                   double& m, double& b, double& delta_m, double& delta_b) {
    int N = x.size();                                                               //La cantidad de datos en x del txt

    double Ex = promedio(x);                                                        //Fórmula para el promedio de los datos en x o ecuación 1
    double Ey = promedio(y);                                                        //Fórmula para el promedio de los datos en y o ecuación 2
    double Exx = 0.0, Exy = 0.0;                                                    //Acumulador para los promedios de exx y exy
    for (size_t i = 0; i < N; ++i) {
        Exx += x[i] * x[i];                                                         //Promedio de las x**2
        Exy += x[i] * y[i];                                                         //Promedio de las y**2
    }
    Exx /= N;                                                                       //Retorno los valores a la sumatoria o ecuación 3
    Exy /= N;                                                                       //Lo mismo, ecuación 4

    double denominador = Exx - Ex * Ex;                                             //Simplifico las ecuaciones al definir el denominador exx - exx**2
    m = (Exy - Ex * Ey) / denominador;                                              //Aquí estimo la pendiente, ecuación 5
    b = (Exx * Ey - Ex * Exy) / denominador;                                        //Aquí estimo el intercepto, ecuación 6

    double square_root = std::accumulate(                                           //Cálculo del error cuadrático o ecuación 7
        x.begin(), x.end(), 0.0,
        [&](double acc, double xi) {
            size_t i = &xi - &x[0];                                                 //Índice del elemento actual
            double y_pred = m * xi + b;
            return acc + std::pow(y[i] - y_pred, 2);                                //Suma del error cuadrático
        }
    );
    square_root /= (N - 2);                                                         //Aquí divido el return por N-2 como se indica en la fórmula

    delta_m = std::sqrt(square_root / denominador);                                 //Cálculo del error de la pendiente o ecuación 8
    delta_b = std::sqrt(delta_m * delta_m * Exx);                                   //Cálculo del error del intercepto o ecuación 9
}

void constantes_fisicas(double m, double b) {                                       
    const double e = 1.602176634e-19;                                               //Valor de e indicado en moodle
    const double h_teorico = 6.62607015e-34;                                        //valor del h indicado en moodle

    double h_exp = m * e;                                                           //Cálculo de h por medio de la pendiente y e
    double phi_J = -b * e;                                                          //Cálculo del módulo de trabajo en JULIOS (ya que es un trabajo)
    double phi_V = -b;                                                              //Cálculo del módulo de trabajo en Voltios (no tiene sentido pero lo agrego porque muchos lo hicieron así)
    double diferencia_relativa = std::abs(h_exp - h_teorico) / h_teorico;           //Error entre los valor de phi

    std::cout.precision(16);                                                        //Para que me de 16 decimales
    std::cout.setf(std::ios::scientific);                                           //Para la notación científica
    std::cout << "---------------------------------------------------\n";
    std::cout << "Constante de Planck experimental h = " << h_exp << " J·s\n";
    std::cout << "Constante de Planck teórica     h = " << h_teorico << " J·s\n";
    std::cout << "\nDiferencia relativa = " << diferencia_relativa << "\n";
    std::cout << "\nFunción de trabajo en julios Φ = " << phi_J << " J\n";
    std::cout << "Función de trabajo en voltios Φ = " << phi_V << " V\n";
    std::cout << "---------------------------------------------------\n";
}

void guardar_ajuste(const std::vector<double>& x, const std::vector<double>& y,     //Aquí creo el archivo donde guardo los datos experimentales y la regresión
                    double m, double b) {
    std::ofstream file("ajuste_lineal.txt");
    for (size_t i = 0; i < x.size(); ++i) {
        file << x[i] << " " << y[i] << " " << m * x[i] + b << "\n";
    }
}

int main(int argc, char* argv[]) {                                                  //Para que pueda leer el ./a.out con el archivo
    if (argc != 2) {                                                                //Verifica que si se pase ese argumento (Nombre de archivo)
        std::cerr << "Uso: " << argv[0] << " archivo_datos.txt" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);                                                     //Abre el archivo de millikan
    if (!fin) {
        std::cerr << "No se pudo abrir el archivo " << argv[1] << std::endl;
        return 1;
    }

    std::vector<double> xdata, ydata;                                               //Lee los datos x y y del archivo con la función del moodle
    double x, y;
    while (fin >> x >> y) {
        xdata.push_back(x);
        ydata.push_back(y);
    }
    fin.close();

    if (xdata.size() < 2 || xdata.size() != ydata.size()) {                         //Verifica la coherencia y consistencia en los datos
        std::cerr << "Error: Datos insuficientes o inconsistentes." << std::endl;
        return 1;
    }

    double m, b, delta_m, delta_b;                                                  //Variables donde se almacenan los r4esultados del ajuste
    ajuste_lineal(xdata, ydata, m, b, delta_m, delta_b);

    std::cout.precision(16);                        
    std::cout.setf(std::ios::scientific);
    std::cout << "---------------------------------------------------\n";           //Aquí imprime los datos PERO en la consola para que se puedan verifica
    std::cout << "Pendiente m = " << m << " ± " << delta_m << "\n";
    std::cout << "Intercepto b = " << b << " ± " << delta_b << "\n";

    constantes_fisicas(m, b);                                                       
    guardar_ajuste(xdata, ydata, m, b);

    return 0;
}
