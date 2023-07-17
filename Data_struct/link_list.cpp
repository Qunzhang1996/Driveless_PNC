#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    
};
Node *head;
Node* Insert(Node* head, int x)
{
    Node * temp=new Node;
    temp->data=x;
    temp->next=head;
    head = temp;
    return head;
};
void Print(Node* head)
{
    Node* temp=head;
    printf("list is :  ");
    while (temp != NULL)
    {
        
        printf("%d", temp->data);
        temp=temp->next;
        
    }
    printf("\n");
};
void Delete(Node*& head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main()
{
    Node* head=NULL;
    printf("HOW MANY NUMBERS?\n");
    int n, i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the number \n");
        scanf("%d",&x);
        head = Insert(head,x);
        Print(head);
    }
    Delete(head);
    Print(head);
    return 0;
};