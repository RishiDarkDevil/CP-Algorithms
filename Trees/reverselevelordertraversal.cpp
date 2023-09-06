#include <bits/stdc++.h>
#include <vector>
#include <stack>
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

void reverseLevelOrderTraversal (node *root) {

    queue<node *> Q;
    stack<node *> S;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty()) {
        node *temp = Q.front();
        Q.pop();
        S.push(temp);

        if (temp == NULL) {
            if (!Q.empty())
                Q.push(NULL);
            continue;
        }

        if (temp->right)
            Q.push(temp->right);
        if (temp->left)
            Q.push(temp->left);
    }

    S.pop();

    while (!S.empty()) {
        node *temp = S.top();
        S.pop();
        if (temp == NULL) {
            cout << endl;
            continue;
        }
        cout << temp->data << " ";
    }

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

    reverseLevelOrderTraversal(root);

    return 0;
}