#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
int main()
{
//	fr();
	
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
ll fp(ll I,ll times)
{
	ll ret=1;
	while(times)
	{
		if(times&1) ret=1ll*ret*I%p;
		times>>=1,I=I*I%p;
	}
	return ret;
}
ll C(ll n,ll m)
{
	if(m>n) return 0;
	ll ret=1;
	for(int i=1;i<=m;i++)
	{
		ll a=(n+i-m)%p,b=i%p;
		ret=ret*(a*fp(b,p-2)%p)%p;
	}
	return ret;
}
ll Lucas(ll n,ll m)
{
	if(m==0) return 1;
	else return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}
void Fac(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
}
ll Lucas(ll n,ll m)
{
	ll ret=1;
	while(n&&m)
	{
		ll a=n%p,b=m%p;
		if(a<b) return 0;
		ret=ret*fac[a]*fp(fac[b]*fac[a-b],p-2)%p;
		n/=p,m/=p;
	}
	return ret;
}