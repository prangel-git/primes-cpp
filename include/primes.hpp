#include <unordered_map>

using integer = unsigned long long;
using container = std::unordered_map<integer, integer>;

class primes_generator
{
private:
    int next_prime;
    int step;
    container next_to_cross;

    void update_step();

    void increase_next_prime();

    void cross_next(integer start, integer jump);
public:
    primes_generator();

    int next();
};
