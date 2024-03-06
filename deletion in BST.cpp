#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node*right;
	node*left;
	node(int d){
		data=d;
		right=NULL;
		left=NULL;
	}
};

node*build(node*root,int a){
	if(root==NULL){
		return new node(a);
	}
	if(a< root->data){
		root->left=build(root->left,a);
	}
	if(a> root->data){
		root->right=build(root->right,a);
	}
	return root;
}

node* find_min(node*root){
	while(root->left){
		root=root->left;
	}
	return root;
}
node*remove(node*root,int a){
	if(root==NULL){
		return NULL;
	}
	else if(a<root->data){
		root->left=remove(root->left,a);
	}
	else if(a> root->data){
		root->right=remove(root->right,a);
	}
	else{
		if(root->left==NULL and root->right==NULL){
			delete root;
			root=NULL;
		}
		else if(root->left){
			node*temp=root;
			root=root->left;
			delete temp;
		}
		else if(root->right){
			node*temp=root;
			root=root->right;
			delete temp;
		}
		else{
			node*temp=find_min(root->right);
			root->data=temp->data;
			root->right=remove(root->right,root->data);
		}
	}
	return root;
}

void print_inorder(node*root){
	if(root==NULL){
		return;
	}
	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
}


int main(){
	node*root=NULL;
	
	int n;
	cout<<" enter the no of elements in a bst"<<endl;
	cin>>n;
	int a[n];
	cout<<" enter the elements in bst"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		root=build(root,a[i]);
	}
	int k;
	cout<<" enter the element to be removed"<<endl;
	cin>>k;
	remove(root,k);
	print_inorder(root);
}
