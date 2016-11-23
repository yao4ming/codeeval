#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        vector<int> prevLevel = {1};
        vector<int> currLevel;
        int depth = stoi(line);
        cout << 1 << " ";

        for (int i = 0; i < depth - 1; ++i) {
            currLevel.clear();
            currLevel.push_back(1);
            cout << 1 << " ";
            for (int j = 0; j < prevLevel.size() - 1; ++j) {
                currLevel.push_back(prevLevel[j] + prevLevel[j+1]);
                cout << prevLevel[j] + prevLevel[j+1] << " ";
            }
            cout << 1 << " ";
            currLevel.push_back(1);

            prevLevel = currLevel;
        }
        cout << endl;
    }
}