#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

void inorder(Node*root,vector<int> &v){
    if(root==NULL){
        return;
    }
    if(root->left){
    inorder(root->left,v);
    }
    v.push_back(root->key);
   if(root->right){
        inorder(root->right,v);
   }
}

Node*help(Node*root){
      if(root==NULL){
          return NULL;
      }
      root->left=help(root->left);
      root->right=help(root->right);
      if((root->left==NULL) && (root->right==NULL)) {
        return root;
      }
      if(root->left==NULL){
          return root->right;
      }
      if(root->right==NULL){
          return root->left;
      }
      
      return root;
      
}

vector<int> removeHalfNodes(Node *root)
{
   root=help(root);
   vector<int>v;
   inorder(root,v);
   return v;
   
}
