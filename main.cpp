#include <iostream>
#include <vector>
#include <string>

#include "playingcards.h"
#include "blackjack.h"
#include "HighOrLow.h"
#include "slotmachine.h"
#include "Baccarat.h"
#include "profile.h"

using namespace std;

const int MAP_WIDTH = 49;  // Map width
const int MAP_HEIGHT = 20; // Map height

char playerSymbol = '@'; // '@' represents the character.

vector<string> gameMap = {
    "#################################################",
    "#                                               #",
    "#       BLACKJACK           HIGHER OR LOWER     #",
    "#                                               #",
    "#      $$$$$$$$$$$                              #",
    "#      $$$     $$$             <<<<^>>>>        #",
    "#      $$$$$$$$$$$             <<<<v>>>>        #",
    "#          |1|                    |2|           #",
    "#----------| |--------------------| |----       #",
    " E                                      |       #",
    " X                                      |       #",
    " I       @                              |       #",
    " T                                      |       #",
    "#----------| |--------------------| |----       #",
    "#          |3|                    |4|           #",
    "#      !!! !!! !!!               &&&&&          #",
    "#      !!! !!! !!!              &&&&&&&         #",
    "#      !!! !!! !!!               &&&&&          #",
    "#                                               #",
    "#         SLOTS                BACCARAT         #",
    "#                                               #",
    "#################################################"
};

// Function to display the map
void displayMap(double& coins) {

    cout << endl << "Current coins: :" << coins << endl;
    for (const auto& row : gameMap) {
        cout << row << endl;
    }
    cout << endl;
}

// Function to move player
void movePlayer(char direction, double& coins, bool& exit) {
    int playerX = -1;
    int playerY = -1;

    for (int i = 0; i < gameMap.size(); ++i) {
        for (int j = 0; j < gameMap[i].size(); ++j) {
            if (gameMap[i][j] == playerSymbol) {
                playerX = i;
                playerY = j;
                break;
            }
        }
        if (playerX != -1) break;
    }

    int newX = playerX;
    int newY = playerY;

    switch (direction) {
    case 'W': newX--; break;
    case 'S': newX++; break;
    case 'A': newY--; break;
    case 'D': newY++; break;
    default:
        cout << "Invalid move. Use W/A/S/D." << endl;
        return;
    }

    if (newX >= 0 && newX < MAP_HEIGHT && newY >= 0 && newY < MAP_WIDTH) {
        if (gameMap[newX][newY] == '1') {
            cout << "Welcome to Blackjack!" << endl;
            Blackjack(coins); // Call Blackjack game
        }
        else if (gameMap[newX][newY] == '2') {
            cout << "Welcome to Higher or Lower!" << endl;
            HighOrLow(coins); // Call HighOrLow game
        }
        else if (gameMap[newX][newY] == '3') {
            Slots(coins); // Call Slot Machine
        }
        else if (gameMap[newX][newY] == '4') {
            Baccarat(coins); // Call Baccarat
        }

        else if (gameMap[newX][newY] == 'E' || gameMap[newX][newY] == 'X' || gameMap[newX][newY] == 'I' || gameMap[newX][newY] == 'T') {
            exit = true;
            return;
        }
        else if (gameMap[newX][newY] == ' ') {
            gameMap[playerX][playerY] = ' '; // Clear the old position
            gameMap[newX][newY] = playerSymbol; // Set the new position
        }
        else if (gameMap[newX][newY] == '#') {
            cout << "Movement blocked by wall!" << endl;
        }
    }
    else {
        cout << "Movement blocked by wall or out of bounds!" << endl;
    }
}

void displayMainMenu() {
    cout << "\n------ Main Menu ------\n";
    cout << "1. Start Game\n";
    cout << "2. Exit Game\n";
    cout << "3. Profile\n"; // %#*
    cout << "Select an option: ";
}

void startGame(const string& username, double& coins) {

    displayMap(coins);
    bool exit = false;

    while (exit == false) {
        cout << "Move (W/A/S/D): ";
        char choice;
        cin >> choice;
        // ask player if exit. If exit, save coins and profile here

        movePlayer(choice, coins, exit);
        displayMap(coins);
    }
}

int main() {
    Game game;

    while (true) {
        displayMainMenu();  // Display main menu
        int option;
        cin >> option;

        switch (option) {
        case 1: {  // Start New Game
            cout << "Enter your username: ";
            string username;
            cin >> username;

            if (usernameExists(username)) {
                cout << "Username already exists. Please choose a different username.\n";
            }
            else {
                string filename = username + ".txt";
                game = Game(username);  // Initialize a new game with the username
                game.saveProfile(filename);  // Save the new game profile
                saveUsername(username); // Save username to profiles.txt
                cout << "New game started and saved to: " << filename << endl;
                game.enterGame();
                startGame(username, coins); // Start the game
                break;
            }
            break;
        }
        case 2: {  // Load Profile
            if (loadGameProfile(game)) {
                // Profile loaded and game started within the function
            }
            break;
        }
        case 3:  // Exit game
            cout << "Game exited. Goodbye!\n";
            return 0;  // Exit the program
        default:
            cout << "Invalid option, please try again.\n";
        }
    }

    return 0;
}
