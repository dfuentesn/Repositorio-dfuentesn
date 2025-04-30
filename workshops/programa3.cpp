#include <iostream>
#include <cmath>
#include <string>

//defino la funcion que calcula fibonacci con long 
long fibonacci(long n){
    //n1 es el primer valor de la cadena y n2 el segundo. En sum acumulo la suma
    long n1 = 1, n2 = 2;
    long sum = 0;
    
    //aqui establesco el limite con tal de que no se exceda n
    while (n1 <= n){
       if (n1 % 2 != 0) {
            sum += n1;  
        }
    
    //calculo el segundo termino para que entonces se vayan reemplazando por el siguiente termino
    //ej: 2 pasa a ser 3, 3 pasa a ser el resulatdo de la suma (5), y asi
    long next = n1 + n2;
    n1 = n2;
    n2 = next;
    }
    return sum;
}

//como siempre, se usa la funcion del profe para poner el ./a.out numero en la linea de comando
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Use: " << argv[0] << " <n> (n >= 2)" << "\n";
        return 1;
    }
    
    //transformo el argumento en un entero largo
    long n = std::stol(argv[1]);
    if (n < 2) {
        std::cerr << "Error: n debe ser >= 2" << "\n";
        return 1;  //1 es false pero para no booleanos (sin la funcion bool)
    }

    std::cout << fibonacci(n) << "\n";
    return 0;
}