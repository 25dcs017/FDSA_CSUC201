#include <iostream>
using namespace std;

// Iterative Binary Search
int iterativeSearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// Recursive Binary Search
int recursiveSearch(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target < arr[mid])
    {
        return recursiveSearch(arr, low, mid - 1, target);
    }
    else
    {
        return recursiveSearch(arr, mid + 1, high, target);
    }
}

int main()
{
    int n, target;

    cout << "Enter number of books: ";
    cin >> n;

    int arr[n];

    cout << "Enter book codes in sorted order:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target book code: ";
    cin >> target;

    int result1 = iterativeSearch(arr, n, target);
    int result2 = recursiveSearch(arr, 0, n - 1, target);

    cout << "\nIterative Search Position: " << result1 << endl;
    cout << "Recursive Search Position: " << result2 << endl;

    return 0;
}