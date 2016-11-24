#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) {

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {

        transform(line.begin(), line.end(), line.begin(), ::tolower);

        set<char> letters;
        for (int i = 97; i < 123; ++i)
            letters.insert(i);

        set<char>::iterator iter;
        for (int i = 0; i < line.size(); ++i) {
            if ((iter = letters.find(line[i])) != letters.end()) {
                letters.erase(iter);
            }
        }

        if (letters.size() != 0) {
            for (iter = letters.begin(); iter != letters.end(); ++iter) {
                cout << *iter;
            }

        } else {
            cout << "NULL";
        }
        cout << endl;
    }
}