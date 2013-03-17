#include <stdio.h>
#include <math.h>
void calculate (int input) {
    double pi = 5 * (input - 32) / 9; // calculation
    //printf here
}

int main (int argc, char**argv) { // main func
    int i;
    for(i = 0; i<100; i+=5){ // start, end, step
        convert(i); // call function
    }
    return 0;
}
