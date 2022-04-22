#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;
typedef struct Node{
	Node *lchild,*rchild,*parent;
	char weight;
}Node;
void CreatTree(Node* &root,Node* p){
	root=new Node;
	char c;
	c=getchar();
	getchar();
	if(c=='*')
	{
		root->weight='*';
		root->parent=p;
		return;
	}
	root->parent=p;
	root->weight=c;
	CreatTree(root->lchild,root);
	CreatTree(root->rchild,root);
}
void FOParent(Node* root,char x1,Node* &p){
	if(root->weight=='*')
		return;
	if(root->weight==x1)
	{
		p=root->parent;
		return;
	}
	FOParent(root->lchild,x1,p);
	FOParent(root->rchild,x1,p);
}
int main(){
	char x1,x2;
Node *p,*root,*p1,*p2,*head;
p=p1=p2=root=NULL;
CreatTree(root,p);
cin>>x1>>x2;
if(root->weight==x1||root->weight==x2)
	cout<<"null";
else
{
FOParent(root,x1,p1);
FOParent(root,x2,p2);
if(p1==NULL||p2==NULL)
{
	cout<<"null";
	return 0;
}
head=p2;
while(p1)
{
	while(p2)
	{
		if(p1==p2)
		{
			cout<<p1->weight;
			return 0;
		}
		p2=p2->parent;
	}
	p1=p1->parent;
	p2=head;
}
}
system("pause");
return 0;
}

