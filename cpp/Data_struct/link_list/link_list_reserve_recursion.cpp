#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head;
void Insert(int n)
{
    Node* temp = new Node();
    temp->data=n;
    temp->next=nullptr;
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node* temp2 = head;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    
};
void Reverse(Node* p)
{
    if(p->next==nullptr)
    {
        head=p;
        return;
    }
    Reverse(p->next);
    Node* q=p->next;
    q->next = p;
    p->next = nullptr;
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

int main()
{
    head = nullptr;
    Insert(2);//list: 2
    Insert(3);//list: 2,3
    Insert(4);//list: 4,2,3
    Insert(5);//list: 4,5,2,3
    Print(head);
    cout<<"reserve print!"<<endl;
    Reverse(head);
    Print(head);
    cout<<endl;
    return 0;
}