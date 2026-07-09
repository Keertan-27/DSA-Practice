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

bool isPalindrome(Node *head)
{
    Node *temp = head;
    stack<int> st;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->data != st.top())
            return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}

Node *reverseNode(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool isPlaindromeOptimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    return true;
    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseNode(slow->next);
    Node *left = head;
    Node *right = newHead;

    while (right != nullptr)
    {
        if (left->data != right->data)
        {
            slow->next = reverseNode(newHead);
            return false;
        }
        left = left->next;
        right = right->next;
    }
    slow->next = reverseNode(newHead);
    return true;
    
}
int main()
{
    vector<int> arr = {1,2,3,1,1};
    Node *head = convArrToLL(arr);
    printLL(head);
    if (isPlaindromeOptimal(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}