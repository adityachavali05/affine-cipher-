#include <iostream>
#include <string>
using namespace std;

long long computeHash(string s) {
    const int p = 31;
    const int mod = 1e9 + 9;

    long long hash = 0;
    long long power = 1;

    for (char c : s) {
        hash = (hash + (c * power) % mod) % mod;
        power = (power * p) % mod;
    }

    return hash;
}
