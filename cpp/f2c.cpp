 // function fahrToCel to perform conversion
#include <iostream>
#include <iomanip>
#include "conv.h"
using namespace std;

int main () {
   float celcius;
   float fahren;
   int precision; 
   cout << "enter celcius temp: ";
   cin >> celcius;
   cout << "enter a precision: "; 
   cin >> precision;
   fahren = 5 * (celcius - 32) / 9; // perform calculation
   cout << fixed;
   cout << "Fahrenheit = " << setprecision(precision) << fahren << endl;
 }
