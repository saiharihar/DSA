bool isSymmetric(Node* root) {
        if(root==NULL){
            return true;
        }
        queue<Node*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            Node*l=q.front();
            q.pop();
            Node*r=q.front();
            q.pop();
            if(!l && !r){
                continue;
            }
            if(!l || !r){
                return false;
            }
            if(l->key!=r->key){
                return false;
            }
            q.push(l->left);	
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
}
