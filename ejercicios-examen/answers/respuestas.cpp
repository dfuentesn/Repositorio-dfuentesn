bool is_prime(long n) {
    for (long ii = 2; ii*ii <= n; ++ii)
        if (n%ii == 0) return false;

    return true;
}

void nth_twin_primes(long n) {
    long counter = 0;
    for(int ii = 2; ; ++ii) {
        if (is_prime(ii) and is_prime(ii+2)) {
            counter++;
            if (counter == n) {
                std::cout << "(" << ii << ", " << ii+2 << ")\n";
                break;
            }
        }
    }
}

//asjkjsidjqjdwpwd