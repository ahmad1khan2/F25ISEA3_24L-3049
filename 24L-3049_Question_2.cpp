#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Grabs a random word from the 24L-3049_WordsList.txt file.
string getRandomWordFromFile()
{
    ifstream wordFile("24L-3049_WordsList.txt");
    vector<string> wordList;
    string tempWord;

    // If the file isn't there, we have a problem.
    if (!wordFile)
    {
        return "ERROR";
    }

    // Shove every word from the file into a list.
    while (wordFile >> tempWord)
    {
        wordList.push_back(tempWord);
    }

    // Make sure the file wasn't empty.
    if (wordList.empty())
    {
        return "EMPTY";
    }

    // Pick a random word from the list.
    srand(time(0));
    int randomIndex = rand() % wordList.size();
    return wordList[randomIndex];
}

void runQ2()
{
    string secretWord = getRandomWordFromFile();

    // Check for errors before starting the game.
    if (secretWord == "ERROR")
    {
        cout << "Error: '24L-3049_WordsList.txt' is missing. Make sure it's in the right folder." << endl;
        return;
    }
    if (secretWord == "EMPTY")
    {
        cout << "Error: '24L-3049_WordsList.txt' is empty. Put some words in it." << endl;
        return;
    }

    string hiddenWord(secretWord.length(), '_'); // This is the word with blanks.
    int mistakes = 0;
    const int MAX_MISTAKES = 7;

    cout << "--- Question 2: Hangman ---" << endl;

    // Main game loop. Ends when you win or run out of guesses.
    while (mistakes < MAX_MISTAKES && hiddenWord != secretWord)
    {
        cout << "\n================================" << endl;
        cout << "The word: " << hiddenWord << endl;
        cout << "Wrong guesses left: " << MAX_MISTAKES - mistakes << endl;

        char playerGuess;
        cout << "Guess a letter: ";
        cin >> playerGuess;

        // Check if the guessed letter is anywhere in the secret word.
        if (secretWord.find(playerGuess) != string::npos)
        {
            cout << "Yep, that's in there." << endl;
            // Fill in the letter wherever it appears.
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
            mistakes++; // One step closer to losing.
        }
    }

    // Check if the player won or lost.
    if (hiddenWord == secretWord)
    {
        cout << "\nNice! You got it. The word was: " << secretWord << endl;
    }
    else
    {
        cout << "\nOuch. You lost. The word was: " << secretWord << endl;
    }
}