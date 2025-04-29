#include <iostream>

//Operadores de entrada y salida
int main (){
    double n1, n2, n3, promedio;
    
      std::cout << "Ingrese la nota 1 =" << "\n";
      std::cin >> n1;
    
      std::cout << "Ingrese la nota 2 =" << "\n";
      std::cin >> n2;
    
      std::cout << "Ingrese la nota 3 =" << "\n";
      std::cin >> n3;

    promedio = (n1+n2+n3)/3;
    std::cout << "El promedio de notas es = " << promedio << "\n";

    return 0;
}
