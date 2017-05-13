#include<bits/stdc++.h>
using namespace std;

vector <int> v[100];
bool visited[100]={false};
stack <int> s;

void dfs(int src,int n)
{
	int i=src,j;
	while(!s.empty())
	{
		i=s.top();
		for(j=0;j<v[i].size();j++)
		{
			if(visited[v[i][j]]==false)
			{
				s.push(v[i][j]);
				visited[v[i][j]]=true;
				cout << v[i][j] << " ";
				break;
			}
		}
		if(j==v[i].size())
			s.pop();
	}
}
int main()
{
	int n,i,t,x,y,e;
	cin >> n >> e;
	for(i=0;i<e;i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	s.push(1);
	visited[1]=true;
	cout << "1 ";
	dfs(1,n);
	return 0;
}
