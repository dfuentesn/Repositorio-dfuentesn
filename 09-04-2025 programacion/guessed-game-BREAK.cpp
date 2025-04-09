/*
 Juego de adivinar un numero
 Pregunta al usuario el numero
 Informar si lo adivino o no*/


#include <iostream>

int main(void) {
    const int NUM = 10;
    int guessed_number;

    for (;;) {
    std::cout << "Adivina un numero entre 1 y 100:\n";
    std::cin >> guessed_number;

    if (guessed_number == NUM){
        std::cout <<"GANASTE :D!!!!\n";
        break;
    } else if (guessed_number > NUM) {
        std::cout <<"Te pasaste :(. Vuelve a intentar\n";
    }  else { // es menor
            std::cout <<"Te falta. Vuele a intentar :)\n"; 
    }
    }

    return 0;
}