#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insertNode(Node *root, char val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insertNode(root->left, val);
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    return root;
}

void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = nullptr;
    string s = "welcome";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
        {
            root = insertNode(root, s[i]);
            postorderTraversal(root);
            cout << endl;
        }
    }
    return 0;
}
