#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void itreativePreorderTrevarsal(Node* root)
{
    if (root == nullptr)    
        return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty())
    {
        Node* current = st.top();
        st.pop();

        cout<< current->data << " ";
        if (current->right)
            st.push(current->right);
        
        if (current->left)
            st.push(current->left);
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

    itreativePreorderTrevarsal(root);
    return 0;
}