#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 12;
    int table[n][n];

    for (int i = 0; i < n; ++i) {
        table[i][0] = i + 1;
        for (int j = 1; j < n; ++j) {
            table[i][j] = table[i][j-1] + i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            (j != n - 1) ? cout << table[i][j] << setw(4) : cout << table[i][j];
        }
        cout << endl;
    }

}