#include<iostream>
struct Node
{
    int data;
    Node* next;
};
Node * head;
Node* Reverse(Node * head)
{
    Node *next, *prev, *current;
    current = head;
    prev = nullptr;

    while (current!=nullptr)
    {
        next=current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
    
}
void Insert(int n)
{   

    Node * temp1=new Node();
    temp1->data=n;
    temp1->next=nullptr;
    if (head == nullptr)
    {
        head = temp1;
    }
    else
    {
        Node* temp2 = head;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }

}

void Print()
{
    Node* temp = head;
    while (temp!=nullptr)
    {
        printf("  %d   ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
};
int main()
{
    head = nullptr;
    Insert(2);//list: 2
    Insert(3);//list: 2,3
    Insert(4);//list: 4,2,3
    Insert(5);//list: 4,5,2,3
    Print();
    head=Reverse(head);
    Print();
    return 0;
};