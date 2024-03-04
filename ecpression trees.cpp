#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	string data;
	node*right;
	node*left;
	node(string d){
		data=d;
		right=left=NULL;
	}
};
void build_tree(){
	string d;
	cin>>d;
	if(d=="-1"){
		return;
	}
	node*root=new node(d);
	root>left=build_tree();
	root->right=build_tree();
	return root;
}
int toint(string s){
	int num=0;
	if(s[0]!="-"){
		 for(int i=0;i<s.size();i++){
		 	num=num*10+ (int(s[i])-48);
		 }
	}
	else{
		for(int i=1;i<s.size();i++){
		 	num=num*10+ (int(s[i])-48);
		 }
		 num=num*-1;
	}
	return num;
}

int eval(node*root){
	if(root==NULL){
		return 0;
	}
	if(!root->left && !root->right){
		return toint(root->data);
	}
	int l,r;
	l=eval(root->left);
	r=eval(root->right);
	if(root->data=="+"){
		return l+r;
	}
	if(root->key=="-"){
        return l-r;
    }
    if(root->key=="*"){
        return l*r;
    }
    return l/r;
}

int main(){
	node*root=build_tree();
	cout<<eval(root);
}

