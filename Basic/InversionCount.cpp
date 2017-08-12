#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
ll *a;

ll merge(ll tmp[],ll l,ll mid,ll r)
{
	ll ls=l,le=mid-1,i,pos=l,cnt=0;
	while(l<=le&&mid<=r)
	{
		if(a[l]<=a[mid])
		{
			tmp[pos]=a[l];
			pos++,l++;
		}
		else
		{
			tmp[pos]=a[mid];
			cnt+=(mid-pos);
			pos++,mid++;
		}
	}
	while(l<=le)
	{
		tmp[pos]=a[l];
		pos++,l++;
	}
	while(mid<=r)
	{
		tmp[pos]=a[mid];
		pos++,mid++;
	}
	for(i=ls;i<=r;i++)
		a[i]=tmp[i];
	return cnt;
}
ll mergeSort(ll tmp[],ll l,ll r)
{
	ll mid=(r+l)/2,cnt=0;
	if(r>l)
	{
		cnt=mergeSort(tmp,l,mid);
		cnt+=mergeSort(tmp,mid+1,r);
		cnt+=merge(tmp,l,mid+1,r);
	}
	return cnt;
}
int main()
{
	ll n,i,t;
	sf("%lld",&t);
	while(t--)
	{
		sf("%lld",&n);
		a=new ll[n+1];
		ll tmp[n+1];
		for(i=0;i<n;i++)
			sf("%lld",&a[i]);
		pf("%lld\n",mergeSort(tmp,0,n-1));
	}
	return 0;
}