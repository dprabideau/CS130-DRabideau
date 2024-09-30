#include <iostream>
#include <vector>
#include <unistd.h>

#ifdef _WIN32
    #include <conio.h>  // For Windows
    #define CLEAR_SCREEN() system("cls")  // Clear screen in Windows
#else
    #include <termios.h>
    #include <fcntl.h>
    #define CLEAR_SCREEN() system("clear")  // Clear screen in Linux/Mac
#endif

// Game constants
const int WIDTH = 30;
const int HEIGHT = 10;
const char PLAYER_CHAR = 'P';
const char GROUND_CHAR = '#';
const char EMPTY_CHAR = ' ';

// Player attributes
int playerX = 5;
int playerY = HEIGHT - 2;
int velocityY = 0;
bool isOnGround = false;

// Ground layout
std::vector<std::string> world(HEIGHT, std::string(WIDTH, EMPTY_CHAR));

void initWorld() {
    // Set the ground in the world (bottom row)
    for (int x = 0; x < WIDTH; x++) {
        world[HEIGHT - 1][x] = GROUND_CHAR;
    }
}

// Function to draw the world
void drawWorld() {
    CLEAR_SCREEN();  // Clear console

    // Place the player in the world
    world[playerY][playerX] = PLAYER_CHAR;

    // Draw the world
    for (int y = 0; y < HEIGHT; y++) {
        std::cout << world[y] << std::endl;
    }

    // Remove player from the world for next frame
    world[playerY][playerX] = EMPTY_CHAR;
}

// Function to handle jumping and falling
void updatePhysics() {
    if (!isOnGround) {
        playerY += velocityY;  // Apply vertical velocity (falling or jumping)
        velocityY++;           // Gravity effect (increase downward velocity)
    }

    // If the player reaches the ground, stop falling
    if (playerY >= HEIGHT - 2) {
        playerY = HEIGHT - 2;
        velocityY = 0;
        isOnGround = true;
    }
}

#ifdef _WIN32
// Windows: Check for keyboard hit (non-blocking input)
int kbhit() {
    return _kbhit();
}

// Windows: Get character input
char getInput() {
    return _getch();
}
#else
// Linux: Non-blocking key input function
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Linux: Get character input
char getInput() {
    return getchar();
}
#endif

// Handle player input for movement and jumping
void handleInput() {
    if (kbhit()) {
        char input = getInput();
        
        if (input == 'a' && playerX > 0) {  // Move left
            playerX--;
        }
        if (input == 'd' && playerX < WIDTH - 1) {  // Move right
            playerX++;
        }
        if (input == 'w' && isOnGround) {  // Jump if on ground
            velocityY = -3;
            isOnGround = false;
        }
    }
}

// Main game loop
int main() {
    initWorld();

    while (true) {
        drawWorld();
        handleInput();
        updatePhysics();

        // Small delay to slow down game loop
        usleep(16667);  // Sleep for 10 milliseconds
    }

    return 0;
}
