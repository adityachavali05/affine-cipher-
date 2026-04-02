#include <iostream>
#include <string>
using namespace std;

// ---------- GCD ----------
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// ---------- Modular Inverse ----------
int modInverse(int a) {
    a %= 26;
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1;
}

// ---------- Encrypt ----------
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

// ---------- Decrypt ----------
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

// ---------- Hash Function ----------
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

// ---------- MAIN ----------
int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cin.ignore();

    while (t--) {
        string text;
        int a, b;

        cout << "\nEnter plaintext: ";
        getline(cin, text);

        cout << "Enter key a: ";
        cin >> a;

        if (gcd(a, 26) != 1) {
            cout << "Invalid key 'a'\n";
            return 0;
        }

        cout << "Enter key b: ";
        cin >> b;
        cin.ignore();

        // Step 1: Encrypt
        string cipher = encrypt(text, a, b);

        // Step 2: Hash ciphertext
        long long hash1 = computeHash(cipher);

        // Step 3: Decrypt
        string decrypted = decrypt(cipher, a, b);

        // Step 4: Re-hash (verification)
        long long hash2 = computeHash(cipher);

        // Output
        cout << "\n--- RESULT ---\n";
        cout << "Ciphertext: " << cipher << endl;
        cout << "Hash: " << hash1 << endl;
        cout << "Decrypted: " << decrypted << endl;

        if (hash1 == hash2)
            cout << "Integrity Check: PASSED\n";
        else
            cout << "Integrity Check: FAILED\n";
    }

    return 0;
}
