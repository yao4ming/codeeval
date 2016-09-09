#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;

    nextNum:
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        map<int, int> myMap;
        int len = 0;
        while (getline(ss, token, ',')) {
            int num = stoi(token);
            if (myMap.find(num) != myMap.end())
                myMap[num]++;
             else
                myMap.insert(pair<int, int>(num, 1));
            len++;
        }

        for(map<int, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++) {
            if (iter->second > len / 2) {
                cout << iter->first << endl;
                goto nextNum;
            }
        }

        cout << "None" << endl;
    }
}