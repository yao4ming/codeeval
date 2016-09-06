#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    string token;
    while (getline(in, line)) {
        set<int> mySet;
        stringstream ss(line);

        //extract nums and store in set(eliminating duplicates)
        while(getline(ss, token, ',')) {
            mySet.insert(stoi(token));
        }

        //print set
        stringstream output;
        for(set<int>::iterator iter = mySet.begin(); iter != mySet.end(); ++iter)
             output << *iter << ",";
        cout << output.str().substr(0, output.str().size()-1);
        cout << endl;
    }
}