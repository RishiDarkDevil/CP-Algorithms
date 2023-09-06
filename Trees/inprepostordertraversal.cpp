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

node *buildTree(node *root) {

    int data; cin >> data;
    if (data == -1)
        return NULL;
    
    root = new node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void inOrderTraversal(node *root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node *root) {
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
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

    inOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);

    return 0;
}