#include <iostream>

//Operadores de entrada y salida
int main (){
    double b, h, area_triangulo; 

    std::cout << "Ingrese un valor para b =" << "\n";
    std::cin >> b;
    std::cout << "Ingrese un valor para h =" << "\n";
    std::cin >> h;

    area_triangulo = (b*h)/2;
    std::cout << "Area del triangulo = " << area_triangulo << "\n";

    return 0;
}
