## Affine Cipher in C++

The Affine Cipher is a classical encryption technique used in cryptography that applies a mathematical transformation to each letter in a message. It is a type of substitution cipher where each character in the plaintext is mapped to a corresponding character in the ciphertext using a linear function. This project implements the Affine Cipher in C++, supporting both encryption and decryption of text.

The working of the Affine Cipher is based on two mathematical formulas. For encryption, each letter is converted into its numerical equivalent (where A = 0, B = 1, ..., Z = 25), and then transformed using the formula ( E(x) = (a \cdot x + b) \mod 26 ). For decryption, the reverse transformation is applied using the formula ( D(x) = a^{-1} \cdot (x - b) \mod 26 ), where ( a^{-1} ) is the modular inverse of ( a ) under modulo 26. These operations ensure that the original message can be recovered from the encrypted text.

A key requirement of the Affine Cipher is that the value of ( a ) must be coprime with 26. This condition is necessary to ensure that a modular inverse exists for ( a ), which is required during the decryption process. If this condition is not satisfied, the cipher becomes invalid because the original message cannot be retrieved correctly.

The implemented program includes several important components. A function to compute the greatest common divisor (GCD) is used to verify whether the chosen value of ( a ) is valid. Another function calculates the modular inverse of ( a ), which is essential for decrypting the ciphertext. The encryption function processes each character of the input text, applies the affine transformation, and produces the encrypted output. Similarly, the decryption function reverses this transformation to recover the original plaintext.

This implementation is designed to handle both uppercase and lowercase letters while preserving non-alphabetic characters such as spaces and punctuation. This ensures that the structure and readability of the original text are maintained even after encryption and decryption.

Although the Affine Cipher demonstrates important concepts in modular arithmetic and classical cryptography, it is not considered secure by modern standards. It is vulnerable to various cryptanalysis techniques and should only be used for educational purposes. Nevertheless, it serves as a useful introduction to the mathematical foundations of encryption algorithms.
