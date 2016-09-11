#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;

    while (getline(in, line)) {
        int lowCount = 0;
        int upCount = 0;
        for (int i = 0; i < line.size(); ++i) {
            if (islower(line[i]))
                lowCount++;
            else
                upCount++;
        }
        cout << fixed << setprecision(2) << "lowercase: " << (double) lowCount * 100 / line.size() <<  " uppercase: " << (double) upCount * 100 / line.size() << endl;
    }
}