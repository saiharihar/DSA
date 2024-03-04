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
node*build_tree(){
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
int height_of_tree(node*root){
	if(root==NULL){
		return 0;
	}
	int h1= height_of_tree(root->left);
	int h2=height_of_tree(root->right);
	return max(h1,h2)+1;
}
int main(){
	node*root= build_tree();
	cout<<height_of_tree(root);
}
