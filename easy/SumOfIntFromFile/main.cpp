#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    int sum = 0;
    while (getline(in, line)) {
        sum += stoi(line);
    }
    cout << sum;
}