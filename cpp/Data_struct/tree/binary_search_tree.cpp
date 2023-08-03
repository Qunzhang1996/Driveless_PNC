#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data=data;
    newNode->left = newNode->right = nullptr;
    return newNode;
};
// void Insert(BstNode** rootPtr, int data)
// {
//     if(*rootPtr==nullptr){//empty tree
//         *rootPtr = GetNewNode(data);

//     }
// };
// int main(){
//     BstNode* root;//pointer to root node
//     root=nullptr;//setting the tree as the empty
//     Insert(&root, 15);
//     Insert(&root, 10);
//     Insert(&root, 20);
// }
BstNode* Insert(BstNode* root, int data)
{
    if(root==nullptr){//empty tree
        root = GetNewNode(data);
    }else if(data<=root->data){
        root->left = Insert(root->left, data);
    }else{
        root->right = Insert(root->right, data);
    }return root;
};
bool Search(BstNode* root, int data){
    if(root==nullptr) return false;
    else if(root->data == data)  return true;
    else if(data<=root->data) return Search(root->left, data);
    else return Search(root->right, data);
};
void FindMin(BstNode* root){
    if(root==nullptr)
    {
        cout<<"Error: Tree is empty\n";
        return;
    }
    BstNode* temp=root;
    while (temp->left!=nullptr)
    {
        temp=temp->left;
    }
    cout<<"The least value:  "<<endl;
    cout<<temp->data<<endl;
    
};
int FindHeight(BstNode* root){
    if(root==nullptr)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right))+1;
}


int main(){
    BstNode* root;//pointer to root node
    root=nullptr;//setting the tree as the empty
    root=Insert(root, 15);
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 25);
    root=Insert(root, 8);
    root=Insert(root, 12);
    FindMin(root);
    int H=FindHeight(root);
    cout<<"Height of the tree is :  "<<H<<endl;

}