#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define ll long long int
ll MAX=1000000009;

struct compare
{
	bool operator()(const pair<ll,ll> l,const pair<ll,ll> r)
	{
		return l.second>r.second;
	}
};
vector< pair<ll,ll> > v[10001];
priority_queue<pair<ll,ll>, vector< pair<ll,ll> >, compare> pq;
ll d[10001]={0};
bool sl[10001]={0};

void prims(ll src,ll n)
{
	ll p,i,dis;
	for(i=1;i<=n;i++)
	{
		d[i]=MAX;
	}
	d[1]=0;
	pq.push(make_pair(src,0));
	while(!pq.empty())
	{
		p=pq.top().first;
		pq.pop();
		sl[p]=1;
		for(i=0;i<v[p].size();i++)
		{
			dis=v[p][i].second;
			if(!sl[v[p][i].first]&&d[v[p][i].first]>dis)
			{
				d[v[p][i].first]=v[p][i].second;
				pq.push(make_pair(v[p][i].first,dis));
			}
		}
	}
}
int main()
{
	ll n,e,i,x,y,w;
	sf("%lld %lld",&n,&e);
	for(i=0;i<e;i++)
	{
		sf("%lld %lld %lld",&x,&y,&w);
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	prims(1,n);
	for(i=1;i<=n;i++)
	{
		pf("%lld %lld\n",i,d[i]);
	}
	return 0;
}