#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

string trim(string str) {
    string trimmedStr;
    int i, j;

    //trim left end
    for (i= 0; i < str.size(); ++i) {
        if (str[i] != ' ')
            break;
    }

    trimmedStr = str.substr(i);

    //trim right end
    for (j = trimmedStr.size()-1; j >= 0 ; --j) {
        if (trimmedStr[j] != ' ')
            break;
    }

    return trimmedStr.substr(0, j+1);
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, '|'))
            tokens.push_back(trim(token));

        stringstream ss2(tokens[0]);
        vector<int> nums;
        while (getline(ss2, token, ' '))
            nums.push_back(stoi(token));

        int iter = 0;
        for (int i = 0, j = i + 1; j < nums.size(); ++i, j++) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                i = -1;
                j = i + 1;
                iter++;
            }

            if (iter == stoi(tokens[1]))
                break;
        }

        for (int k = 0; k < nums.size(); ++k)
            cout << nums[k] << " ";
        cout << endl;
    }
}