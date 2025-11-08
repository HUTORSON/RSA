#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

constexpr int MAX16 = 65535;

// Sito Eratostenesa
vector<bool> sito_Eratostenesa() {
    vector<bool> is_prime(MAX16 + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX16; ++p) {
        if (is_prime[p]) {
            for (int q = p * p; q <= MAX16; q += p)
                is_prime[q] = false;
        }
    }
    return is_prime;
}

vector<int> all_primes16() {
    vector<bool> is_prime = sito_Eratostenesa();
    vector<int> primes;
    for (int i = 2; i <= MAX16; ++i)
        if (is_prime[i]) primes.push_back(i);
    return primes;
}

int random_prime(const vector<int>& primes) {
    static mt19937_64 rng(
        (unsigned)chrono::high_resolution_clock::now().time_since_epoch().count()
    );
    uniform_int_distribution<size_t> dist(0, primes.size() - 1);
    return primes[dist(rng)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes = all_primes16();
    cout << random_prime(primes) << '\n';
    return 0;
}
