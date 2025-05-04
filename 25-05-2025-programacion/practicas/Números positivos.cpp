#include <iostream>

int main(){
    long num;
      std::cout << "Ingrese un número = ";
      std::cin >> num;
    
    if( num > 0){
        std::cout << "El número es positivo"  << "\n" << "EL número entero es = " << num << "\n";
    }

    else if (num == 0){
       std::cout << "El número es 0"  << "\n" << "EL número entero es = " << num << "\n"; 
    }

    else {
       std::cout << "El número es negativo" << "\n" << "EL número entero es = " << num << "\n";  
    }

    return 0;
}