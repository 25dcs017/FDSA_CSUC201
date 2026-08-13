#include <iostream>
using namespace std;

// Iterative Search
int iterativeSearch(string plates[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (plates[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Recursive Search
int recursiveSearch(string plates[], int n, string target, int i)
{
    if (i == n)
    {
        return -1;
    }

    if (plates[i] == target)
    {
        return i;
    }

    return recursiveSearch(plates, n, target, i + 1);
}

int main()
{
    int n;
    string target;

    cout << "Enter number of vehicles: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> plates[i];
    }

    cout << "Enter target license plate: ";
    cin >> target;

    int result1 = iterativeSearch(plates, n, target);
    int result2 = recursiveSearch(plates, n, target, 0);

    cout << "\nIterative Search Position: " << result1 << endl;
    cout << "Recursive Search Position: " << result2 << endl;

    return 0;
}