#include <iostream>
using namespace std;

int main() {
   int num, factorial = 1; // Declares two variables: num to store user input, and factorial to store the result of the calculation
   cout << "Enter a number: "; // Ask the user to enter a number
   cin >> num; // Read user input and store it in num
   if (num < 0) { // If the number is negative
      cout << "Factorial cannot be found for negative numbers" << endl; // Displays an error message
   } else if (num == 0) { // if the number is zero
      cout << "Factorial of 0 is 1" << endl; // Shows that the factorial of 0 is 1
   } else { // if the number is positive

      for (int i = 1; i <= num; i++) { // Start a loop that runs until i reaches num
         factorial *= i; // Multiply each value from i to factorial
      }
      cout << "Factorial of " << num << " is " << factorial << endl; // Display the result
   }
   return 0; //Terminate the program by returning the value 0
}
