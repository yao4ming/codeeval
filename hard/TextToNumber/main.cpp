#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>
#include <string.h>
using namespace std;

int textToNum(string text) {
    if (strncmp(text.c_str(), "negative", 8) == 0)
        return 1;
    else if (strncmp(text.c_str(), "zero", 4) == 0)
        return 0;
    else if (strncmp(text.c_str(), "one", 3) == 0)
        return 1;
    else if (strncmp(text.c_str(), "two", 3) == 0)
        return 2;
    else if (strncmp(text.c_str(), "three", 5) == 0)
        return 3;
    else if (strncmp(text.c_str(), "four", 4) == 0)
        return 4;
    else if (strncmp(text.c_str(), "five", 4) == 0)
        return 5;
    else if (strncmp(text.c_str(), "six", 3) == 0)
        return 6;
    else if (strncmp(text.c_str(), "seven", 5) == 0)
        return 7;
    else if (strncmp(text.c_str(), "eight", 5) == 0)
        return 8;
    else if (strncmp(text.c_str(), "nine", 4) == 0)
        return 9;
    else if (strncmp(text.c_str(), "ten", 3) == 0)
        return 10;
    else if (strncmp(text.c_str(), "eleven", 6) == 0)
        return 11;
    else if (strncmp(text.c_str(), "twelve", 6) == 0)
        return 12;
    else if (strncmp(text.c_str(), "thirteen", 8) == 0)
        return 13;
    else if (strncmp(text.c_str(), "fourteen", 8) == 0)
        return 14;
    else if (strncmp(text.c_str(), "fifteen", 7) == 0)
        return 15;
    else if (strncmp(text.c_str(), "sixteen", 7) == 0)
        return 16;
    else if (strncmp(text.c_str(), "seventeen", 9) == 0)
        return 17;
    else if (strncmp(text.c_str(), "eighteen", 8) == 0)
        return 18;
    else if (strncmp(text.c_str(), "nineteen", 8) == 0)
        return 19;
    else if (strncmp(text.c_str(), "twenty", 6) == 0)
        return 20;
    else if (strncmp(text.c_str(), "thirty", 6) == 0)
        return 30;
    else if (strncmp(text.c_str(), "forty", 5) == 0)
        return 40;
    else if (strncmp(text.c_str(), "fifty", 5) == 0)
        return 50;
    else if (strncmp(text.c_str(), "sixty", 5) == 0)
        return 60;
    else if (strncmp(text.c_str(), "seventy", 7) == 0)
        return 70;
    else if (strncmp(text.c_str(), "eighty", 6) == 0)
        return 80;
    else if (strncmp(text.c_str(), "ninety", 6) == 0)
        return 90;
    else if (strncmp(text.c_str(), "hundred", 7) == 0)
        return 100;
    else if (strncmp(text.c_str(), "thousand", 8) == 0)
        return 1000;
    else if (strncmp(text.c_str(), "million", 7) == 0)
        return 1000000;

}

char getOperator(int operand1, int operand2) {
    if (operand1 == -1) {
        return '*';
    }
    else if (operand1 == 0) {
        return '\0';
    }
    else if (operand1 >= 1 && operand1 <= 19) {
        return '*';
    }
    else if (operand1 >= 20 && operand1 <= 90) {
        if (operand2 == 100 || operand2 == 1000 || operand2 == 1000000)
            return '*';
        else
            return '+';
    }
    else if (operand1 == 100) {
        if (operand2 == 1000 || operand2 == 1000000)
            return '*';
        else
            return '+';
    }
    else if (operand1 == 1000) {
        if (operand2 == 1000000)
            return '*';
        else
            return '+';
    }
    else if (operand1 == 1000000) {
        return '+';
    }
    else {
        return '\0';
    }

}

bool isOperator(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return true;
        default:
            return false;
    }
}

int priority(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
}

vector<string> infixToPostfix(string infix) {
    vector<string> postfix;
    stack<char> stack1;
    string num = "";

    //get operators and operands
    for (int i = 0; i < infix.size(); i++) {
        char symbol = infix[i];

        //operand
        if (!isOperator(symbol)) {
            num += symbol;
            if (isOperator(infix[i+1]) || i == infix.size() - 1) {
                postfix.push_back(num);
            }
        }//operator
        else {
            num = "";
            //push first operator to stack
            if (stack1.size() == 0) {
                stack1.push(symbol);
            }//push operator to postfix
            else {
                while (!stack1.empty() && (priority(symbol) <= priority(stack1.top()))) {
                    string str = "";
                    str += stack1.top();
                    stack1.pop();
                    postfix.push_back(str);
                }
                stack1.push(symbol);
            }
        }
    }
    //push remaining operators to postfix
    while(stack1.size() > 0) {
        string str = "";
        str += stack1.top();
        stack1.pop();
        postfix.push_back(str);
    }
    return postfix;
}

int evaluateOperator(char oper, int op1, int op2) {
    switch (oper) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '%': return op1 % op2;
    }
}

int evaluatePostFix(vector<string> postfix) {
    stack<int> stack1;
    for (int i = 0; i < postfix.size(); i++) {

        //push operand to stack
        if (!isOperator(postfix[i][0])) {
            stack1.push(stoi(postfix[i]));
        }
            //pop operands and evaluate with operator
            //push new resulting operand to stack
        else {
            if (stack1.size() < 2)
                cout << "Not enough operands for " << postfix[i];

            int second = stack1.top();
            stack1.pop();
            int first = stack1.top();
            stack1.pop();
            int result = evaluateOperator(postfix[i][0], first, second);
            stack1.push(result);
        }
    }
    //return evaluated postfix
    if (stack1.size() == 1)
        return stack1.top();
    else
        cout << "Too many values" << endl;
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

        string infix = "";
        for (int i = 0; i < tokens.size(); ++i) {
            int num = textToNum(tokens[i]);
            int num2 = 0;
            char op = '\0';
            if (i != tokens.size() - 1) {
                num2 = textToNum(tokens[i+1]);
                op = getOperator(num, num2);
            }

            infix += to_string(num);
            infix += op;
        }

        vector<string> postFix = infixToPostfix(infix);
        if (strncmp(tokens[0].c_str(), "negative", 8) == 0)
            cout << -1 * evaluatePostFix(postFix) << endl;
        else
            cout << evaluatePostFix(postFix) << endl;
    }
}