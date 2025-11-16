#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
using namespace std;

/// The game board, 1 through 9.
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Just draws the board as it is.
void drawBoard()
{
    cout << "\n--- Tic-Tac-Toe ---" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << " _____|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << " _____|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "      |     |     " << endl;
}

// Checks for a winner or a draw.
// Returns 1 if someone won, 0 for a draw, -1 if the game's still on.
int checkWin()
{
    // Check all 8 ways to win.
    if (board[0] == board[1] && board[1] == board[2]) return 1;
    if (board[3] == board[4] && board[4] == board[5]) return 1;
    if (board[6] == board[7] && board[7] == board[8]) return 1;
    if (board[0] == board[3] && board[3] == board[6]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    if (board[0] == board[4] && board[4] == board[8]) return 1;
    if (board[2] == board[4] && board[4] == board[6]) return 1;

    // If nobody won, check if the board is full (a draw).
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return -1; // Found an empty spot, game's not over.
        }
    }

    return 0; // Board is full, it's a draw.
}


void runQ3()
{
    // Reset the board to numbers 1-9 for a new game.
    for (int i = 0; i < 9; i++)
    {
        // This converts the integer i to its char equivalent
        // '0' is 48 in ASCII. 0 + '1' (49) = 49 ('1'). 1 + '1' (49) = 50 ('2').
        board[i] = i + '1';
    }

    int player = 1; // This will just be 1 or 2
    int choice;
    char mark;
    int gameStatus = -1; // -1 means "in progress"

    // Main game loop.
    do
    {
        system("cls");
        drawBoard();

        // Figure out whose turn it is.
        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        cout << "Player " << player << " (" << mark << "), pick a spot: ";

        string inputLine;
        getline(cin, inputLine); // Read input as a string

        try
        {
            choice = stoi(inputLine); // Try to convert to a number
        }
        catch (const std::exception&)
        {
            choice = 0; // Set to invalid choice if conversion fails
        }

        // Make sure the spot is valid and not already taken.
        // (choice - 1) is the array index.
        if (choice >= 1 && choice <= 9 && board[choice - 1] != 'X' && board[choice - 1] != 'O')
        {
            board[choice - 1] = mark; // Put the X or O on the board.

            gameStatus = checkWin(); // Check for a win or draw

            // Switch to the other player *only if* the game isn't over.
            if (gameStatus == -1)
            {
                // Switch player
                if (player == 1)
                {
                    player = 2;
                }
                else
                {
                    player = 1;
                } 
            }
        }
        else
        {
            // Invalid move. We don't switch players.
            cout << "Idiot. That spot is taken or doesn't exist. Try again." << endl;
            cout << "Press any key to continue to try again." << endl;
            char key_press = _getch();
        }

    } while (gameStatus == -1); // Keep looping as long as the game is in progress


    system("cls");
    drawBoard(); // Show the final board.

    // Announce the winner or the draw.
    if (gameStatus == 1)
    {
        // 'player' never got switched on the final winning move,
        // so 'player' is still the winner.
        cout << "\nGame Over. Player " << player << " wins!" << endl;
    }
    else // gameStatus must be 0
    {
        cout << "\nIt's a draw. Boring." << endl;
    }
}