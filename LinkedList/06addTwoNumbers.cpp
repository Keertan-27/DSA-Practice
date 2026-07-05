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
Node *convArrToDDLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printDL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *temp1 = l1;
    Node *temp2 = l2;
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    int carry = 0;
    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if (temp1 != nullptr)
            sum = sum + temp1->data;
        if (temp2 != nullptr)
            sum = sum + temp2->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if (temp1 != nullptr)
            temp1 = temp1->next;
        if (temp2 != nullptr)
            temp2 = temp2->next;
    }

    if (carry != 0)
    {
        Node* carryNode = new Node(carry);
        curr->next = carryNode;
        curr = curr->next;
    }
    

    return dummy->next;
}
int main()
{
    vector<int> arr1 = {9,9,9,9,9,9,9};
    vector<int> arr2 = {9,9,9,9};
    Node *l1 = convArrToDDLL(arr1);
    Node *l2 = convArrToDDLL(arr2);
    cout<<"List l1: ";
    printDL(l1);
    cout<<"List l2: ";
    printDL(l2);

    Node *ans = addTwoNumbers(l1, l2);
    cout<<"Sum of them: ";
    printDL(ans);
}