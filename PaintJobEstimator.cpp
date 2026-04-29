#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

const double GALLONS_PER_SQ_FT = 1.0 / 110.0;
const double LABOR_HOURS_PER_SQ_FT = 8.0 / 110.0;
const double LABOR_CHARGE_PER_HOUR = 25.00;

/*
Purpose:
    Prompts the user for the number of rooms to be painted.

Parameters:
    None.

Preconditions:
    None.

Postconditions:
    Returns a number of rooms that is at least 1.
*/
int getNumRooms()
{
    int rooms;

    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    while (cin.fail() || rooms < 1)
    {
        cout << "Invalid input. Number of rooms must be at least 1." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
    }

    return rooms;
}

/*
Purpose:
    Prompts the user for the price per gallon of paint.

Parameters:
    None.

Preconditions:
    None.

Postconditions:
    Returns a paint price that is $10.00 or greater.
*/
double getPricePerGallon()
{
    double price;

    cout << "Enter the price per gallon of paint: $";
    cin >> price;

    while (cin.fail() || price < 10.00)
    {
        cout << "Invalid input. Paint price must be $10.00 or greater." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the price per gallon of paint: $";
        cin >> price;
    }

    return price;
}

/*
Purpose:
    Prompts the user for the square feet of wall space in a room.

Parameters:
    roomNumber - the current room number being entered.

Preconditions:
    roomNumber is a valid room number.

Postconditions:
    Returns square footage that is 0 or greater.
*/
double getSqFt(int roomNumber)
{
    double sqFt;

    cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
    cin >> sqFt;

    while (cin.fail() || sqFt < 0)
    {
        cout << "Invalid input. Square footage must be 0 or greater." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
        cin >> sqFt;
    }

    return sqFt;
}

/*
Purpose:
    Calculates the gallons of paint needed for a room.

Parameters:
    sqFt - the square feet of wall space.

Preconditions:
    sqFt is 0 or greater.

Postconditions:
    Returns the gallons needed, rounded up to the next whole gallon.
*/
int gallonsForRoom(double sqFt)
{
    return static_cast<int>(ceil(sqFt * GALLONS_PER_SQ_FT));
}

/*
Purpose:
    Calculates the labor hours needed for a given amount of wall space.

Parameters:
    sqFt - the square feet of wall space.

Preconditions:
    sqFt is 0 or greater.

Postconditions:
    Returns the labor hours required.
*/
double laborHoursForRoom(double sqFt)
{
    return sqFt * LABOR_HOURS_PER_SQ_FT;
}

/*
Purpose:
    Displays the complete paint job estimate.

Parameters:
    totalGallons - total gallons of paint required.
    laborHours - total labor hours required.
    paintCost - total cost of paint.
    laborCost - total labor charges.
    totalCost - total cost of the paint job.

Preconditions:
    All values have been calculated and are valid.

Postconditions:
    The full estimate is written to the console.
*/
void displayEstimate(int totalGallons, double laborHours, double paintCost, double laborCost, double totalCost)
{
    cout << endl;
    cout << fixed << setprecision(2);

    cout << "Paint Job Estimate" << endl;
    cout << "------------------" << endl;
    cout << "Total gallons of paint required: " << totalGallons << endl;
    cout << "Total labor hours required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of paint job: $" << totalCost << endl;
}

int main()
{
    int numRooms;
    double pricePerGallon;
    double sqFt;

    int totalGallons = 0;
    double totalLaborHours = 0.0;

    double paintCost;
    double laborCost;
    double totalCost;

    cout << "Paint Job Estimator" << endl;
    cout << "-------------------" << endl;

    numRooms = getNumRooms();
    pricePerGallon = getPricePerGallon();

    for (int room = 1; room <= numRooms; room++)
    {
        sqFt = getSqFt(room);

        totalGallons += gallonsForRoom(sqFt);
        totalLaborHours += laborHoursForRoom(sqFt);
    }

    paintCost = totalGallons * pricePerGallon;
    laborCost = totalLaborHours * LABOR_CHARGE_PER_HOUR;
    totalCost = paintCost + laborCost;

    displayEstimate(totalGallons, totalLaborHours, paintCost, laborCost, totalCost);

    return 0;
}