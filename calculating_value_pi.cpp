#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n = 1000000; 
    double radius = 0.5; 
    double x, y; 
    int count = 0; 

    
    srand(time(NULL));

    
    for (int i = 0; i < n; i++) {
        x = (double)rand() / RAND_MAX * 2 - 1;
        y = (double)rand() / RAND_MAX * 2 - 1;

        
        if (sqrt(x*x + y*y) <= radius) {
            count++;
        }
    }

   
    double pi = 4 * (double)count / n;

   
    cout << "Estimated value of PI: " << pi << endl;

    return 0;
}
