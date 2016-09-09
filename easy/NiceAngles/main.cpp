#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '.'))
            tokens.push_back(token);

        int mins = (stod(line) - stoi(tokens[0])) * 60;
        int secs = (stod(line) - stoi(tokens[0]) - (mins/60.0)) * 3600;

        string minutes = to_string(mins);
        string seconds = to_string(secs);
        if (mins == 0)
            minutes = "00";

        if (secs == 0)
            seconds = "00";

        if (minutes.size() == 1)
            minutes.insert(0, 1, '0');

        if (seconds.size() == 1)
            seconds.insert(0, 1, '0');

        cout << tokens[0] << "." << minutes << "'" << seconds << '"' << endl;
    }
}