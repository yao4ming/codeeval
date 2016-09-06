#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        int count[line.size()];

        //init count arr to 0's
        for (int j = 0; j < line.size(); ++j) {
            count[j] = 0;
        }

        //count digit pos
        for (int i = 0; i < line.size(); ++i) {
            int pos = line[i] - '0';
            count[pos]++;
        }

        //check if count arr matches line
        bool match = true;
        for (int k = 0; k < line.size(); ++k) {
            if (line[k] - '0' != count[k]) {
                cout << 0 << endl;
                match = false;
                break;
            }
        }
        if (match)
            cout << 1 << endl;
    }
}