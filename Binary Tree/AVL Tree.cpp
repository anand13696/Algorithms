#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pf printf
ll *level,cnt=0;

int input()
{
  int n=0;
  char c=getchar_unlocked();
  while(c<33)
    c=getchar_unlocked();
  while(c>33)
  {
    n=(n<<1)+(n<<3)+(c-'0');
    c=getchar_unlocked();
  }
  return n;
}
struct node
{
	int val,height;
	struct node *left;
	struct node *right;
};
struct node *newNode(int val)
{
	node *n=new node;
	n->val=val;
	n->height=1;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
int h(node *n)
{
	if(n==NULL)
		return 0;
	return n->height;
}
int bf(node *n)
{
	if(n==NULL)
		return 0;
	return h(n->left)-h(n->right);
}
struct node *leftRotate(node *z)
{
	node *y=z->right;
	z->right=y->left;
	y->left=z;
	y->height=max(h(y->left),h(y->right))+1;
	z->height=max(h(z->left),h(z->right))+1;
	return y;
}
struct node *rightRotate(node *z)
{
	node *y=z->left;
	z->left=y->right;
	y->right=z;
	y->height=max(h(y->left),h(y->right))+1;
	z->height=max(h(z->left),h(z->right))+1;
	return y;
}
struct node *insert(node *n,int k)
{
	if(n==NULL)
		return (newNode(k));
	if(k<n->val)
		n->left=insert(n->left,k);
	else
		n->right=insert(n->right,k);
	n->height=max(h(n->left),h(n->right))+1;
	int bal=bf(n);
	if(bal==-2&&k>n->right->val)
		return leftRotate(n);
	if(bal==2&&k<n->left->val)
		return rightRotate(n);
	if(bal==-2&&k<n->right->val)
	{
		n->right=rightRotate(n->right);
		return leftRotate(n);
	}
	if(bal==2&&k>n->left->val)
	{
		n->left=leftRotate(n->left);
		return rightRotate(n);
	}
	return n;
}
void search(node *root,int k)
{
	node *parent=root,*curr=root;
	while(curr->val!=k)
	{	
		if(curr->val<k)
		{
			parent=curr;
			curr=curr->right;
		}
		else
		{
			parent=curr;
			curr=curr->left;
		}
	}
	level[k]=level[parent->val]+1;
}
int main()
{
	int n,i,k;
	n=input();
	level=new ll[n+1];
	node *root=NULL;
	for(i=0;i<n;i++)
	{
		k=input();
		root=insert(root,k);
		if(i==0)
			level[k]=1;
		else
			search(root,k);
		cnt+=(level[k]-1);
		pf("%lld\n",cnt);
	}
	return 0;
}