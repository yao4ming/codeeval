#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ';'))
            tokens.push_back(token);

        vector<int> nums;
        int val = stoi(tokens[1]);
        stringstream ss2(tokens[0]);
        while (getline(ss2, token, ','))
            nums.push_back(stoi(token));

        stringstream out;
        bool found = false;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {

                if (nums[i] + nums[j] == val) {
                    out << nums[i] << "," << nums[j] << ";";
                    found = true;
                    break;
                }
            }
        }

        if (found)
            cout << out.str().substr(0, out.str().size()-1) << endl;
        else
            cout << "NULL" << endl;
    }
}