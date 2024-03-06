#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node*right;
		node*left;
		node(int d){
			data=d;
			right=left=NULL;
		}
};

node* build(node*root,int a){
	if(root==NULL){
		return new node(a);
	}
	if( a< root->data){
		root->left=build(root->left,a);
	}
	else{
		root->right=build(root->right,a);
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
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		root= build(root,a[i]);
	}
	print_inorder(root);
}
