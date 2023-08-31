#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

// Function to shuffle the letters of a word
string shuffleWord(const string& word) {
    string shuffled = word;
    random_shuffle(shuffled.begin(), shuffled.end());
    return shuffled;
}

int main() {
    // Load dictionary file into a vector
    vector<string> dictionary;
    string word;
    ifstream inFile("dictionary.txt");
    if (inFile.is_open()) {
        while (getline(inFile, word)) {
            dictionary.push_back(word);
        }
        inFile.close();
    } else {
        cout << "Failed to open dictionary file." << endl;
        return 1;
    }

    // Select a word at random from the dictionary
    srand(time(NULL));
    int index = rand() % dictionary.size();
    string selectedWord = dictionary[index];
    string shuffledWord, guess;

    // Clear the console and prompt player 2 to guess the word
    system("cls");
    cout << "Welcome to the guessing game." << endl;
    cout << "Player 2, please guess the word." << endl;
    cout << "The word has " << selectedWord.length() << " letters." << endl;
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
        shuffledWord = shuffleWord(selectedWord);
        cout << "Shuffled word: " << shuffledWord << endl;
        cout << "Your guess (" << attempts << " attempts left): ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == selectedWord) {
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
                // Select a new word at random from the dictionary
                index = rand() % dictionary.size();
                selectedWord = dictionary[index];
                cout << "Player 2, please guess the word." << endl;
                cout << "The word has " << selectedWord.length() << " letters." << endl;
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
                cout << "The correct word was: " << selectedWord << endl;
                cout << "Do you want to play again? (y/n): ";
                char playAgain;
                cin >> playAgain;
                if (playAgain == 'n') {
                    break;
                } else {
                    system("cls");
                    // Select a new word at random from the dictionary
                    index = rand() % dictionary.size();
                    selectedWord = dictionary[index];
                    cout << "Player 2, please guess the word." << endl;
                    cout << "The word has " << selectedWord.length() << " letters." << endl;
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