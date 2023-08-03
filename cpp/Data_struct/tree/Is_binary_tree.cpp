#include <iostream>
#include <climits>

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

BstNode* Insert(BstNode* root, int data) {
    if (root == nullptr) {
        root = new BstNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

void inOrderTraversal(BstNode* node) {
    if (node == nullptr)
        return;

    inOrderTraversal(node->left);
    std::cout << node->data << " ";
    inOrderTraversal(node->right);
}

bool isBSTUtil(BstNode* node, int min_value, int max_value) {
    if (node == nullptr)
        return true;

    if (node->data <= min_value || node->data >= max_value)
        return false;

    return isBSTUtil(node->left, min_value, node->data) &&
           isBSTUtil(node->right, node->data, max_value);
}

bool isBST(BstNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
void postOrderCleanup(BstNode* node) {
    if (node == nullptr)
        return;

    postOrderCleanup(node->left);
    postOrderCleanup(node->right);

    delete node;
}
int main() {
    int values[] = {4, 2, 5, 1, 3};
    int n = sizeof(values) / sizeof(values[0]);

    BstNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = Insert(root, values[i]);
    }

    // Perform in-order traversal to verify the tree
    std::cout << "In-order traversal of the binary search tree: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Check if the tree is a binary search tree
    if (isBST(root)) {
        std::cout << "The tree is a binary search tree.\n";
    } else {
        std::cout << "The tree is not a binary search tree.\n";
    }

    // Clean up memory
    postOrderCleanup(root);

    return 0;
}
