#include <iostream>
#include <limits>
using namespace std;

/*
Purpose:
    Prompts the user for the rectangle's length and width and validates input.

Preconditions:
    None.

Postconditions:
    length > 0
    width > 0
    Validated values are returned to the caller through reference parameters.
*/
void getLengthWidth(double& length, double& width)
{
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    while (cin.fail() || length <= 0)
    {
        cout << "Invalid input. Length must be greater than 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the length of the rectangle: ";
        cin >> length;
    }

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    while (cin.fail() || width <= 0)
    {
        cout << "Invalid input. Width must be greater than 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the width of the rectangle: ";
        cin >> width;
    }
}

/*
Purpose:
    Calculates and returns the perimeter of a rectangle.

Preconditions:
    length and width have already been validated.

Postconditions:
    Returns the calculated perimeter.
*/
double calcPerimeter(double length, double width)
{
    return 2 * (length + width);
}

/*
Purpose:
    Calculates and returns the area of a rectangle.

Preconditions:
    length and width have already been validated.

Postconditions:
    Returns the calculated area.
*/
double calcArea(double length, double width)
{
    return length * width;
}

/*
Purpose:
    Displays the perimeter and area of a rectangle.

Preconditions:
    Valid perimeter and area values are provided.

Postconditions:
    Results are written to the console.
*/
void displayProperties(double perimeter, double area)
{
    cout << endl;
    cout << "Rectangle Properties" << endl;
    cout << "--------------------" << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
    cout << endl;
}

int main()
{
    double length;
    double width;
    double perimeter;
    double area;
    char choice;

    do
    {
        getLengthWidth(length, width);

        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);

        displayProperties(perimeter, area);

        cout << "Would you like to process another rectangle? (Y/N): ";
        cin >> choice;

        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            cout << "Invalid choice. Please enter Y or N: ";
            cin >> choice;
        }

        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    cout << "Program ended." << endl;

    return 0;
}