
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    vector<list<int>> shelves(10);

    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;

        int shelf = code % 10;

        shelves[shelf].push_back(code);

        cout << "Book " << code
             << " added to shelf " << shelf << endl;
    }

    cout << "\nFinal Contents of Shelves:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelves[i].empty()) {
            cout << "Empty";
        } else {
            for (int book : shelves[i]) {
                cout << book << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
