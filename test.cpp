#include <iostream>
#include "affine.h"
#include "hash.h"

using namespace std;

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

        // 🔥 Integrated pipeline
        string cipher = encrypt(text, a, b);
        long long hashVal = computeHash(cipher);
        string decrypted = decrypt(cipher, a, b);

        cout << "\n--- RESULT ---\n";
        cout << "Ciphertext: " << cipher << endl;
        cout << "Hash: " << hashVal << endl;
        cout << "Decrypted: " << decrypted << endl;

        if (decrypted == text)
            cout << "Status: SUCCESS\n";
        else
            cout << "Status: FAILED\n";
    }

    return 0;
}
