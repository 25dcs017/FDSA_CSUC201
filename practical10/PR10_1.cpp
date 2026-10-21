
#include <iostream>
using namespace std;

int main() {
    int parking[10];

    // Initialize all slots as empty
    for (int i = 0; i < 10; i++) {
        parking[i] = -1;
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int reg;
        cout << "Enter vehicle registration number: ";
        cin >> reg;

        int slot = reg % 10;
        int count = 0;

        // Find an empty slot using linear probing
        while (parking[slot] != -1 && count < 10) {
            slot = (slot + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full! Vehicle "
                 << reg << " cannot be parked.\n";
        } else {
            parking[slot] = reg;
            cout << "Vehicle " << reg
                 << " parked in slot " << slot << endl;
        }
    }

    // Display final parking lot
    cout << "\nFinal Parking Lot:\n";

    for (int i = 0; i < 10; i++) {
        if (parking[i] == -1) {
            cout << "Slot " << i << ": Empty" << endl;
        } else {
            cout << "Slot " << i << ": "
                 << parking[i] << endl;
        }
    }

    return 0;
}
