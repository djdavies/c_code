 // function fahrToCel to perform conversion
 main fahrToCel() {
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
