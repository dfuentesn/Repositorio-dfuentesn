#include <iostream>

int main(){
    long num;
      std::cout << "Ingrese un numero" << "\n";
      std::cin >> num;
    
    if (num == 0){
      std::cout << "El número no es par" << "\n";
    }

    else if (num % 2 == 0){
      std::cout << "El número es par" << "\n";
    }
    
    else {
      std::cout << "El número no es par" << "\n";
    }
     
    return 0;
}