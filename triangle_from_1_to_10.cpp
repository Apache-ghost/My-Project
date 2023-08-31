#include <iostream>

using namespace std;

int main() {
    const int k = 10; 
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}