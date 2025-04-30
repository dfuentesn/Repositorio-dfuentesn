#include <iostream>
#include <cmath>
#include <string>

//establecemos la funcion isprime para definir que es un primo
bool isprime(long n){

    //acá establecemos un límite inferior, todo n igual o menor a 1 no será ni tendra primmos, por ende su suma será 0 
    if (n <= 1){
        return false;
    } 

    //acá decimos que 2 es el único par primo porque retorna como verdadero
    bool flag = true;
    if (n == 2){
        return true;
    } 

    //iteramos desde 2 y verificamos que todos los demás n sean divisibles por la raíz del número más 1 (el 1 es un precaución, como visto en clase)
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++){
        if (n % ii == 0){
            flag = false;
            break;
        } 
    }
    return flag;
}

int main(int argc, char **argv){
    
    //convierte el argumento a un entero (como visto en clase), le pongo long para que no falle con numeros grandes
    long n = std::stoi(argv[1]);

    //inicia la variable suma en 0 para acumular los valores
    long sum = 0;

    //inicia el bucle desde 2 hasta n; incrementa
    for (long ii = 2; ii <= n; ++ii){
        //verifica que se cumpla el ser primo con la función:
        if (isprime(ii)){
            sum += ii;
        }
    }

    //imprime el valor final de la suma
    std::cout << "La suma es = " << sum << "\n";
    return 0;
 }


//NOTA: Para que funcione (ya que tiene que leer los parámetros desde la línea de comando), se debe escribir ./a.out y el número
//Ejemplo: ./a.out 5. Debería retornar "La suma es= 10"