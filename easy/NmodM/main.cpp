#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void split(const string &s, char delim, vector<int> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(stoi(item));
    }
}

vector<int> split(const string &s, char delim) {
    vector<int> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        vector<int> nums = split(line, ',');
        int val = nums[0] / nums[1];
        int product = val * nums[1];
        cout << nums[0] - product << endl;
    }
}