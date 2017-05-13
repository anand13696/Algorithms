#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf

struct compare
{
	bool operator()(const ll& l,const ll& r)
	{
		return l>r;
	}
};
std::vector<ll> v[100001];
priority_queue<ll,vector<ll>,compare> q;
queue<ll> sl;
ll indegree[100001]={0};

void toposort(ll n)
{
	ll p,i,cnt=0;
	while(!q.empty())
	{
		p=q.top();
		q.pop();
		sl.push(p);
		cnt++;
		for(i=0;i<v[p].size();i++)
		{
			if(--indegree[v[p][i]]==0)
			{
				q.push(v[p][i]);
			}
		}
	}
	if(cnt!=n)
	{
		pf("Sandro fails.");
	}
	else
	{
		while(!sl.empty())
		{
			pf("%lld ",sl.front());
			sl.pop();
		}
	}
}
int main()
{
	ll n,e,i,x,y,flag=0;
	sf("%lld %lld",&n,&e);
	for(i=0;i<e;i++)
	{
		sf("%lld %lld",&x,&y);
		v[x].push_back(y);
		indegree[y]++;
		if(x==y)
			flag=1;
	}
	for(i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	if(q.empty())
	{
		flag=1;
	}
	if(flag==1)
	{
		pf("Sandro fails.");
	}
	else
	{
		toposort(n);
	}
	return 0;
}