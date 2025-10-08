#include <iostream>
#include <vector>

using namespace std;

// The game board, 1 through 9.
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Just draws the board as it is.
void drawBoard()
{
    cout << "\n--- Tic-Tac-Toe ---" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "     |     |     " << endl;
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
        board[i] = i + '1';
    }

    int currentPlayer = 1;
    int choice;
    char mark;
    int gameStatus;

    // Main game loop.
    do
    {
        drawBoard();

        // Figure out whose turn it is.
        mark = (currentPlayer % 2 == 1) ? 'X' : 'O';

        cout << "Player " << currentPlayer << " (" << mark << "), pick a spot: ";
        cin >> choice;

        // Make sure the spot is valid and not already taken.
        if (choice >= 1 && choice <= 9 && board[choice - 1] != 'X' && board[choice - 1] != 'O')
        {
            board[choice - 1] = mark; // Put the X or O on the board.
            currentPlayer++;          // Next player's turn.
        }
        else
        {
            cout << "Idiot. That spot is taken or doesn't exist. Try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        gameStatus = checkWin(); // See if the game is over.
    } while (gameStatus == -1);

    drawBoard(); // Show the final board.

    // Announce the winner or the draw.
    if (gameStatus == 1)
    {
        cout << "\nGame Over. Player " << (currentPlayer - 1) << " wins!" << endl;
    }
    else
    {
        cout << "\nIt's a draw. Boring." << endl;
    }
}