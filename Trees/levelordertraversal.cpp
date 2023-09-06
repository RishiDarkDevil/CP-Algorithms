#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class node {
    
    public:
        int data;
        node *left;
        node *right;

    node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root) {

    int data; cin >> data;

    if (data == -1)
        return NULL;

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root) {

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
            continue;
        }

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);
        
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    node *root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    return 0;
}