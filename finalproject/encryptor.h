#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//function to generate random alphabetic characters
char randomAlphabet();

//function to encrypt the plaintext using zigzag pattern
string encrypt(string plaintext);

//function to decrypt the ciphertext back to plaintext
string decrypt(string ciphertext);

#endif
