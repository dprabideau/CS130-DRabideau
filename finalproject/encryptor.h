#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function to generate random alphabetic characters
char randomAlphabet();

// Function to encrypt the given plaintext using the zigzag pattern
string encrypt(string plaintext);

// Function to decrypt the ciphertext back to plaintext
string decrypt(string ciphertext);

#endif // ENCRYPTOR_H
