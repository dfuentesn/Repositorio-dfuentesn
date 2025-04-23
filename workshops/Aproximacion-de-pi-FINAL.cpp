//Version FINAL del codigo para la aproximacion de pi con la formula de Bailey-Borwein-Plouffe

#include <iostream>
#include <cmath> 

//Vuelvo a definir M_PI en caso de que la libreria nos retorne un error de portabilidad
#ifndef M_PI 
const double M_PI = 3.14159265358979323846;
#endif

//Luego, creo la funcion pi_aprox con double para poder almacenar decimales (a diferencia de int) con varios digitos (a diferencia de float)
double pi_aprox(int n){
    double suma = 0.0;
    double denominador = 1.0;  //como 16**k inicia con k=0, tenemos 1.0

    for (int k = 0; k < n; k++) //En este caso uso solo < para retornar exactamente n terminos
    { 
        double termino = (4.0/(8*k+1)) - 
                         (2.0/(8*k+4)) - 
                         (1.0/(8*k+5)) - 
                         (1.0/(8*k+6));
        //En el termino separe el denominador de las restas para mayor presicion

        termino /= denominador;
        suma += termino; 
        denominador *= 16.0; //En cada nueva iteracion se multiplicara el denominador por 16, esto aumentara al denominador de la forma 16**k
    }
    return suma; //Aca retorno las sumatorias, eso nos dara la aproximacion de pi
}

int main(){
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    for (int n = 1; n <= 20; n++) //Aqui defino la variacion del loop entre 1 y 20
    {
    double aprox = pi_aprox(n); 
    double diff_rel = std::abs(1 - aprox /M_PI); //gracias a la linea anterior acortamos pi_aprox(n) con solo aprox

    std::cout << "n = ";
    if (n < 10) std::cout << " ";
    std::cout << n << ", π ≈ " << aprox
    << ", Diferencia relativa: " << diff_rel << std::endl;
     }
     return 0;
  }