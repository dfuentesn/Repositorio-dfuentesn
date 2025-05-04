//Respuesta del profe
#include <iostream>

bool is_prime(long n) {
    for (long ii = 2; ii * ii <= n; ++ii){
       if (n % ii == 0){
            return false;
        } 
    }
     return true;
}


/*
Qué hace:
Objetivo: Determina si un número n es primo.

Paso 1: Itera desde ii = 2 hasta ii * ii <= n (es decir, hasta la raíz cuadrada de n).

Paso 2: Si n es divisible entre ii (n % ii == 0), retorna false (no es primo).

Paso 3: Si termina el bucle sin encontrar divisores, retorna true (es primo).

Ejemplo:
Para n = 5:

Verifica 5 % 2 (no es 0), luego ii se vuelve 3 y 3*3 > 5. Retorna true.

Para n = 4:

Verifica 4 % 2 == 0. Retorna false.
*/

void nth_twin_primes(long n) {
    long k = 0;
    for(int ii = 2; ; ++ii) {
        if (is_prime(ii) and is_prime(ii+2)) {
            k++;
            if (k == n) {
                std::cout << "(" << ii << ", " << ii + 2 << ")\n";
                break;
            }
        }
    }
}

/*
Qué hace:
Objetivo: Encuentra el n-ésimo par de primos gemelos y lo imprime.

Paso 1: Inicializa un contador counter en 0.

Paso 2: Itera desde ii = 2 hasta encontrar el n-ésimo par.

Para cada ii:

Verifica si ii e ii + 2 son primos (usando is_prime).

Si ambos son primos, incrementa counter.

Si counter == n, imprime el par (ii, ii + 2) y termina el bucle (break).

Ejemplo:
Para nth_twin_primes(1):

ii = 3: is_prime(3) y is_prime(5) son true.
counter se vuelve 1. Imprime (3, 5) y termina.

Para nth_twin_primes(2):

ii = 5: is_prime(5) y is_prime(7) son true.
counter se vuelve 2. Imprime (5, 7) y termina.
*/