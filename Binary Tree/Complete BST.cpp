#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
int *parent,*tree,n;

void findRoot(int l,int r,int i)
{
	if(l==r)
	{
		tree[i]=l;
		if(i==0)
			parent[l]=-1;
		else if(i%2!=0)
			parent[l]=tree[((i-1)/2)];
		else
			parent[l]=tree[((i-2)/2)];
	}
	if(r>l&&i<n)
	{
		int h,max,maxnodes,root,tn=(r-l+1);
		h=floor(log2 (r-l+1));
		maxnodes=pow(2,(h+1));
		max=maxnodes/2;
		if(maxnodes-1>tn)
		{
			root=((max)/2)+(tn+1-max)+(l-1);
			if(root>((maxnodes/2)+(l-1)))
				root=(maxnodes/2)+(l-1);
		}
		else
			root=((tn+1)/2)+(l-1);
		tree[i]=root;
		if(i==0)
			parent[root]=-1;
		else if(i%2!=0)
			parent[root]=tree[((i-1)/2)];
		else
			parent[root]=tree[((i-2)/2)];
		findRoot(l,root-1,2*i+1);
		if(parent[root+1]==0)
			findRoot(root+1,r,2*i+2);
	}
}
int main()
{
	int l,i,j,t;
	sf("%d",&t);
	for(j=1;j<=t;j++)
	{
		sf("%d",&n);
		parent=new int[n+1];
		tree=new int[n+1];
		memset(parent,0,sizeof(parent));
		findRoot(1,n,0);
		for(i=0;i<n;i++)
			cout << tree[i] << " ";
		cout << "\n";
	}
	return 0;
}
/* EXAMPLE if n=17 then output is

10 6 14 4 8 12 16 2 5 7 9 11 13 15 17 1 3
the tree is
				     10
				  /      \
			     6       14
			   /  \     /   \
			  4   8    12    16
			 / \  / \  / \   / \
			2  5  7 9  11 13 15 17
			/\
			1 3