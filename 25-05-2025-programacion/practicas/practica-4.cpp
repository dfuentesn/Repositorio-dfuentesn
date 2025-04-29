#include <iostream>

//Operadores de incrementos
int main (){
    int k, n, edad;

    k = 7;
    n = 2;
    edad = k;

    std::cout << "La edad es =" << edad << "\n";

    k += n; //k ahora es igual a k con el valor de n
    std::cout << "k =" << k << "\n";

    return 0;
}
