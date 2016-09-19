#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Node {
public:

    Node(int val) {
        this->val = val;
        traversed = false;
        left = right =  NULL;
        sum = 0;
    }

    ~Node() {
        if (left != NULL)
            delete[](left);

        if (right != NULL)
            delete[](right);
    }

    int val;
    Node* left;
    Node* right;
    bool traversed;
    int sum;
};

Node* root = NULL;

void initTriangle(string file) {

    ifstream in(file);
    string line;

    getline(in, line);
    root = new Node(stoi(line));

    //set root as current
    vector<Node*> current;
    current.push_back(root);

    //read line/level
    while (getline(in, line)) {

        stringstream ss(line);
        string token;
        vector<int> vals;

        //parse line as array of ints
        while (getline(ss, token, ' '))
            vals.push_back(stoi(token));

        //set node values at level
        vector<Node*> nodes;
        for (int i = 0; i < vals.size(); i++)
            nodes.push_back(new Node(vals[i]));

        //set left and right pointer values of each node at level
        for (int i = 0; i < current.size(); i++) {
            current[i]->left = nodes[i];
            current[i]->right = nodes[i+1];
        }

        current.clear();
        current = nodes;
        nodes.clear();
    }
}

int findMaxSumFromRootToLeaf(Node* node) {
    if (node == NULL)
        return 0;

    if (node->traversed)
        return node->sum;

    node->traversed = true;
    node->sum = max(findMaxSumFromRootToLeaf(node->left), findMaxSumFromRootToLeaf(node->right)) + node->val;
    return node->sum;
}

int main(int argc, char** argv) {

    initTriangle(argv[1]);
    int maxSum = findMaxSumFromRootToLeaf(root);
    cout << maxSum << endl;
}