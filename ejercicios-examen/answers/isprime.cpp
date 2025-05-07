#include <iostream>
#include <cmath>

int isprime(int m);
int largest_prime_factor(int m);

int main(void){
    std::cout << largest_prime_factor(9) << std::endl;
    std::cout << largest_prime_factor(97) << std::endl;
    std::cout << largest_prime_factor(100) << std::endl;
    std::cout << largest_prime_factor(12345) << std::endl;
    std::cout << largest_prime_factor(1000099) << std::endl;
    std::cout << largest_prime_factor(5412345) << std::endl;

    return 0;
}

int isprime(int m){
    if (m <= 1){
        std::cerr << "out of range: " << m << "\n";
        return false;
    }

    if (m == 2) return true;

    for (int ii = 2; ii <= std::sqrt(m) + 1; ii++ )
    if (m%ii == 0) return false;
    return true;
}

int largest_prime_factor(int m){
    int largestprime = 0;
    
    if (isprime(m))        
        return m;

    for (long ii = 2; ii <= std::sqrt(m) + 1; ii++){
         while (m % ii ==0){
             if (isprime(ii)){
             largestprime = ii;   
            } 
         m /= ii;              
        }     
    }

     if (m > 2 && isprime(m)){
        largestprime = m;
    }
    return largestprime;
}