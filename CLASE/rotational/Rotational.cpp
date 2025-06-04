#include <iostream>                                                                                     //para las salidas y las entradas
#include <vector>                                                                                       //para los vectores
#include <cmath>                                                                                        //para el seno y el coseno
#include <string>                                                                                       //para las cadenas 

//Funcion de las matices rotacionales (EN X Y Y Z)
void rotational_matrix(double t, char axis, std::vector<double>& M) {                                   //recibe angulo en radianes, el eje (x,y,z) y la lista para la matris 3x3
    double c = std::cos(t), s = std::sin(t);                                                            //acorto seno y coseno en radianes a c y s por fines esteticos no mas jaja
    if (axis == 'x') M = {1,0,0,    0,c,-s,    0,s,c};                                                  //La martis ROTACIONAL del eje x (como size = 9, es 3x3)
    else if (axis == 'y') M = {c,0,s,    0,1,0,    -s,0,c};                                             //La matris ROTACIONAL del eje y (cada 3 entras salta a una nueva fila)
    else if (axis == 'z') M = {c,-s,0,    s,c,0,    0,0,1};                                             //La matris ROTACIONAL del eje z (lo mismo)
}

//En esta funcion multiplico la matris con el vector
void mult(const std::vector<double>& M, const std::vector<double>& v, std::vector<double>& r) {         //Recibe M, el vector y devuelve r (vector rotado)
    for (int i = 0; i < 3; ++i)                                                                         //i = filas, por eso es menor a 3 (inicia desde 0, ergo 3 filas)
        r[i] = M[i*3] * v[0] + M[i*3+1] * v[1] + M[i*3+2] * v[2];                                       //vector*elemnto fila, ergo sumo 1 mas cada elemento para aumentar la posicion
}

int main(int argc, char **argv) {                                                                       //Cantidad de datos plus la losta de esos datos
    if (argc != 7) {                                                                                    //Verifica el ingreso de SEIS datos, sino, termina el programa
        std::cout << "Uso: ./a.out vx vy vz thetax thetay thetaz\n";
        return 1;
    }

    std::vector<double> v = {std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])};               //Convertimos las tres primeras entradas en numeros para guardarlas en el vector 
    std::vector<double> r1(3), r2(3), Rm(9);                                                            //r1 y r2 guardan los vectores temporales y Rm la matris de tramaño 9 (3x3)

    rotational_matrix(std::stod(argv[4]), 'x', Rm);                                                     //Calcula la matris de rotacion de thetax en x, multiplica eso por el vector
    mult(Rm, v, r1);                                                                                    //Guarda el resultado en r1

    rotational_matrix(std::stod(argv[5]), 'y', Rm);                                                     //Lo mismo epro para theta y en y, multiplica por r1
    mult(Rm, r1, r2);                                                                                   //Lo guarda en r2

    rotational_matrix(std::stod(argv[6]), 'z', Rm);                                                     //Lo mismo pero para thetaz en z, lo multiplica con r2
    mult(Rm, r2, v);                                                                                    //Guarda el resultado en v

    for (double x : v) std::cout << x << " ";                                                           //Imprime los tres componentes del vector rotado (3x1)
    std::cout << "\n";      

    return 0;
}

