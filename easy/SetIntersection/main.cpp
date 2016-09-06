#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        string list;
        string num;
        vector<string> lists;
        set<int> list1;
        vector<int> list2;

        //get sorted list
        stringstream ss(line);
        while (getline(ss, list, ';'))
            lists.push_back(list);

        //get nums in list1
        stringstream ss2(lists[0]);
        while (getline(ss2, num, ','))
            list1.insert(stoi(num));

        //get nums in list2
        stringstream ss3(lists[1]);
        while (getline(ss3, num, ','))
            list2.push_back(stoi(num));

        //find intersection in lists
        stringstream out;
        for (int i = 0; i < list2.size(); ++i) {
            if (list1.find(list2[i]) != list1.end())
                out << list2[i] << ",";
        }
        cout << out.str().substr(0, out.str().size()-1) << endl;

    }
}