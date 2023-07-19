#include<iostream>

struct Node
{
    int data;
    struct Node* next;
    
};
Node * head;

void Insert(int data, int n)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;
    if (n==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 =head;
    for (int i=0;i<n-2;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;  
    temp2->next = temp1;
};
void Print()
{
    Node* temp = head;
    while (temp!=nullptr)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
};
void Delete(int n)
{
    Node *temp1 = head;
    if (n==1)
    {
        head = temp1->next;
        delete(temp1);
        return;
    }
    
    int i;
    for(int i=0; i<n-2;i++)
    {
        temp1 = temp1->next;
        //temp1 points to (n-1)th node
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete(temp2);
};

int main()
{
    head = nullptr;
    Insert(2,1);
    Insert(4,2);
    Insert(5,3);
    Insert(6,4);
    Print();
    int n;
    printf("Enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();

    return 0; 
}