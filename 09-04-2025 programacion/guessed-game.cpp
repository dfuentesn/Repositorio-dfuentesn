/*
 Juego de adivinar un numero
 Pregunta al usuario el numero
 Informar si lo adivino o no*/


#include <iostream>

int main(void) {
    const int NUM = 10;
    int guessed_number;
    std::cout << "Adivina un numero entre 1 y 100:\n";
    std::cin >> guessed_number;

    return 0;
}