#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void decToBin(int decimal) {

    if (decimal == 0)
        cout << 0;

    if (decimal == 1)
        cout << 1;

    vector<short> remainders;
    while(decimal != 0) {
        remainders.push_back(decimal % 2);
        decimal /= 2;
    }

    for(int i = remainders.size() - 1; i >= 0; i--)
        cout << remainders[i];

    cout << endl;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line))
        decToBin(stoi(line));
}