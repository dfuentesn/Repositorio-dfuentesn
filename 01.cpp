#include <iostream>
#include <string>

int main(void)
{
    std::string name;
    std::cout << "Hola, what's your name\n ";
    //std::cin >> name;  //lee hasta el primer espacio
    std::getline(std::cin, name);  
    //variable name, no input. Getline usa dos funciones
    std::cout << "Hello, " + name + "!\n" ;

    return 0;
}
