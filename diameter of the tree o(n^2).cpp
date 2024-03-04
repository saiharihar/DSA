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

int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1= height(root->left);
	int h2=height(root->right);
	return max(h1,h2)+1;
}


int  diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int d1= height(root->left)+ height(root->right);
	int d2=diameter(root->left);
	int d3=diameter(root->right);
	
	return max(d1,max(d2,d3));
	
}

int main(){
	node*root =build_tree();
	cout<<diameter(root);
}



