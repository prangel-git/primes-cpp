#include "primes.hpp"

#include <iostream>

int primes_generator::next()
{
    if (this->next_prime == 2)
    {
        this->next_prime = 3;
        return 2;
    } else if (this -> next_prime == 3) {
        this->next_prime = 5;
        return 3;
    } else {
        auto iter = this->next_to_cross.find(this->next_prime);
        while (iter != this->next_to_cross.end()) {
            this->cross_next(iter->first, iter->second);
            this->next_to_cross.erase(iter);
            this->increase_next_prime();
            iter = this->next_to_cross.find(this->next_prime);
        }
        
        integer current_prime = this->next_prime;
        integer prime_sq = current_prime * current_prime;
        this->next_to_cross[prime_sq] = 6 * current_prime;

        if (current_prime % 6 == 5) {
            this->cross_next(prime_sq - 4 * current_prime, 6 * current_prime);
        } else if (current_prime % 6 == 1) {
            this->cross_next(prime_sq - 2 * current_prime, 6 * current_prime);
        } 

        this->increase_next_prime();
        return current_prime;
    }
}

primes_generator::primes_generator() : next_prime(2),
                   step(2),
                   next_to_cross() {}

void primes_generator::update_step() {
    if (this->step == 2) {
        this->step = 4;
    } else {
        this->step = 2;
    }
}

void primes_generator::increase_next_prime() {
    this->next_prime += this->step;
    this->update_step();
}

void primes_generator::cross_next(integer start, integer jump) {
    integer next = start + jump;
    
    auto iter = this->next_to_cross.find(next);

    while (iter != this->next_to_cross.end()) {
        next += jump;
        iter = this->next_to_cross.find(next);
    }

    this->next_to_cross[next] = jump;   
}