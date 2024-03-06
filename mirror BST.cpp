Node* mirrorBST(Node * root){
    if(root==NULL){
        return NULL;
    }
    Node*temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorBST(root->left);
    mirrorBST(root->right);
    
    return root;
}
