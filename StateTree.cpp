#include "StateTree.h"
#include "Node.h"

using namespace std;

TreeNode::TreeNode (string state, string confirmed, string deaths, string incidentRate) //extend Node
: Node(state, confirmed, deaths, incidentRate) {
    left = nullptr;
    right = nullptr;
}

void StateTree::privateInsert(TreeNode *currentNode, TreeNode *newNode)  { // insert node into tree
    if (root == nullptr) { // tree is empty
        root = newNode;
    } else if (newNode -> state < currentNode -> state) { // new value is less than current value
        if (currentNode -> left != nullptr) { // there is a left node
            privateInsert (currentNode -> left, newNode); // recursively check left subtree;
        } else { // no left node
            currentNode -> left = newNode; // insert new node as left child
        }
    }
    else if (newNode -> state > currentNode -> state) {
        if (currentNode -> right != nullptr) { // there is a right node
            privateInsert (currentNode -> right, newNode); // recursively check right subtree
        } else {
            currentNode -> right = newNode; // insert new node as right child
        }
    }
    // if it reaches this far, it's a duplicate and won't be added
}

void StateTree::insert(TreeNode * node) {
    privateInsert(root, node);
}

Node * StateTree::privateSearch(TreeNode * currentNode, const string& state) { // search by state

    if (currentNode == nullptr || currentNode -> state == state) { // base case
        return currentNode;
    }

    if (state < currentNode -> state) { // requested state comes before the current node
        return privateSearch(currentNode -> left, state);
    }

    // requested state comes after the current node
    return privateSearch(currentNode -> right, state);
}

Node StateTree::search(const string& state) {
    return *privateSearch(root, state);
}

void StateTree::privatePrintAll(TreeNode * currentNode) {
    if (currentNode == nullptr) return;
    currentNode -> printNode(); // print current node
    if (currentNode -> left != nullptr)
        privatePrintAll(currentNode -> left); // print left node
    if (currentNode -> right != nullptr)
        privatePrintAll(currentNode -> right); // print right node
}

void StateTree::printAll(){
    privatePrintAll(root);
}
