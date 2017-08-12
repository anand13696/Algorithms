#include <bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf

bool prime[1000001]={0};

void sieve()
{
	int i,j;
	for(i=1;i<1000001;i++)
	{
		prime[i]=1;
	}
	for(i=2;i<1000;i++)
	{
		if(prime[i]==1)
		{
			for(j=i*i;j<1000001;j+=i)
			{
				prime[j]=0;
			}
		}
	}
}
int main()
{
	int n,t;
	sf("%d",&t);
	sieve();
	while(t--)
	{
		sf("%d",&n);
		if(prime[n])
			pf("Prime\n");
		else
			pf("Not Prime\n");
	}
    return 0;
}
