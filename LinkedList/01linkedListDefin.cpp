#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
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
        mover = temp; // mover = mover->next;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool searchInLL(Node* head, int k){
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            return true;
        }
        
        temp = temp->next;
    }
    return false;
}
int main()
{
    vector<int> arr = {12, 1, 3, 5};
    Node *head = convArrToLL(arr);
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << lengthOfLL(head);
    cout<<endl;
    cout<< searchInLL(head, 15);
    return 0;
}