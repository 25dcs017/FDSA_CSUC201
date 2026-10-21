
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int table[SIZE];

    // Initialize all slots as empty
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }

    int n, id;
    cout << "Enter number of students: ";
    cin >> n;

    // Jump sizes coprime with table size 10
    int steps[] = {1, 3, 7, 9};

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % SIZE;
        int h2 = steps[id % 4];
        bool placed = false;

        // Double hashing
        for (int j = 0; j < SIZE; j++) {
            int slot = (h1 + j * h2) % SIZE;

            if (table[slot] == -1) {
                table[slot] = id;
                cout << "Student " << id
                     << " placed at slot " << slot << endl;
                placed = true;
                break;
            }
        }

        if (!placed) {
            cout << "Hash table is full or no slot found "
                 << "in the probe sequence for ID "
                 << id << endl;
        }
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}
