#include<bits/stdc++.h> // Header file for input/output operations
using namespace std;

int main() {
    int n;
    cout << "Enter the numbers in the list : ";
    cin >> n; // Ask the user for the number of elements in the list
    int a[n]; // Create an array of size n to store the list of numbers
    cout << "Enter " << n << " of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Populate the array with the list of numbers entered by the user
    }
    double mean = 0.0; // Initialize the mean variable to 0
    int max = a[0], min = a[0]; // Initialize the maximum and minimum variables to the first element of the array
    for (int i = 0; i < n; i++) {
        mean += a[i]; // Add each element of the array to the mean variable
        if (a[i] > max) { // Check if the current element is greater than the maximum value so far
            max = a[i]; // If it is, set the maximum value to the current element
        }
        if (a[i] < min) { // Check if the current element is less than the minimum value so far
            min = a[i]; // If it is, set the minimum value to the current element
        }
    }
    mean /= n; // Divide the sum of the elements by the number of elements to get the mean value
    cout << "The  mean is : " << mean << endl; // Output the mean value
    cout << "The minimum is : " << min << endl; // Output the minimum value
    cout << "The maximum is : " << max << endl; // Output the maximum value
    return 0; // Exit the program
}
