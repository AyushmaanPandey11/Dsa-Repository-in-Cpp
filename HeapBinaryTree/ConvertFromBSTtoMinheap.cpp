#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorderTraversal(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

Node* BSTtoMinHeap(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    vector<int> ans;
    inorderTraversal(root, ans);
    Node* anshead = new Node(-1); // Create a dummy node for the head
    Node* current = anshead;
    int index = 0;

    // Construct the min heap using the elements from the inorder traversal
    while (index < ans.size()) {
        Node* newNode = new Node(ans[index]);
        current->right = newNode;
        current = newNode;
        index++;
    }

    return anshead->right; // Return the actual root of the min heap
}

void printPreorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Create a sample BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Given BST Structure:" << endl;
    // Print the original BST
    printPreorder(root);
    cout << endl;

    Node* minHeapRoot = BSTtoMinHeap(root);

    cout << "\nMin Heap Preorder Traversal:" << endl;
    // Print the pre-order traversal of the min heap
    printPreorder(minHeapRoot);
    cout << endl;

    return 0;
}
