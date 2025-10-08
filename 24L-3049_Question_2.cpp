#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Grabs a random word from the 24L-3049_WordsList.txt file.
string getRandomWordFromFile()
{
    ifstream wordFile("24L-3049_WordsList.txt");
    vector<string> wordList;
    string tempWord;

    if (!wordFile) { return "ERROR"; }

    while (wordFile >> tempWord)
    {
        wordList.push_back(tempWord);
    }

    if (wordList.empty()) { return "EMPTY"; }

    srand(time(0));
    int randomIndex = rand() % wordList.size();
    return wordList[randomIndex];
}

void runQ2()
{
    string secretWord = getRandomWordFromFile();

    if (secretWord == "ERROR")
    {
        cout << "Error: '24L-3049_WordsList.txt' is missing." << endl;
        return;
    }
    if (secretWord == "EMPTY")
    {
        cout << "Error: '24L-3049_WordsList.txt' is empty." << endl;
        return;
    }

    string hiddenWord(secretWord.length(), '_');
    int mistakes = 0;
    const int MAX_MISTAKES = 7;
    string allGuessedLetters = "";

    cout << "--- Question 2: Hangman ---" << endl;

    while (mistakes < MAX_MISTAKES && hiddenWord != secretWord)
    {
        char key_press;
        cout << "\n================================" << endl;
        cout << "The word: " << hiddenWord << endl;
        cout << "Wrong guesses left: " << MAX_MISTAKES - mistakes << endl;
        cout << "You've guessed: " << allGuessedLetters << endl;

        string userInput;
        cout << "Guess a letter: ";
        cin >> userInput; // Read whatever the user types.

        char playerGuess = userInput[0]; // **FIX**: We only care about the first letter.

        if (allGuessedLetters.find(playerGuess) != string::npos)
        {
            cout << "You already guessed that. Try again." << endl;
            cout << "Press any key to continue to your next attempt." << endl;
            key_press = _getch();

            system("cls");
            continue;
        }

        allGuessedLetters += playerGuess;

        if (secretWord.find(playerGuess) != string::npos)
        {
            cout << "Yep, that's in there." << endl;
            for (int i = 0; i < secretWord.length(); i++)
            {
                if (secretWord[i] == playerGuess)
                {
                    hiddenWord[i] = playerGuess;
                }
            }
        }
        else
        {
            cout << "Nope, '" << playerGuess << "' is wrong." << endl;
            mistakes++;
        }
        cout << "Press any key to continue to your next attempt." << endl;
        key_press = _getch();

        system("cls");
    }

    if (hiddenWord == secretWord)
    {
        cout << "\nNice! You got it. The word was: " << secretWord << endl;
    }
    else
    {
        cout << "\nOuch. You lost. The word was: " << secretWord << endl;
    }
}