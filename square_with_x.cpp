#include <iostream>

using namespace std;

int main() {
   
    int size;
    cout << "Enter the size of the square: ";
    cin >> size;

  
    for (int i = 0; i < size; i++) {
        cout << "x ";
    }
    cout << endl;

    
    for (int i = 0; i < size - 2; i++) {
        cout << "x ";
        for (int j = 0; j < size - 2; j++) {
            cout << ". ";
        }
        cout << "x" << endl;
    }

    
    for (int i = 0; i < size; i++) {
        cout << "x ";
    }
    cout << endl;

    return 0;
}