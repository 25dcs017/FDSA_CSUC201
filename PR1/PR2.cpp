#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;

    int book[n];

    cout << "Enter book IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "Books borrowed more than once:\n";

    for (int i = 0; i < n; i++)
    {
        bool alreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (book[i] == book[k])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (alreadyPrinted)
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (book[i] == book[j])
            {
                cout << book[i] << " ";
                break;
            }
        }
    }

    return 0;
}