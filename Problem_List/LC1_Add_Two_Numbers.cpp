#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution
{
private:
    /* data */
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int sum=0,carry=0;
        ListNode* dummy=new ListNode(0);  
        ListNode* current=dummy;
        
        while(l1!=nullptr||l2!=nullptr||carry){
            sum=carry;
             if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }


            carry=sum/10;

            current->next=new ListNode(sum%10);
           

            current=current->next;

        }
        return dummy->next;

        
    };
};







// Utility function to create a linked list from an array
ListNode* createLinkedListFromArray(int arr[], int n) {
    ListNode* head = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        newNode->next = head;
        head = newNode;
    }

    return head;
}


// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}





int main(){
    int arr1[]={2,4,3};
    int arr2[]={5,6,4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* l1=createLinkedListFromArray(arr1,n1);
    ListNode* l2=createLinkedListFromArray(arr2,n2);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1,l2);


    std::cout << "List 1: ";
    printLinkedList(l1);

    std::cout << "List 2: ";
    printLinkedList(l2);

    std::cout << "Sum: ";
    printLinkedList(result);
    

    // Clean up
    ListNode* temp;
    while (l1) {
        temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2) {
        temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result) {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;





};