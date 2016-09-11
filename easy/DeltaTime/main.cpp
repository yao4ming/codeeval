#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void difference(vector<int> time1, vector<int> time2) {
    string hours, mins, secs;
    //secs
    if (time1[2] - time2[2] < 0) {
        secs = to_string((time1[2] + 60) - time2[2]);
        time1[1]--;
    } else {
        secs = to_string(time1[2] - time2[2]);
    }

    //mins
    if (time1[1] - time2[1] < 0) {
        mins = to_string((time1[1] + 60) - time2[1]);
        time1[0]--;
    } else {
        mins = to_string(time1[1] - time2[1]);
    }

    //hours
    hours = to_string(time1[0] - time2[0]);

    if (secs.size() == 1)
        secs.insert(0, 1, '0');
    if (mins.size() == 1)
        mins.insert(0, 1, '0');
    if (hours.size() == 1)
        hours.insert(0, 1, '0');

    cout << hours << ":" << mins << ":" << secs << endl;
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(token);

        stringstream ss2(tokens[0]);
        vector<int> time1;
        while (getline(ss2, token, ':'))
            time1.push_back(stoi(token));

        stringstream ss3(tokens[1]);
        vector<int> time2;
        while (getline(ss3, token, ':'))
            time2.push_back(stoi(token));

        //time1 hour > time2 hour
        if (time1[0] > time2[0]) {
            difference(time1, time2);
        }//time1 hour = time2 hour
        else if (time1[0] == time2[0]) {
            //time1 min > time2 min
            if (time1[1] > time2[1])
                difference(time1, time2);
            else if (time1[1] == time2[1])
                (time1[2] > time2[2]) ? difference(time1, time2) : difference(time2, time1);
            else
                difference(time2, time1);
        }//time1 hour < time2 hour
        else {
            difference(time2, time1);
        }
    }
}