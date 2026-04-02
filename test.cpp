#include <iostream>
#include <string>
using namespace std;

// Include functions manually (since no headers used)
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int modInverse(int a) {
    a %= 26;
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1;
}

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

// Hash function
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

int main() {
    string text = "HELLO";
    int a = 5, b = 8;

    if (gcd(a, 26) != 1) {
        cout << "Invalid key\n";
        return 0;
    }

    string cipher = encrypt(text, a, b);
    long long hash = computeHash(cipher);
    string decrypted = decrypt(cipher, a, b);

    cout << "Plaintext: " << text << endl;
    cout << "Encrypted: " << cipher << endl;
    cout << "Hash: " << hash << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
