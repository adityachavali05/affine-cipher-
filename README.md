## Deliverables (to be pushed to GitHub):

1. Source code for the assigned cipher (encryption + decryption)  
   The Affine Cipher is implemented in C++ with support for both encryption and decryption.

2. Source code for a hashing function   
   A Polynomial Rolling Hash function is implemented from scratch. This hash function is efficient and commonly used in string processing. It was chosen because it demonstrates modular arithmetic and avoids collisions reasonably well for small inputs.

3. A README.md that includes:

   - Brief theory behind the cipher and the hash  
     The Affine Cipher is a substitution cipher that encrypts characters using the formula:
     E(x) = (a * x + b) mod 26  
     Decryption is done using:
     D(x) = a⁻¹ * (x - b) mod 26  
     where a⁻¹ is the modular inverse of a. The value of 'a' must be coprime with 26.

     The hashing function used is a Polynomial Rolling Hash:
     Hash(s) = Σ (s[i] * p^i) mod m  
     where p is a constant base and m is a large prime.

   - Instructions to run the code  
     Compile using:
     g++ test.cpp -o test  
     Run using:
     ./test  

   - At least 2 worked examples  

     Example 1:  
     Plaintext: HELLO  
     Key: a = 5, b = 8  
     Ciphertext: RCLLA  
     Hash Output: (varies, e.g. 742... depending on run)  

     Example 2:  
     Plaintext: WORLD  
     Key: a = 7, b = 3  
     Ciphertext: ZRUOG  
     Hash Output: (computed value)  

4. A test script demonstrating encrypt → hash → decrypt round-trip  
   The test.cpp file demonstrates the full pipeline:
   plaintext → encryption → hashing → decryption → original plaintext recovery.

---

## Constraints:

- Language: C++  
- No cryptography libraries used  
- All implementations are from scratch  
- Hash function is unique and explained  

---

## Note

This project is for educational purposes only. The Affine Cipher is not secure for modern cryptographic use.
