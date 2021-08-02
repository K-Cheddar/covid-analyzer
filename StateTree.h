#pragma once
#include "Node.h"

using namespace std;

// TreeNode struct that is an extension of Node struct with 2 additional TreeNode pointers, left and right.
struct TreeNode : Node {
    TreeNode* left;
    TreeNode* right;

    TreeNode (string state, const string& confirmed, const string& deaths, string incidentRate);

};

class StateTree {
private:
    // Tree's root
    TreeNode * root;

    void privateInsert(TreeNode* currentNode, TreeNode * newNode);

    Node * privateSearch(TreeNode * currentNode, const string& state);

    void privatePrintAll(TreeNode * currentNode);

public:
    void insert(TreeNode * node);
    Node search(const string& state);
    void printAll();
};