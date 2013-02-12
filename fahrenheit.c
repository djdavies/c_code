#include <stdio.h>
void convert (int input) {
    int celcius = 5 * (input - 32) / 9; // calculation
    printf("fahren = %d - celcius = %d\n", input, celcius);
}

int main (int argc, char**argv) { // main func
    int i;
    for(i = 0; i<100; i+=5){ // start, end, step
        convert(i); // call function
    }
    return 0;
}
