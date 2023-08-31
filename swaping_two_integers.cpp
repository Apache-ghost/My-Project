#include <iostream>

using namespace std;

int main() {
    int a, b;

   
    cout << "Enter the first number and second integer : ";
    cin >> a>>b;

   
    cout << "Original order: " << a << " " << b << endl;

   
    int temp = a;
    a = b;
    b = temp;

   
    cout << "Swapped order: " << a << " " << b << endl;

    return 0;
}
