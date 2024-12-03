/*
Author: Dayne Rabideau
Last Modified Date: 12-02-2024
Description: 
    Original Idea: 
        Using a Lissajou curve as an encryption method. Plaintext would be 
        placed in a grid and then converted to ciphertext by following the Lissajous curve.
    Outcome: 
        Instead of a mapping to a Lissajous curve, the text is read left-to-right or 
        right-to-left for each row in a zig-zag pattern to mimic a Lissajous curve with a 
        ratio 1:n where n is an integer.
*/

#include "encryptor.h"

int main() {
    int choice;
    while (true) {
        // Present user with menu options
        cout << "Choose an option:\n1. Encrypt\n2. Decrypt\n0. Exit\nYour choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline from input

        if (choice == 1) {
            // Encryption mode
            string plaintext;
            cout << "Enter the plaintext to encrypt: ";
            getline(cin, plaintext);

            string ciphertext = encrypt(plaintext);
            cout << "Encrypted ciphertext: " << ciphertext << endl;
        } else if (choice == 2) {
            // Decryption mode
            string ciphertext;
            cout << "Enter the ciphertext to decrypt: ";
            getline(cin, ciphertext);

            string plaintext = decrypt(ciphertext);
            cout << "Decrypted plaintext: " << plaintext << endl;
        } else if (choice == 0) {
            // Exit the program
            cout << "Exiting the program." << endl;
            break;
        } else {
            // Handle invalid input
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}