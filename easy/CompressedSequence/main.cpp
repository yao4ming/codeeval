#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        int freq = 0, prevVal = -1;

        while (getline(ss, token, ' ')) {
            int val = stoi(token);
            if (prevVal == val) {
                freq++;
            } else {
                if (prevVal != -1)
                    cout << freq << " " << prevVal << " ";
                freq = 1;
                prevVal = val;
            }
        }
        cout << freq << " " << prevVal << " ";
        cout << endl;
    }
}