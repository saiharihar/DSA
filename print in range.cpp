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

void print_inrange(node*root,int k1,int k2){
	if(root==NULL){
		return;
	}
	if(root->data>=k1 and root->data<=k2){
		print_inrange(root->left,k1,k2);
		cout<<root->data<<" ";
		print_inrange(root->right,k1,k2);
	}
	 else if(root->data>k2){
		print_inrange(root->left,k1,k2);
	}
	else if(root->data<k1){
		print_inrange(root->right,k1,k2);
	}
	
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
	int k1,k2;
	cin>>k1>>k2;
	print_inorder(root);
	cout<<endl;
	print_inrange(root,k1,k2);
}
