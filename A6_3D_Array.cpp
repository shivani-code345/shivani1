#include <iostream>
using namespace std;

int main() {
    int num_rows, num_columns, num_depth;
    cout << "Enter the number of rows: ";
    cin >> num_rows;
    cout << "Enter the number of columns: ";
    cin >> num_columns;
    cout << "Enter the number of depth levels: ";
    cin >> num_depth;

    char memory_arrangement; 
    cout << "Enter memory arrangement (R for ROM major, C for COLUMN major): ";
    cin >> memory_arrangement;

    unsigned long long base_address; 
    cout << "Enter the base address (in hexadecimal): ";
    cin >> hex >> base_address;

    int i, j, k;
    cout << "Enter the row index (i): ";
    cin >> i;
    cout << "Enter the column index (j): ";
    cin >> j;
    cout << "Enter the depth index (k): ";
    cin >> k;
    unsigned long long address;
    if (memory_arrangement == 'R') {
        address = base_address + (i * num_columns * num_depth + j * num_depth + k) * sizeof(int);
    } else if (memory_arrangement == 'C') {
        address = base_address + (k * num_rows * num_columns + j * num_rows + i) * sizeof(int);
    } else {
        cout << "Invalid memory arrangement. Please choose 'R' or 'C'." << endl;
        return 1;
    }
    cout << "Address of element (" << i << ", " << j << ", " << k << "): 0x" << hex << address << endl;

    return 0;
}
