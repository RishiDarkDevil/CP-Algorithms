#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
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

int noOfLeafNodes(node *root){
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

node *buildTreeFromLOT(node *root) {

    int data; cin >> data;

    if (data == -1)
        return NULL;

    root = new node(data);

    queue<node *> Q;
    Q.push(root);

    while (!Q.empty()) {
        node *temp = Q.front();
        Q.pop();
        
        int leftData; cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            Q.push(temp->left);
        }

        int rightData; cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            Q.push(temp->right);
        }
    }

    return root;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
    #endif

    node *root = NULL;
    root = buildTreeFromLOT(root);

    cout << noOfLeafNodes(root) << endl;

    return 0;
}