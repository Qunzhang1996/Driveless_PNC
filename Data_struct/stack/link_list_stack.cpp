#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* link;
};
Node* top =nullptr;
void Push(int x)
{
    Node* temp =new Node();
    temp->data=x;
    temp->link=top;
    top=temp;
}//push_head
void Pop(){
    Node* temp;
    if(top==nullptr) return;
    temp=top;
    top=top->link;
    delete(temp);
}
void Print(Node* p)
{
    if(p == nullptr)
    {
        printf("\n");
        return;
    }
    printf("   %d    ",  p->data);
    Print(p->link);

};
int main()
{
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Print(top);
    Pop();
    Print(top);
}