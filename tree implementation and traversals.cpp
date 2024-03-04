#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
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

void print_preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(node* root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

void print_postorder(node* root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
}

void levelorder_print(node*root){
	queue <node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node*temp= q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return;
}

int main() {
    node* root = build_tree();
    cout << "Preorder: ";
    print_preorder(root);
    cout << endl;

    cout << "Inorder: ";
    print_inorder(root);
    cout << endl;

    cout << "Postorder: ";
    print_postorder(root);
    cout << endl;
    
    cout<<"level order:"<<endl;
    levelorder_print(root);
    cout<<endl;

    return 0;
}

