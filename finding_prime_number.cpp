#include <iostream>
using namespace std;

bool is_prime(int num) { // Function to check if a number is prime
   if (num <= 1) { // If the number is less than or equal to 1, it's not prime
      return false;
   }
   for (int i = 2; i < num; i++) { // Check if the number is divisible by any number between 2 and num-1
      if (num % i == 0) { // If it is, it's not prime
         return false;
      }
   }
   return true; // If the number is not divisible by any number between 2 and num-1, it's prime
}

int main() {
   int n, count = 0, num = 2; // Initialize variables

   cout << "Enter a number: ";
   cin >> n; // Ask the user for the number of prime numbers to find

   cout << "The first " << n << " prime numbers are: " << endl;

   while (count < n) { // Loop until n prime numbers are found
      if (is_prime(num)) { // Check if the current number is prime
         cout << num << " "; // If it is, print it
         count++; // Increment the count of prime numbers found
      }
      num++; // Increment the current number being tested
   }

   return 0; // Exit the program
}
