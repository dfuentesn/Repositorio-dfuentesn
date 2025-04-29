#include <iostream>
#include <cmath>
#include <string>

//establecemos la funcion isprime para definit que es un primo
bool isprime(long n){

    // aca establecemos un limite inferior, todo n igual o menor a 1 no sera ni tendra primmos por ende su suma sera 0 
    if (n <= 1){
        return false;
    } 

    // aca decimos que 2 es el unico par primo porque retorna como verdadero
    bool flag = true;
    if (n == 2){
        return true;
    } 

    //iteramos desde 2 y verificamos que todos los demas n sean divisibles por la raiz del numero mas 1 (el 1 es un precaucion, como vizto en clase)
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++){
        if (n % ii == 0){
            flag = false;
            break;
        } 
    }
    return flag;
}

int main(int argc, char **argv){
    
    //verifica que el numero de argumentos sea el nombre y el argumento (osea 2), si no se cumple, muestra un mensaje de error
    if (argc != 2){
        std::cerr << "Uso: " << argv[0] << " <numero>" << "\n";
        return 1; //aca el 1 actua como false solo que sin ser booleano (no hay funcion bool)
    }
    
    //convierte el argumento a un entero (como visto en clase)
    int n = std::stoi(argv[1]);

    //inicia la variable suma en 0 para acumular los valores
    long sum = 0;

    //inicia el bucle desde 2 hasta n, incrementa
    for (long ii = 2; ii <= n; ++ii){
        //verifica que se cumpla el ser primo con la funcion
        if (isprime(ii)){
            sum += ii;
        }
    }

    //imprime el valor final de la suma
    std::cout << "La suma es = " << sum << "\n";
    return 0;
 }


//NOTA: Para que funcione (ya que tiene que leer los parametros desde la linea de comando), se debe escribir ./a.out y el numero
//Ejemplo: ./a.out 5, deberia retornar "La suma es= 10"