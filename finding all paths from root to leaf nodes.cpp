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

node*build(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node*n=new node(d);
	n->left =build();
	n->right=build();
	return n;
}

void root_to_leaf_paths(node*root,vector<int> &path){
	if(root==NULL){
		return;
	}
	if(root->left==NULL and root->right==NULL){
		for(int i=0;i< path.size();i++){
			cout<<path[i]<<"->";
		}
		cout<<root->data<<"->";
		cout<<endl;
		return;
	}
	path.push_back(root->data);
	root_to_leaf_paths(root->left,path);
	root_to_leaf_paths(root->right,path);
	path.pop_back();
}

int main(){
	node*root=NULL;
	cout<<" enter the elements in the tree"<<endl;
	root=build();
	vector<int>v;
	root_to_leaf_paths(root,v);
}
