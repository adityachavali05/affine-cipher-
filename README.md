Brief Theory Behind the Cipher and the Hash

The Affine Cipher is a classical substitution cipher that uses a mathematical transformation to encrypt text. Each letter in the plaintext is first converted into a numerical value (A = 0, B = 1, ..., Z = 25) and then transformed using the formula 
𝐸
(
𝑥
)
=
(
𝑎
⋅
𝑥
+
𝑏
)
m
o
d
 
 
26
E(x)=(a⋅x+b)mod26, where 
𝑎
a and 
𝑏
b are keys. Decryption is performed using the formula 
𝐷
(
𝑥
)
=
𝑎
−
1
⋅
(
𝑥
−
𝑏
)
m
o
d
 
 
26
D(x)=a
−1
⋅(x−b)mod26, where 
𝑎
−
1
a
−1
 is the modular inverse of 
𝑎
a. For the cipher to work correctly, the value of 
𝑎
a must be coprime with 26 so that the modular inverse exists.

In addition to encryption, a polynomial rolling hash function is used to generate a hash value for the ciphertext. The hash is computed using modular arithmetic and a constant base, producing a numeric representation of the ciphertext. This hash serves as a basic integrity check, ensuring that the ciphertext has not been altered during processing.

Instructions to Run the Code

To compile the program, use a C++ compiler such as g++. Run the following command:

g++ test.cpp -o crypto

After compilation, execute the program using:

./crypto

The program will prompt for the number of test cases. For each test case, enter the plaintext along with the keys 
𝑎
a and 
𝑏
b. The program will then perform encryption, compute the hash of the ciphertext, and decrypt it back to verify correctness.

Worked Examples

Example 1:
Plaintext: HELLO
Key: 
𝑎
=
5
a=5, 
𝑏
=
8
b=8
Ciphertext: RCLLA
Hash Output: (generated numeric value)
Decrypted Text: HELLO

Example 2:
Plaintext: WORLD
Key: 
𝑎
=
7
a=7, 
𝑏
=
3
b=3
Ciphertext: ZRUOG
Hash Output: (generated numeric value)
Decrypted Text: WORLD

Test Script Description

The test script demonstrates a complete pipeline where the input plaintext is first encrypted using the Affine Cipher. The resulting ciphertext is then passed to the hashing function to generate a hash value. Finally, the ciphertext is decrypted back to the original plaintext. The program verifies whether the decrypted text matches the original input, ensuring correctness of the implementation and demonstrating a successful encrypt → hash → decrypt round-trip.
