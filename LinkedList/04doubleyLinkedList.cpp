#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val, Node *next1, Node *prev1)
    {
        data = val;
        next = next1;
        prev = prev1;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
Node* convArrToDDLL(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printDL(Node* head){
    Node* temp = head;

    while (temp!= nullptr)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteHead(Node* &head)
{
    if (head == nullptr)
    {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
    return head;
}

Node* deletTail(Node* &head){
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    return head;
}
int main()
{
    vector<int> arr = {2, 4, 6, 1, 8};
    Node* head = convArrToDDLL(arr);
    printDL(head);
    deleteHead(head);
    printDL(head);
    deletTail(head);
    printDL(head);
    return 0;
}