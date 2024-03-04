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
node* level_orderbuild(){
	int d;
	cin>>d;
	node*root=new node(d);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node*temp=q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			temp->left=new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right=new node(c2);
			q.push(temp->right);
		}
	}
	return root;
}
void levelorder_print(node*root){
	queue <node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node*temp= q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return;
}

int main(){
	node*root=level_orderbuild();
	levelorder_print(root);
}
