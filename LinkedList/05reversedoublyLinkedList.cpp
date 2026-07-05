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
// using sack
Node* reverseLinkedList(Node* head)
{
    Node* temp = head;
    stack<int> st;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// using DL property of storing the prev val as well
Node* reverseUsingDLProperty(Node* head)
{
    Node* curr = head;
    Node* temp = NULL;
    while (curr!= nullptr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}
int main()
{
    vector<int> arr = {7,23,8,1,9};
    Node *head = convArrToDDLL(arr);
    printDL(head);
    // Node* rev = reverseLinkedList(head);
    // printDL(rev);

    Node* rev2 = reverseUsingDLProperty(head);
    printDL(rev2);
    return 0;
}