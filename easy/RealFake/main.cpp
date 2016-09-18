#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        int sum = (line[0] - '0') * 2;
        for (int i = 2; i < line.size(); i += 2)
            sum += (line[i] - '0') * 2;

        for (int j = 1; j < line.size(); j += 2)
            sum += line[j] - '0';

        if (sum % 10 == 0)
            cout << "Real" << endl;
        else
            cout << "Fake" << endl;
    }
}