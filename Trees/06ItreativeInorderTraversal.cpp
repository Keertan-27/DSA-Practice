#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void itreativeInorderTrevarsal(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (current != nullptr || !st.empty())
    {
        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data<<" ";

        current = current->right;
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    root->right->left = new Node(8);
    root->right->right = new Node(9);

    itreativeInorderTrevarsal(root);
    return 0;
}