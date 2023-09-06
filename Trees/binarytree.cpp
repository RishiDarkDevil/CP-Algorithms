#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root) {

    int data; cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;
    
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    
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

    root = buildTree(root);

    return 0;
}