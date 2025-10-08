#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>

using namespace std;

// Checks if a word is the same forwards and backwards.
bool isPalindrome(string text)
{
    string reversedText = text; // Copy the word.
    reverse(reversedText.begin(), reversedText.end()); // Flip the copy.

    // If the original and the flipped one match, it's a palindrome.
    if (text == reversedText)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void runQ1()
{
    string word;
    char key_press;

    cout << "--- Question 1: Palindrome Checker ---" << endl;
    cout << "Press 'Esc' to quit." << endl;

    // Loop forever until the user hits Esc.
    while (true)
    {
        cout << "\nEnter a word: ";
        cin >> word;

        // Check the word and print the result.
        if (isPalindrome(word))
        {
            cout << "'" << word << "' is a Palindrome." << endl;
        }
        else
        {
            cout << "'" << word << "' is Not a Palindrome." << endl;
        }

        cout << "\nPress Esc to quit, or any other key to go again..." << endl;
        key_press = _getch(); // Wait for a key press.

        // 27 is the ASCII code for the Escape key.
        if (key_press == 27)
        {
            break; // Get out of the loop.
        }
    }
}