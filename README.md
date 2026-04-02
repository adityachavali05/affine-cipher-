## Brief Theory Behind the Cipher and the Hash

The Affine Cipher is a classical substitution cipher that uses a mathematical transformation to encrypt text. Each letter in the plaintext is first converted into a numerical value (A = 0, B = 1, ..., Z = 25). It is then transformed using the formula:

E(x) = (a · x + b) mod 26

where **a** and **b** are keys.

Decryption is performed using the formula:

D(x) = a⁻¹ · (x − b) mod 26

where **a⁻¹** is the modular inverse of **a**. For the cipher to work correctly, the value of **a** must be coprime with 26 so that the modular inverse exists.

In addition to encryption, a polynomial rolling hash function is used to generate a hash value for the ciphertext. The hash is computed using modular arithmetic and a constant base, producing a numeric representation of the ciphertext. This hash serves as a basic integrity check, ensuring that the ciphertext has not been altered during processing.

The program will prompt for the number of test cases. For each test case, enter the plaintext along with the keys **a** and **b**. The program will then perform encryption, compute the hash of the ciphertext, and decrypt it back to verify correctness.

## Examples Test Cases

**Example 1**
Plaintext: HELLO
Key: a = 5, b = 8
Ciphertext: RCLLA
Hash Output: (generated numeric value)
Decrypted Text: HELLO

**Example 2**
Plaintext: WORLD
Key: a = 7, b = 3
Ciphertext: ZRUOG
Hash Output: (generated numeric value)
Decrypted Text: WORLD

## Test Script Description

The test script demonstrates a complete pipeline where the input plaintext is first encrypted using the Affine Cipher. The resulting ciphertext is then passed to the hashing function to generate a hash value. Finally, the ciphertext is decrypted back to the original plaintext.

The program verifies whether the decrypted text matches the original input, ensuring correctness of the implementation and demonstrating a successful **encrypt → hash → decrypt** round-trip.
