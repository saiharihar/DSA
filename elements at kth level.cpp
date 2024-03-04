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

void printKthLevel(node* root, int k) {
    if (root == NULL || k < 0) {
        return;
    }

    if (k == 0) {
        cout << root->data << " ";
    } else {
        printKthLevel(root->left, k - 1);
        printKthLevel(root->right, k - 1);
    }
}

int main(){
	cout<<"enter the elements in a tree"<<endl;
	node*root= build_tree();
	int k;
	cout<<"enter the level"<<endl;
	cin>>k;
	printKthLevel(root,k);
}
