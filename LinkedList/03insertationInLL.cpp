#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int val, Node *head)
    {
        data = val;
        next = head;
    }
};

Node *convArrToLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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
Node *insertHead(Node *&head, int val)
{
    Node *temp = new Node(val, head);
    head = temp;
    return head;
}

Node *insertTail(Node *&head, int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return head;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *vlaInsert = new Node(val);
    temp->next = vlaInsert;
    return head;
}

Node *insertKthPosition(Node *&head, int val, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
            return NULL;
        
    }
    if (k==1)
    {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k-1)
        {
            Node* insVal = new Node(val);
            insVal->next = temp->next;
            temp->next = insVal;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertElemBeforVal(Node* &head, int insertVal, int elm)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == elm)
    {
        Node* newVal = new Node(insertVal, head);
        head = newVal;
        return head;
    }
    
    Node* temp = head;
    while (temp!= NULL)
    {
        if (temp->next->data == elm)
        {
            Node* newElm = new Node(insertVal);
            newElm->next = temp->next;
            temp->next = newElm;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 4, 1, 5, 7};
    Node *head = convArrToLL(arr);
    printLL(head);
    insertHead(head, 3);
    printLL(head);
    insertTail(head, 10);
    printLL(head);
    insertKthPosition(head, 12, 1);
    printLL(head);
    insertElemBeforVal(head, 8, 4);
    printLL(head);
    return 0;
}