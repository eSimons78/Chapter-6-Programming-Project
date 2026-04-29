#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_FAHRENHEIT = 0;
const int MAX_FAHRENHEIT = 20;

/*
Purpose:
    Converts a Fahrenheit temperature to Celsius.

Preconditions:
    fahrenheit represents a valid temperature value.

Postconditions:
    Returns the equivalent temperature in degrees Celsius.
*/
double getCelsius(double fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}

int main()
{
    double celsius;

    cout << "Fahrenheit to Celsius Temperature Table" << endl;
    cout << "---------------------------------------" << endl;

    cout << right << setw(12) << "Fahrenheit"
         << setw(12) << "Celsius" << endl;

    cout << right << setw(12) << "----------"
         << setw(12) << "-------" << endl;

    cout << fixed << setprecision(1);

    for (int fahrenheit = MIN_FAHRENHEIT; fahrenheit <= MAX_FAHRENHEIT; fahrenheit++)
    {
        celsius = getCelsius(fahrenheit);

        cout << right << setw(12) << fahrenheit
             << setw(12) << celsius << endl;
    }

    return 0;
}