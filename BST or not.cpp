#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};
bool help(Node*root,int minval,int maxval){
        if(root==NULL){
            return true;
        }
            if(root->key>=maxval || root->key<=minval){
                 return false;
            }
        
        return(help(root->left,minval,root->key)and help(root->right,root->key,maxval));
}



bool isBST(Node * root){
    return help(root,INT_MIN,INT_MAX);
    
}

