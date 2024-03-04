#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;
    node(int d){
        data = d;
        right = left = NULL;
    }
};

node* build_tree() {
    int d;
    cin >> d;
    if (d == -1) {
        return NULL;
    }
    node* n = new node(d);
    n->left = build_tree();
    n->right = build_tree();
    return n;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}

int diameter(node* root, int& height){
    int lh = 0;
    int rh = 0;
    int ld = 0;
    int rd = 0;

    if(root == NULL){
        height = 0;
        return 0;
    }
    ld = diameter(root->left, lh);
    rd = diameter(root->right, rh);
    height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ld, rd))-1;
}

int main(){
    node* root = build_tree();
    int height = 0;
    cout << diameter(root, height);
}

