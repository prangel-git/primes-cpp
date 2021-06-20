#include <iostream>

#include <primes.hpp>

int main(int, char **)
{
    std::cout << "Hello, world!\n";

    primes_generator test;

    // Show the first 10001 primes
    for (size_t i = 0; i < 10001; i++)
    {
        std::cout << test.next() << " ";   
    }
    std::cout << std::endl;


    // Sum primes under upper_bound
    integer upper_bound = 2000000;
    integer expected_result = 142913828922;

    integer sum_primes = 0;
    integer current_prime = test.next();

    while (current_prime < upper_bound) {
        sum_primes += current_prime;
        current_prime = test.next();
    }

    
    if(sum_primes != expected_result) {
        std::cout << "The expected result is " << expected_result << " but the calculation gives " << sum_primes << std::endl;
    }

    std::cout << "The sum of primes under " << upper_bound << " equals " << sum_primes << " Last prime explored is " << current_prime << std::endl;
    
}
