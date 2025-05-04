#include <iostream>
#include <cmath>

int main(){
    long num, k = 0;
    std::cout << "ingrese un numero = ";
    std::cin >> num;

    for (long i = 1; i <= num; i++){
        if (num % i == 0){
            k++;
        }
    }

    if (k == 2){
        std::cout << "El número es primo" << "\n";
    }

    else{
        std::cout << "El número no es primo" << "\n";
    }

    return 0;
}