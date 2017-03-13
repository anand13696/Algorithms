#include<bits/stdc++.h>
using namespace std;
vector <int> v[100];
bool visited[100]={false};
queue <int> q;

void bfs(int s,int n)
{
	int i,j;
	for(j=1;j<=n;j++){
		if(visited[j]==false){
			q.push(j);
			visited[j]=true;
		}
		while(!q.empty()) {
			int p=q.front();
			cout << p << " ";
			q.pop();
		for(i=0;i<v[p].size();i++) {
			if(visited[v[p][i]]==false) {
				q.push(v[p][i]);
				//cout << v[p][i];
				visited[v[p][i]]=true;
			}
		}
	}
	}
}
int main()
{
	int n,i,t,x,y,e;
	cin >> n >> e;
	for(i=0;i<e;i++) {
		cin >> x >> y;
		if(x<=n && y<=n){
		v[x].push_back(y);
		v[y].push_back(x);
		}
		else{
			cout << "Error\n";
			break;
		}
	}
	q.push(1);
	visited[1]=true;
	bfs(1,n);
}