#include <iostream>
#include <cmath>

bool isprime(long n)
{

    if (n <= 1)
    {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    bool flag = true;
    if (n == 2)
    {
        return true;
    }

    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++)
    {
        if (n % ii == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main(void)
{
    long n;
    std::cout << "n=";
    std::cin >> n;

    long sum = 0;
    for (long ii = 2; ii <= n; ++ii)
    {
        if (isprime(ii) == true)
        {
            sum += ii;
        }
    }
    std::cout << "La suma es = " << sum << "\n";
    return 0;
}
