#ifndef AFFINE_H
#define AFFINE_H

#include <string>
#include <cctype>
using namespace std;

// GCD
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Modular inverse
int modInverse(int a) {
    a %= 26;
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1;
}

// Encrypt
string encrypt(string text, int a, int b) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)(((a * (c - base) + b) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Decrypt
string decrypt(string cipher, int a, int b) {
    string result = "";
    int a_inv = modInverse(a);

    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int val = (a_inv * ((c - base - b + 26) % 26)) % 26;
            result += (char)(val + base);
        } else {
            result += c;
        }
    }
    return result;
}

#endif
