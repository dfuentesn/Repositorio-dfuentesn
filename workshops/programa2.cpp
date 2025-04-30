#include <iostream>
#include <cmath>
#include <string>

//defíno la función isprime (inicia a contar primos desde 2, verifica que los demás sean divisibles por la raíz del número más 1 (precaución vista en clase))
bool isprime (long n){
    if (n <= 1){
        return false;      
    } //1 y menores no son primos

    if (n == 2){
        return true;        
    } //2 es el único par primo

    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++){
        if (n % ii == 0){
           return false;
        } //como le quitamos el bool flag, ya no es necesario un break                
    }
   return true;
}

long max_prime (long n){
    
    //incia en 0, el 0 indicará que el número NO tiene primos (como 1 o menores a 1)
    long max_prime = 0;
    
    if (isprime(n))        
        return n;

//si se cumple que el número es primo, entonces:
 for (long ii = 2; ii <= std::sqrt(n) + 1; ii ++){
    while (n % ii ==0){
        if (isprime(ii)){
            max_prime = ii;   
        } //actualiza max_prime por si ii es primo
        n /= ii;              
    } //reduce a n dividiendole por ii
 }

//acá defino que si el n que obtuvimos es primo y mayor que dos, es el mayor factor
 if (n > 2 && isprime(n)){
        max_prime = n;
    }
    return max_prime;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << "\n";
        return 1;            
    } //1 es como false pero para no booleanos
    
    long n = std::stol(argv[1]);   //acá convierto el argumento en un entero largo
    long result = max_prime(n);    //aquí calculo el mayor primo
    std::cout << "el factor primo más grande = " << result << "\n";   
    return 0;
}