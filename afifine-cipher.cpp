#include <iostream>
#include <string>
using namespace std;

# Computing gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

# Calculating Inverse of mod26
int modInverse(int a) {
    a = a % 26;
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1; 
}

// Encryption function
string encrypt(string text, int a, int b) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)(((a * (c - base) + b) % 26) + base);
        } else {
            result += c; // keep spaces/symbols unchanged
        }
    }
    return result;
}

// Decryption function
string decrypt(string cipher, int a, int b) {
    string result = "";
    int a_inv = modInverse(a);

    if (a_inv == -1) {
        return "Invalid key (no modular inverse exists)";
    }

    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int value = (a_inv * ((c - base - b + 26) % 26)) % 26;
            result += (char)(value + base);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key a (must be coprime with 26): ";
    cin >> a;

    if (gcd(a, 26) != 1) {
        cout << "Invalid 'a'. It must be coprime with 26.\n";
        return 0;
    }

    cout << "Enter key b: ";
    cin >> b;

    string encrypted = encrypt(text, a, b);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, a, b);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}