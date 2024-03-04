#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node*left;
	node*right;
	node(int d){
		data=d;
		left=right=NULL;
	}
};

node* build_tree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node*n=new node(d);
	n->left=build_tree();
	n->right=build_tree();
	return n;
}

void printkthlevel(node*root,int k,int level){
	if(root==NULL){
		return;
	}
	printkthlevel(root->left,k,level+1);
	printkthlevel(root->right,k,level+1);
	if(k==level){
		cout<<root->data<<" ";
	}	
}
int main(){
	cout<<" enter the elements in a tree"<<" ";
	node*root= build_tree();
	int k;
	cout<<"enter the kth level"<<endl;
	cin>>k;
	printkthlevel(root,k,1);
}

