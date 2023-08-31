#include <iostream>
#include <algorithm>
#include <string>

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
    cout << "Type a word: ";
    cin >> word;

    // Shuffle the word
    shuffledWord = shuffleWord(word);

    // Loop until player 2 guesses correctly
    while (true) {
        // Prompt player 2 to guess the word
        cout << "Find the word: " << shuffledWord << endl;
        cout << "Your guess: ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == word) {
            cout << shuffledWord << endl;
            cout << "Congratulations, you won!" << endl;
            break;
        } else {
            cout << "You lost!" << endl;
        }
        
        // Shuffle the word for the next round
        shuffledWord = shuffleWord(word);
    }

    return 0;
}