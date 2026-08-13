#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter colour codes (0, 1, 2):" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] != 0 && arr[i] != 1 && arr[i] != 2)
        {
            cout << "Invalid input! Enter only 0, 1, or 2." << endl;
            return 0;
        }
    }

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    cout << "Sorted colour codes: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}