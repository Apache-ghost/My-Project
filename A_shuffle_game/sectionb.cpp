#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to shuffle the letters of a word
string shuffleWord(const string& word) {
    string shuffled = word;
    random_shuffle(shuffled.begin(), shuffled.end());
    return shuffled;
}

int main() {
    string word, shuffledWord, guess;

    // Get the word from player 1
    cout << "Player 1, please enter a word: ";
    cin >> word;

    // Clear the console and prompt player 2 to guess the word
    system("cls");
    cout << "Player 2, please guess the word." << endl;
    cout << "The word has " << word.length() << " letters." << endl;
    cout << "Each time you guess, I will show you the shuffled letters." << endl;
    cout << "Press enter to start." << endl;
    cin.ignore();
    cin.get();

    // Initialize game parameters
    int attempts = 5;
    int correctGuesses = 0;
    double score = 0;

    // Start the game loop
    while (true) {
        // Shuffle the word and prompt player 2 to guess
        shuffledWord = shuffleWord(word);
        cout << "Shuffled word: " << shuffledWord << endl;
        cout << "Your guess (" << attempts << " attempts left): ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == word) {
            cout << "Congratulations, you guessed the word!" << endl;
            correctGuesses++;
            score += attempts;
            attempts = 5;
            cout << "Do you want to play again? (y/n): ";
            char playAgain;
            cin >> playAgain;
            if (playAgain == 'n') {
                break;
            } else {
                system("cls");
                cout << "Player 2, please guess the word." << endl;
                cout << "The word has " << word.length() << " letters." << endl;
                cout << "Each time you guess, I will show you the shuffled letters." << endl;
                cout << "Press enter to start." << endl;
                cin.ignore();
                cin.get();
            }
        } else {
            cout << "Sorry, that is incorrect." << endl;
            attempts--;
            if (attempts == 0) {
                cout << "You have no more attempts." << endl;
                cout << "The correct word was: " << word << endl;
                cout << "Do you want to play again? (y/n): ";
                char playAgain;
                cin >> playAgain;
                if (playAgain == 'n') {
                    break;
                } else {
                    system("cls");
                    cout << "Player 2, please guess the word." << endl;
                    cout << "The word has " << word.length() << " letters." << endl;
                    cout << "Each time you guess, I will show you the shuffled letters." << endl;
                    cout << "Press enter to start." << endl;
                    cin.ignore();
                    cin.get();
                }
                attempts = 5;
            } else {
                cout << "You have " << attempts << " attempts left." << endl;
            }
        }
    }

    // Calculate and display average score
    if (correctGuesses > 0) {
        score /= correctGuesses;
    }
    cout << "Your average score is: " << score << endl;

    return 0;
}