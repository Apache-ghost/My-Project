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

// Function to select a word from the dictionary based on the difficulty level
string selectWord(const vector<string>& dictionary, int difficulty) {
    vector<string> words;
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i].length() == difficulty) {
            words.push_back(dictionary[i]);
        }
    }
    if (words.size() == 0) {
        cout << "No words of length " << difficulty << " found in dictionary." << endl;
        return "";
    }
    srand(time(NULL));
    int index = rand() % words.size();
    return words[index];
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

    // Prompt player to choose difficulty level
    int difficulty;
    cout << "Welcome to the guessing game." << endl;
    cout << "Please choose a difficulty level (1-10): ";
    cin >> difficulty;

    // Select a word from the dictionary based on the difficulty level
    string selectedWord = selectWord(dictionary, difficulty);
    while (selectedWord == "") {
        cout << "Please choose a different difficulty level (1-10): ";
        cin >> difficulty;
        selectedWord = selectWord(dictionary, difficulty);
    }

    string shuffledWord, guess;

    // Clear the console and prompt player 2 to guess the word
    system("cls");
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
                // Prompt player to choose difficulty level
                cout << "Please choose a difficulty level (1-10): ";
                cin >> difficulty;
                // Select a new word from the dictionary based on the difficulty level
                selectedWord = selectWord(dictionary, difficulty);
                while (selectedWord == "") {
                    cout << "Please choose a different difficulty level (1-10): ";
                    cin >> difficulty;
                    selectedWord = selectWord(dictionary, difficulty);
                }
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
                    // Prompt player to choose difficulty level
                    cout << "Please choose a difficulty level (1-10): ";
                    cin >> difficulty;
                    // Select a new word from the dictionary based on the difficulty level
                    selectedWord = selectWord(dictionary, difficulty);
                    while (selectedWord == "") {
                        cout << "Please choose a different difficulty level (1-10): ";
                        cin >> difficulty;
                        selectedWord = selectWord(dictionary, difficulty);
                    }
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