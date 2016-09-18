#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<vector<int>> timeStamp;
        while (getline(ss, token, ' ')) {
            vector<int> time;
            stringstream ss2(token);
            while (getline(ss2, token, ':'))
                time.push_back(stoi(token));

            timeStamp.push_back(time);
        }

        sort(timeStamp.begin(), timeStamp.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     if (a[1] == b[1])
                         return a[2] > b[2];
                      else
                         return a[1] > b[1];
                 } else {
                     return a[0] > b[0];
                 }
             });

        for (int i = 0; i < timeStamp.size(); ++i) {
            for (int j = 0; j < timeStamp[i].size(); ++j) {
                if (j != timeStamp[i].size()-1) {
                    if (to_string(timeStamp[i][j]).size() == 1)
                        cout << "0" << timeStamp[i][j] << ":";
                    else
                        cout << timeStamp[i][j] << ":";
                } else {
                    if (to_string(timeStamp[i][j]).size() == 1)
                        cout << "0" << timeStamp[i][j];
                    else
                        cout << timeStamp[i][j];
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}