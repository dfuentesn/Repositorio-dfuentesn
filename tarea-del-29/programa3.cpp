#include <iostream>
#include <string>
//le quite cmath porque no se usa para nada en este código

//defíno la función que calcula fibonacci con long 
long fibonacci(long n){
    //n1 es el primer valor de la cadena y n2 el segundo. En sum acumúlo la suma
    long n1 = 1, n2 = 2;
    long sum = 0;
    
    //aquí establezco el límite con tal de que no se exceda n
    while (n1 <= n){
       if (n1 % 2 != 0) {
            sum += n1;  
        }
    
    //calcúlo el segundo término para que entonces se vayan reemplazando por el siguiente término
    //ej: 2 pasa a ser 3, 3 pasa a ser el resulatdo de la suma (5), y así
    long next = n1 + n2;
    n1 = n2;
    n2 = next;
    }
    return sum;
}

//como siempre, se usa la función del profe para poner el ./a.out número en la línea de comando
int main(int argc, char** argv) {
    
    //transformo el argumento en un entero largo
    long n = std::stol(argv[1]);
    if (n < 2) {
        std::cerr << "Error: n debe ser >= 2" << "\n";
        return 1;  //1 es false pero para no booleanos, es decir, return false;
    }

    std::cout << fibonacci(n) << "\n";
    return 0;
}