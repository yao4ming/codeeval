#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

const int years = 30;
const int months = 12;
int period[years][months];
int numOfMonths;

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
    for (j = trimmedStr.size()-1; j >=0 ; --j) {
        if (str[j] != ' ')
            break;
    }

    return trimmedStr.substr(0, j+1);
}

int convertMonth(string month) {
    if (strncmp(month.c_str(), "Jan", 3) == 0)
        return 1;
    else if (strncmp(month.c_str(), "Feb", 3) == 0)
        return 2;
    else if (strncmp(month.c_str(), "Mar", 3) == 0)
        return 3;
    else if (strncmp(month.c_str(), "Apr", 3) == 0)
        return 4;
    else if (strncmp(month.c_str(), "May", 3) == 0)
        return 5;
    else if (strncmp(month.c_str(), "Jun", 3) == 0)
        return 6;
    else if (strncmp(month.c_str(), "Jul", 3) == 0)
        return 7;
    else if (strncmp(month.c_str(), "Aug", 3) == 0)
        return 8;
    else if (strncmp(month.c_str(), "Sep", 3) == 0)
        return 9;
    else if (strncmp(month.c_str(), "Oct", 3) == 0)
        return 10;
    else if (strncmp(month.c_str(), "Nov", 3) == 0)
        return 11;
    else if (strncmp(month.c_str(), "Dec", 3) == 0)
        return 12;
}

void initPeriod() {
    numOfMonths = 0;
    for (int j = 0; j < years; ++j) {
        for (int i = 0; i < months; ++i)
            period[j][i] = 0;
    }
}

int main(int argc, char** argv) {
    ifstream in(argv[1]);
    string line;

    while (getline(in, line)) {
        initPeriod();

        stringstream ss(line);
        string token;
        while (getline(ss, token, ';')) {
            token = trim(token);
            int i;
            for (i = 0; i < token.size(); ++i) {
                if (token[i] == '-')
                    break;
            }

            string start = token.substr(0, i);
            string end = token.substr(i+1);

            //GET INDEX TO EXTRACT START MONTH AND YEAR
            for (i = 0; i < start.size(); ++i) {
                if (start[i] == ' ')
                    break;
            }
            int startMonth = convertMonth(start.substr(0, i));
            int startYear = stoi(start.substr(i+1));

            //GET INDEX TO EXTRACT EMD MONTH AND YEAR
            for (i = 0; i < end.size(); ++i) {
                if (end[i] == ' ')
                    break;
            }
            int endMonth = convertMonth(end.substr(0, i));
            int endYear = stoi(end.substr(i+1));

            for (int currYear = startYear; currYear <= endYear; ++currYear) {

                //JUN 2014 - MAR 2015, 2015  start at JAN
                if (currYear != startYear)
                    startMonth = 1;

                //JUN 2014 - MAR 2015, 2014 end at DEC
                if (endMonth < startMonth || endYear > startYear || currYear > startYear)
                    endMonth = 12;

                //set back to original end month
                if (currYear == endYear)
                    endMonth = convertMonth(end.substr(0, i));

                //count num of worked months
                for (int currMonth = startMonth - 1; currMonth < endMonth; ++currMonth) {
                    if (!period[currYear - 1990][currMonth]) {
                        period[currYear - 1990][currMonth] = true;
                        numOfMonths++;
                    }
                }
            }
        }
        cout << numOfMonths / 12 << endl;
    }
}