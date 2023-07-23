#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int value): data(value),left(nullptr),right(nullptr),parent(nullptr){}
};
Node* Find(Node* root, int data){
    if(root==nullptr) return root;
    else if (root->data == data)  return root;
    else if(data<=root->data) return Find(root->left, data);
    else return Find(root->right, data);
};




Node* FindMin(Node* root){
    if(root == nullptr) return nullptr;
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}



Node* Getsuccessor(Node* root, int data)
{
    Node* current =Find(root, data);
    if(current==nullptr) return nullptr;
    //case 1: Node has right subtree
    if(current->right!=nullptr){
        // Node* temp =current->right;
        // while(temp->left!=nullptr) temp=temp->left;
        // return temp;
        return FindMin(current->right);
    }
    //case2: No right subtree
    else{
        Node* successor = nullptr;
        Node* ancestor = root;
        while(ancestor!=current){
            if(ancestor->data>current->data){
                successor = ancestor;
                ancestor=ancestor->left;
            }else{
                ancestor=ancestor->right;
            }
            
        }
        return successor;
    }
}
Node* Insert(Node* root, int data)
{
    if(root == nullptr) root = new Node(data);
    else if(data<=root->data) root->left=Insert(root->left,data);
    else root->right = Insert(root->right, data);
    return root;
}

int main() {
    Node* root = nullptr;
    int values[] = {4, 2, 5, 1, 3,7,8,9,10};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; ++i) {
        root = Insert(root, values[i]);
    }

    int test_val = 8;
    Node* successor = Getsuccessor(root, test_val);

    if(successor == nullptr)
        cout << "No successor found for the given node.";
    else
        cout << "The in-order successor of " << test_val << " is " << successor->data << "."<<endl;

    return 0;
}
