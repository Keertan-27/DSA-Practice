#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    Node(int val, Node *next1)
    {
        data = val;
        next = next1;
    }
};

Node *convArrToLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* delNthNodeFromLast(Node* head, int N)
{
    Node* temp = head;
    int len = 0;
    while (temp!= nullptr)
    {
        len++;
        temp = temp->next;
    }
    
    if (len == N)
    {
        Node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
    temp = head;
    for (int i = 1; i < len-N; i++)
    {
        temp = temp->next;
    }
    
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

Node* delNthNodeFromLastOptimal(Node* head, int N)
{
    Node* slow = head;
    Node* fast = head;

    for (int i = 0; i < N; i++)
    {   
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        return head->next;
    }
    
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convArrToLL(arr);
    printLL(head);
    Node* ans = delNthNodeFromLast(head, 5);
    printLL(ans);
}