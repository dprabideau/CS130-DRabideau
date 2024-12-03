#include "encryptor.h"

// Function to generate random alphabetic characters
char randomAlphabet() {
    int randomChar = rand() % 52; // Generate a random number between 0-51
    if (randomChar < 26) {
        return 'a' + randomChar; // Return a lowercase letter
    } else {
        return 'A' + (randomChar - 26); // Return an uppercase letter
    }
}

// Function to encrypt the given plaintext using the zigzag pattern
string encrypt(string plaintext) {
    srand(time(0)); // Seed the random number generator with the current time

    // Calculate the minimum grid size to fit the plaintext
    size_t gridSize = ceil(sqrt(plaintext.length()));
    size_t gridCount = gridSize * gridSize; // Total slots in the grid

    // Fill the grid with plaintext characters
    vector<char> grid;
    for (size_t i = 0; i < plaintext.size(); i++) {
        grid.push_back(plaintext[i]);
    }

    // Fill the remaining slots with random characters
    while (grid.size() < gridCount) {
        grid.push_back(randomAlphabet());
    }

    // Generate the zigzag pattern for traversal
    vector<size_t> curve;
    bool direction = true; // True for left-to-right, false for right-to-left
    for (size_t row = 0; row < gridSize; row++) {
        if (direction) {
            for (size_t col = 0; col < gridSize; col++) {
                curve.push_back(row * gridSize + col);
            }
        } else {
            for (size_t col = gridSize - 1; col < gridSize; col--) {
                curve.push_back(row * gridSize + col);
            }
        }
        direction = !direction; // Flip direction for the next row
    }

    // Construct the ciphertext by reading the grid in zigzag order
    string ciphertext = "";
    for (size_t i = 0; i < curve.size(); i++) {
        ciphertext += grid[curve[i]];
    }

    // Return the ciphertext along with metadata for grid size and padding count
    size_t randomCharsCount = gridCount - plaintext.size();
    return to_string(gridSize) + "," + to_string(randomCharsCount) + "," + ciphertext;
}

// Function to decrypt the ciphertext back to plaintext
string decrypt(string ciphertext) {
    // Parse the grid size and padding count from the ciphertext
    size_t firstComma = ciphertext.find(',');
    if (firstComma == string::npos) {
        cout << "Error: Invalid ciphertext format" << endl;
        return "";
    }

    size_t secondComma = ciphertext.find(',', firstComma + 1);
    if (secondComma == string::npos) {
        cout << "Error: Invalid ciphertext format" << endl;
        return "";
    }

    size_t gridSize = stoi(ciphertext.substr(0, firstComma));
    size_t randomCharsCount = stoi(ciphertext.substr(firstComma + 1, secondComma - firstComma - 1));
    string reorderedText = ciphertext.substr(secondComma + 1);

    // Validate ciphertext length
    if (reorderedText.size() != gridSize * gridSize) {
        cout << "Error: Ciphertext length does not match grid size" << endl;
        return "";
    }

    // Reconstruct the zigzag pattern
    vector<size_t> curve;
    bool direction = true;
    for (size_t row = 0; row < gridSize; row++) {
        if (direction) {
            for (size_t col = 0; col < gridSize; col++) {
                curve.push_back(row * gridSize + col);
            }
        } else {
            for (size_t col = gridSize - 1; col < gridSize; col--) {
                curve.push_back(row * gridSize + col);
            }
        }
        direction = !direction;
    }

    // Reorder the text based on the zigzag pattern
    vector<char> grid(gridSize * gridSize, ' ');
    for (size_t i = 0; i < curve.size(); i++) {
        grid[curve[i]] = reorderedText[i];
    }

    // Extract the original plaintext, excluding padding
    string plaintext = "";
    for (size_t i = 0; i < grid.size() - randomCharsCount; i++) {
        plaintext += grid[i];
    }

    return plaintext;
}