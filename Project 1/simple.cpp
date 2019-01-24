//Yueyi Gao
//Project1-simple.cpp
//I used google and textbook to find how to initiate dynamic array.
//The code refer to factorial.cpp and standard deviation.cpp

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   cout << "Enter the numbers of elements (less than 10): ";
   int n;
   int factorial = 1;
   cin >> n;
	//If users don't enter the correct number.
   while (n > 10 || n < 0) {
      cout << "Please enter the number between 0 to 10: ";
      cin >> n;
   }
	//Factorial value based on how many positive numbers users want to input.
   for (int i = 1; i <= n; ++i) {
      factorial *= i; //factorial = factorial * i.
   }
   cout << "Factorial of " << n << " = " << factorial;
   cout << endl;

	//Initiate the dynamic array for the input numbers.
   float* data = new float[n];
		
   cout << "Enter elements: ";
   for (int i = 0; i < n; ++i) {
      cin >> data[i];
   }

   float sum = 0.0, mean, standardDeviation = 0.0;
   for (int i = 0; i < n; ++i)
   {
      sum += data[i];
   }

   mean = sum / n;

   for (int i = 0; i < n; ++i) {
      standardDeviation += pow(data[i] - mean, 2);
   }
   cout << endl << "Standard Deviation = " << sqrt(standardDeviation / n);
   return 0;

}



