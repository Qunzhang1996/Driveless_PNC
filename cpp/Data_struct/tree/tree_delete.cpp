#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr){}
};
Node* Insert(Node* root, int data){
    if(root == nullptr) root = new Node(data);
    else if(data<=root->data) root->left=Insert(root->left, data);
    else root->right=Insert(root->right, data);
    return root;
};
void inOrderTraversal(Node* node) {
    if (node == nullptr)
        return;
    
    inOrderTraversal(node->left);
    std::cout << node->data << " ";
    inOrderTraversal(node->right);
}


Node* FindMin(Node* root){
    if(root==nullptr)
    {
        cout<<"Error: Tree is empty\n";
        return root;
    }
    Node* temp=root;
    while (temp->left!=nullptr)
    {
        temp=temp->left;
    }
    cout<<"The least value:  "<<endl;
    cout<<temp->data<<endl;
    return temp;
    
};
Node* Delete(Node* root, int data)
{
    if(root==nullptr) return root;
    else if (data<root->data)  root->left=Delete(root->left, data);
    else if (data>root->data)  root->right=Delete(root->right, data);
    else{//The data found, to  be deleted!!!!!!!!!!!!!!!!!!!
        if(root->left == nullptr && root->right == nullptr){//Case 1: No child
            delete root;
            root = nullptr;
        }else if(root->left == nullptr)
        {
            Node* temp = root;
            root=root->right;
            delete temp;
        }else if(root->right == nullptr)
        {
            Node* temp = root;
            root=root->left;
            delete temp;
        }else
        {
            Node* temp=FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }       

    }
    return root;
}

int main() {
    int values[] = {4, 2, 5, 1, 3,7,8,9,10};
    int n = sizeof(values) / sizeof(values[0]);

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = Insert(root, values[i]);
    }

    // Perform in-order traversal to verify the tree
    std::cout << "In-order traversal of the binary search tree: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    root = Delete(root, 2);

    std::cout << "In-order traversal of the binary search tree after deletion: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}