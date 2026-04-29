#include <iostream>
#include <string>
#include <limits>
using namespace std;

/*
Purpose:
    Prompts the user for a region name and the number of accidents reported
    in that region.

Preconditions:
    None.

Postconditions:
    accidents > 0
    Validated values are returned to the caller through reference parameters.
*/
void getRegInfo(string& regionName, int& accidents)
{
    cout << "Enter the name of the region: ";
    getline(cin, regionName);

    cout << "Enter the number of accidents reported in " << regionName << ": ";
    cin >> accidents;

    while (cin.fail() || accidents <= 0)
    {
        cout << "Invalid input. The number of accidents must be greater than 0." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the number of accidents reported in " << regionName << ": ";
        cin >> accidents;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
Purpose:
    Determines whether one accident count is less than or equal to another.

Preconditions:
    Both values represent validated accident counts.

Postconditions:
    Returns true if value1 <= value2.
    Returns false otherwise.
*/
bool isLower(int value1, int value2)
{
    return value1 <= value2;
}

/*
Purpose:
    Displays the name of the safest region and its number of accidents.

Preconditions:
    regionName corresponds to the region with the lowest accident count.

Postconditions:
    Results are written to the console.
*/
void showLowest(string regionName, int accidents)
{
    cout << endl;
    cout << "Safest Driving Area" << endl;
    cout << "-------------------" << endl;
    cout << "The safest region is: " << regionName << endl;
    cout << "Number of accidents: " << accidents << endl;
}

int main()
{
    const int NUM_REGIONS = 5;

    string regionName;
    string safestRegion;
    int accidents;
    int lowestAccidents;

    cout << "Safest Driving Area Program" << endl;
    cout << "---------------------------" << endl;

    for (int count = 1; count <= NUM_REGIONS; count++)
    {
        cout << endl;
        cout << "Region " << count << " of " << NUM_REGIONS << endl;

        getRegInfo(regionName, accidents);

        if (count == 1)
        {
            lowestAccidents = accidents;
            safestRegion = regionName;
        }
        else if (isLower(accidents, lowestAccidents))
        {
            lowestAccidents = accidents;
            safestRegion = regionName;
        }
    }

    showLowest(safestRegion, lowestAccidents);

    return 0;
}