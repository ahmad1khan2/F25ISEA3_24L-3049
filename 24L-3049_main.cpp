#include <iostream>
#include <cstdlib>
#include <string>

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
    system("cls"); 
}

int main()
{
    string choice = "0"; // Use a string for choice

    while (choice != "4") // Compare to the string "4"
    {
        cout << "===========================" << endl;
        cout << "    Assignment 3 Menu" << endl;
        cout << "===========================" << endl;
        cout << "1. Palindrome Thing" << endl;
        cout << "2. Hangman Game" << endl;
        cout << "3. Tic-Tac-Toe" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Pick one: ";

        getline(cin, choice); // Use getline to read the whole line

        if (choice == "1")
        {
            system("cls");
            runQ1();
            clearScreen();
        }
        else if (choice == "2")
        {
            system("cls");
            runQ2();
            clearScreen();
        }
        else if (choice == "3")
        {
            system("cls");
            runQ3();
            clearScreen();
        }
        else if (choice == "4")
        {
            cout << "Later." << endl;
        }
        else
        {
            // This 'else' block now catches everything else:
            // "5", "a", "hello", or just an empty Enter keypress.
            cout << "That's not an option. Pay attention. Plij" << endl;

            // We need a simple pause here.
            cout << "\nPress enter to try again...";
            cin.get(); // getline() consumed the newline, so cin.get() will wait.
            system("cls");
        }
    }

    return 0;
}