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
    integer current_prime = test.next();
    integer sum_primes = 0;

    while (current_prime < upper_bound) {
        sum_primes += current_prime;
        current_prime = test.next();
    }

    std::cout << "The sum of primes under " << upper_bound << " equals " << sum_primes << " Last prime explored is " << current_prime << std::endl;
    
}
