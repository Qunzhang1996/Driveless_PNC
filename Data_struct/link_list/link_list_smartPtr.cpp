#include <iostream>
#include <memory>

struct Node
{
    int data;
    std::unique_ptr<Node> next;
};

std::unique_ptr<Node> head;

void Insert(int x)
{
    auto newNode = std::make_unique<Node>();
    newNode->data = x;
    newNode->next = std::move(head);
    head = std::move(newNode);
}

void Print()
{
    Node* temp = head.get();
    std::cout << "List is: ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next.get();
    }
    std::cout << std::endl;
}

int main()
{
    head = nullptr;
    std::cout << "HOW MANY NUMBERS?" << std::endl;
    int n, x;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> x;
        Insert(x);
        Print();
    }

    head.reset();  // Automatically releases the memory

    return 0;
}
