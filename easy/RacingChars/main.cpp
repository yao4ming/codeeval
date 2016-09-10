#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    vector<string> track;
    while (getline(in, line)) {
        track.push_back(line);
    }

    int prev;
    bool gateFound;
    for (int i = 0; i < track[0].size(); ++i) {
        if (track[0][i] == '_') {
            track[0][i] = '|';
            prev = i;
        }
        cout << track[0][i];
    }
    cout << endl;
    for (int i = 1; i < track.size(); ++i) {

        gateFound = false;

        if (track[i][prev-1] == 'C') {
            track[i][prev-1] = '/';
            prev--;
            gateFound = true;
        }
        else if (track[i][prev] == 'C') {
            track[i][prev] = '|';
            gateFound = true;
        }
        else if (track[i][prev+1] == 'C') {
            track[i][prev+1] = '\\';
            prev++;
            gateFound = true;
        }

        if (!gateFound) {
            if (track[i][prev-1] == '_') {
                track[i][prev-1] = '/';
                prev--;
            }
            else if (track[i][prev] == '_') {
                track[i][prev] = '|';
            }
            else if (track[i][prev+1] == '_') {
                track[i][prev+1] = '\\';
                prev++;
            }
        }
        cout << track[i] << endl;
    }
}