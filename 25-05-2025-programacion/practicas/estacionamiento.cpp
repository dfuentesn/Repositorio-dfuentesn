#include <iostream>

int main(){
    long horas, minutos;
    double total;

    std::cout << "Ingrese las horas = " << "\n";
    std::cin >> horas;
    std::cout << "Ingrese los minutos" << "\n";
    std::cin >> minutos;

    if (minutos > 0){
        horas = horas++;  
    }

     total = horas * 3.50;

     std::cout << "El cliente debe pagar = " << total << "\n";
     
    return 0;
}