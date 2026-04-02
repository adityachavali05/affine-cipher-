#ifndef HASH_H
#define HASH_H

#include <string>
using namespace std;

// Simple polynomial rolling hash
long long computeHash(string s) {
    const int p = 31;
    const int mod = 1e9 + 9;

    long long hash = 0, power = 1;

    for (char c : s) {
        hash = (hash + (c * power) % mod) % mod;
        power = (power * p) % mod;
    }

    return hash;
}

#endif
