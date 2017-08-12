#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
ll M=1000000009;
struct compare
{
	bool operator()(const pair<ll,ll> l,const pair<ll,ll> r)
	{
		return l.second>r.second;
	}
};
std::vector< pair<ll,ll> > v[500001];
priority_queue<pair<ll,ll>,vector< pair<ll,ll> >,compare> pq;
ll mindis[500001];
ll parent[500001];

void dijkstra(ll src,ll n)
{
	ll p,i,d;
	for(i=1;i<=n;i++){		
		mindis[i]=M;
	}
	pq.push(make_pair(src,0));
	mindis[src]=0;
	while(!pq.empty())
	{
		p=pq.top().first;
		pq.pop();
		for(i=0;i<v[p].size();i++)
		{
			d=mindis[p]+v[p][i].second;
			if(mindis[v[p][i].first]>d)
			{
				mindis[v[p][i].first]=d;
				pq.push(make_pair(v[p][i].first,d));
				parent[v[p][i].first]=p;
			}
		}
	}
}
int main()
{
	ll n,e,q,i,x,y,w,src;
	sf("%lld %lld",&n,&e);
	for(i=0;i<e;i++)
	{
		sf("%lld %lld %lld",&x,&y,&w);
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	sf("%lld",&src);
	dijkstra(src,n);
	for(i=0;i<=n;i++)
	{
		cout << i << " " << parent[i] << " " << mindis[i] << endl;
	}
	return 0;
}