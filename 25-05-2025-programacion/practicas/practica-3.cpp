#include <iostream>

//Operadores de incrementos
int main (){
    int k = 19;
    int resultado_k; //incrementa la variable k
    int decrecion_k;

    resultado_k = ++k; //incrementando de 1 en 1
    decrecion_k = --k;  //disminuye de 1 a 1

    std::cout << "ahora la variable aumentada es =" << resultado_k << "\n";
    std::cout << "ahora la variable decrecida es =" << decrecion_k << "\n";
 
    return 0;
}
