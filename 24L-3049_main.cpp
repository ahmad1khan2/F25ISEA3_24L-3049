#include <iostream>
#include <cstdlib>

using namespace std;

// Tell this file about the functions in the other files.
void runQ1();
void runQ2();
void runQ3();

// Clears the screen.
void clearScreen()
{
    cout << "\nPress enter to go back to the menu...";
    cin.ignore();
    cin.get();
    system("cls"); // Use "clear" on Mac/Linux
}

int main()
{
    int choice = 0;

    while (choice != 4)
    {
        cout << "===========================" << endl;
        cout << "   Assignment 3 Menu" << endl;
        cout << "===========================" << endl;
        cout << "1. Palindrome Thing" << endl;
        cout << "2. Hangman Game" << endl;
        cout << "3. Tic-Tac-Toe" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Pick one: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            runQ1();
            clearScreen();
        }
        else if (choice == 2)
        {
            system("cls");
            runQ2();
            clearScreen();
        }
        else if (choice == 3)
        {
            system("cls");
            runQ3();
            clearScreen();
        }
        else if (choice == 4)
        {
            cout << "Later." << endl;
        }
        else
        {
            cout << "That's not an option. Pay attention." << endl;
            clearScreen();
        }
    }

    return 0;
}