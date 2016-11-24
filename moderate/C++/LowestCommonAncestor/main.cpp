#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class Node {

public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    bool add(int val) {
        if (val == this->val) {
            return false;
        } else if (val < this->val) {
            if (left == NULL) {
                left = new Node(val);
                return true;
            } else {
                return left->add(val);
            }
        } else if (val > this->val) {
            if (right == NULL) {
                right = new Node(val);
                return true;
            } else {
                return right->add(val);
            }
        }
        return false;
    }
};

class BinaryTree {
    Node* root = NULL;

public:
    BinaryTree() {}

    bool add(int val) {
        if (root == NULL) {
            root = new Node(val);
            return true;
        } else {
            return root->add(val);
        }
    }

    int lca(int num1, int num2) {
        Node* curr = root;

        while (curr != NULL) {
            int val = curr->val;
            if (val == num1 || val == num2)
                return val;
            //if node are on opposite sides of current node
            if((val > num1 && val < num2) || (val < num1 && val > num2))
                return val;
            else if(val > num1 && val > num2)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    BinaryTree* tree = new BinaryTree();
    tree->add(30);
    tree->add(8);
    tree->add(52);
    tree->add(3);
    tree->add(20);
    tree->add(10);
    tree->add(29);

    ifstream in(argv[1]);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string token;
        vector<int> tokens;
        while (getline(ss, token, ' '))
            tokens.push_back(stoi(token));
        cout << tree->lca(tokens[0], tokens[1]) << endl;
    }
}