#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/*
Purpose:
    Prompts the user for a judge's score and validates the input.

Preconditions:
    None.

Postconditions:
    Returns a value between 0.0 and 10.0, inclusive.
*/
double getScore()
{
    double score;

    cout << "Enter a judge's score between 0 and 10: ";
    cin >> score;

    while (cin.fail() || score < 0.0 || score > 10.0)
    {
        cout << "Invalid score. Score must be between 0 and 10." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter a judge's score between 0 and 10: ";
        cin >> score;
    }

    return score;
}

/*
Purpose:
    Determines whether one score is less than or equal to another.

Preconditions:
    Both values represent validated scores.

Postconditions:
    Returns true if value1 <= value2.
    Returns false otherwise.
*/
bool isLower(double value1, double value2)
{
    return value1 <= value2;
}

/*
Purpose:
    Determines whether one score is greater than or equal to another.

Preconditions:
    Both values represent validated scores.

Postconditions:
    Returns true if value1 >= value2.
    Returns false otherwise.
*/
bool isHigher(double value1, double value2)
{
    return value1 >= value2;
}

/*
Purpose:
    Calculates the average score after removing the highest and lowest scores.

Preconditions:
    total includes all five scores.
    minScore and maxScore are valid scores.

Postconditions:
    Returns the average of the three remaining scores.
*/
double calcAverage(double total, double minScore, double maxScore)
{
    return (total - minScore - maxScore) / 3.0;
}

int main()
{
    const int NUM_JUDGES = 5;

    double score;
    double total = 0.0;
    double minScore;
    double maxScore;
    double finalScore;

    cout << "Star Search Score Calculator" << endl;
    cout << "----------------------------" << endl;

    for (int judge = 1; judge <= NUM_JUDGES; judge++)
    {
        cout << endl << "Judge " << judge << endl;

        score = getScore();
        total += score;

        if (judge == 1)
        {
            minScore = score;
            maxScore = score;
        }
        else
        {
            if (isLower(score, minScore))
            {
                minScore = score;
            }

            if (isHigher(score, maxScore))
            {
                maxScore = score;
            }
        }
    }

    finalScore = calcAverage(total, minScore, maxScore);

    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Final Score: " << finalScore << endl;

    return 0;
}