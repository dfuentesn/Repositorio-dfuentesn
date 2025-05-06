#include <iostream>
#include <cmath>
#include <fstream>

bool is_prime(long n){
    for (long ii = 2; ii * ii <= n; ii++)
    if (n % ii == 0) return false;
    return true;
}

void nth_twin_primes(int count){
    long counter = 0;
    for (long ii; ; ++ii){
        if (is_prime(ii) && is_prime(ii+2)){
            counter++;
            if(counter == count){
                std::cout << "(" << ii << "," << ii+2 << ")\n";
                break;
            }
        }
    }
}

void print_twin_primes_norms(int N){
    long count = 0;
    long p = 2;
    std::ofstream file("twin_primes.txt");

    std::cout << "n\tp\tp+2\tnorma\n";

    while (count < N) {
        if (is_prime(p) && is_prime(p + 2)) {
            ++count;
            double norma = std::sqrt(p * p + (p + 2) * (p + 2));
            file << count << "\t" 
                      << p << "\t" 
                      << (p + 2) << "\t" 
                      << p << "\n";
        }
        ++p;
    }
    file.close();
}

int main(){
    int N = 100;
    print_twin_primes_norms(N);
    return 0;
}
