#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
Node* head;
Node* GetNewNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    return newNode;
}
void InsertAtHead(int x){
    Node* newNode = GetNewNode(x);
    if(head==nullptr)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

    
}
void InsertAtEnd(int x){
    Node* newNode = GetNewNode(x);
    
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* lastNode = head;
    while(lastNode->next !=nullptr)
    {
        lastNode =lastNode ->next;
    }
        lastNode->next=newNode;
        newNode->prev=lastNode;
    
    
}
void Print(Node* p)
{
    if(p == nullptr)
    {
        printf("\n");
        return;
    }
    printf("   %d    ",  p->data);
    Print(p->next);

};

void ReservePrint(Node* p)
{
    if(p==nullptr)
    {
        return;
    }
    ReservePrint(p->next);
    printf("   %d    ",  p->data);
}


int main()
{
    head = nullptr;
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);Print(head);ReservePrint(head);
    cout<<endl;
    InsertAtEnd(4);
    InsertAtEnd(5);
    InsertAtEnd(6);Print(head);ReservePrint(head);
    cout<<endl;
    return 0;
}