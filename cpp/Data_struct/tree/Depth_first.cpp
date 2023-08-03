 #include<iostream>
 #include<queue>
 using namespace std;
 struct Node
 {
    int data;
    Node* left;
    Node* right;
 };
Node* GetNewNode(int data){
    Node* newNode= new Node();
    newNode->data=data;
    newNode->left=newNode->right=nullptr;
    return newNode; 
}

void Preorder(Node* root){
    if(root==nullptr) return;
    printf("%d ", root->data);
    cout<<endl;
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root){
    if(root==nullptr) return;
    
    Inorder(root->left);
    printf("%d ", root->data);
    cout<<endl;
    Inorder(root->right);
    
}

void PosorderNode* root){
    if(root==nullptr) return;
    
    Posorder(root->left);
    Posorder(root->right);
    printf("%d ", root->data);
    cout<<endl;
}




Node* Insert(Node* root, int data)
{
    if(root==nullptr) return root=GetNewNode(data);
    else if(data<=root->data) root->left=Insert(root->left,data);
    else root->right = Insert(root->right, data);
    return root;
}
 int main()
 {

    Node* root;//pointer to root node
    root=nullptr;//setting the tree as the empty
    root=Insert(root, 15);
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 25);
    root=Insert(root, 8);
    root=Insert(root, 12);

    Preorder(root);
    return  0;
 };