#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;

    getline(in, line);
    int numLines = stoi(line);
    vector<pair<int, string>> lines;
    while (getline(in, line)) {
        lines.push_back(pair<int, string>(line.size(), line))

    sort(lines.rbegin(), lines.rend());

    for (int i = 0; i < numLines; ++i)
        cout << lines[i].second << endl;

}