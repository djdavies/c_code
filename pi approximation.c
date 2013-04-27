// A C program to approximate the value of Pi 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Function for calculating factorial	
int factorial_return(int factor)	
{
	int factorial = 1;
	int x;
	for(x=2; x<=factor; x++)
	{
		factorial = factorial * x;
	}
	return factorial;	
}
	
// Calculation of Pi Method	
double ramanujan_pi (double k)
{
    double c = (2*sqrt(2))/9801;				// Define constant
    double t = 0;     							// Define variable to hold value of 1/pi from loop
    double s; 									// Initialise Variable for loop        						    
    for (s = 0; s<k; s++)						// No of iterations determine degree of pi
    {  			  
        t = t + (factorial_return(4 * s) * (1103 + 26390*s)) / (pow(factorial_return(s), 4) * pow(396, (4*s)));
       
	}
	double pi = 1/(c*t);						// Answer is for {1/pi}, hence reciprocal required for pi
    return pi;     							// Return the value of pi			
}

// Main Method
int main (int argc, char *argv[]) 
{
	printf ("################################\nRamanujan Pi Calculation Program\n################################\n\n");
	double result = ramanujan_pi(30.0);			// Returns pi with x iterations of the ramanujan_pi logic loop
	printf ("The result is %.15f \n\n", result);	// Prints the result (NOTE: .15f prints to 15 decimal places)
	return 0;
}
