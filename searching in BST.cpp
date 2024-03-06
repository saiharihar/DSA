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

node*build(node*root,int a){
	if(root==NULL){
		return new node(a);
	}
	if(root->data >a){
		root->left=build(root->left,a);
	}
	else{
		root->right=build(root->right,a);
	}
	return root;
}

bool search(node*root,int key){
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(key< root->data){
		return search(root->left,key);
	}
	if(key>root->data){
		return search(root->right,key);
	}
}
int main(){
	node*root=NULL;
	int n;
	cout<<"no of elements in a tree"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		root=build(root,a[i]);
	}
	cout<<search(root,3);
}
