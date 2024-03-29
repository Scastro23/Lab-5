// Samuel Castro
// Lab 5
// SP2024
/* Description: Create a binary tree class which will take strings of website names and sort
them in alphabetical order. Your class should also be able to sort them in reverse
alphabetical order as well.*/

#include <iostream>
#include <string>

using namespace std;

class BiTreeNode {
public:
    string data;
    BiTreeNode* left;
    BiTreeNode* right;

    BiTreeNode(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BiTree {
private:
    BiTreeNode* root;

    // Helper function for adding a node
    BiTreeNode* addNode(BiTreeNode* node, string val) {
        if (node == nullptr) {
            return new BiTreeNode(val);
        }

        if (val < node->data) {
            node->left = addNode(node->left, val);
        }
        else if (val > node->data) {
            node->right = addNode(node->right, val);
        }

        return node;
    }

    // Helper function printing in alphabetical order
    void printInOrder(BiTreeNode* node) {
        if (node == nullptr) {
            return;
        }

        printInOrder(node->left);
        cout << node->data << endl;
        printInOrder(node->right);
    }

    // Helper function printing in reverse alphabetical order
    void printReverseOrder(BiTreeNode* node) {
        if (node == nullptr) {
            return;
        }

        printReverseOrder(node->right);
        cout << node->data << endl;
        printReverseOrder(node->left);
    }

    // Helper function printing the tree in a tree format
    void printTreeFormat(BiTreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }

        printTreeFormat(node->right, depth + 1);
        cout << string(depth * 4, ' ') << node->data << endl;
        printTreeFormat(node->left, depth + 1);
    }

public:
    BiTree() {
        root = nullptr;
    }

    // Add a new item to the tree
    void add(string val) {
        root = addNode(root, val);
    }

    // Print the contents of the tree in alphabetical order
    void print() {
        cout << "Contents of the tree in alphabetical order:" << endl;
        printInOrder(root);
    }

    // Print the contents of the tree in a tree format
    void TPrint() {
        cout << "Contents of the tree in tree format:" << endl;
        printTreeFormat(root, 0);
    }

    // Print the contents of the tree in reverse alphabetical order
    void RPrint() {
        cout << "Contents of the tree in reverse alphabetical order:" << endl;
        printReverseOrder(root);
    }
};

int main() {
    BiTree tree;

    // Adding website names to the tree
    tree.add("google.com");
    tree.add("facebook.com");
    tree.add("apple.com");
    tree.add("amazon.com");
    tree.add("youtube.com");

    // Printing contents of the tree
    tree.print();
    cout << endl;
    tree.TPrint();
    cout << endl;
    tree.RPrint();

    return 0;
}
