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

Node *sortZeroOnceTwos(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twosHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twosHead;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (one->data != -1) ? oneHead->next : twosHead->next;
    one->next = twosHead->next;
    two->next = nullptr;

    Node* newNode = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twosHead;

    return newNode;
}
int main()
{
    vector<int> arr = {2, 2, 0, 1, 2, 0, 1};
    Node *head = convArrToLL(arr);
    printLL(head);
    Node *ans = sortZeroOnceTwos(head);
    printLL(ans);
}