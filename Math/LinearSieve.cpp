#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
bool isnp[maxn];
int prime[maxn],phi[maxn],mu[maxn],fac[maxn],d[maxn],totp;
void getp(int);
void getphi(int);
void getmu(int);
void getfac(int);
void getall(int);
ll Phi(ll);
int main()
{
//	fr();
	
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void getp(int n)
{
	isnp[1]=true;totp=0;
	for(int i=2;i<=n;i++)
	{
		if(!isnp[i]) prime[++totp]=i;
		for(int j=1;i*prime[j]<=n&&j<=totp;j++)
		{
			isnp[i*prime[j]]=true;
			if(!(i%prime[j])) break;
		}
	}
}
void getphi(int n)
{
	isnp[1]=true;totp=0;
	for(int i=2;i<=n;i++)
	{
		if(!isnp[i]) prime[++totp]=i,phi[i]=i-1;
		for(int j=1;i*prime[j]<=n&&j<=totp;j++)
		{
			isnp[i*prime[j]]=true;
			if(!(i%prime[j])){phi[i*prime[j]]=phi[i]*prime[j];break;}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
void getmu(int n)
{
	isnp[1]=true,mu[1]=1;totp=0;
	for(int i=2;i<=n;i++)
	{
		if(!isnp[i]) prime[++totp]=i,mu[i]=-1;
		for(int j=1;i*prime[j]<=n&&j<=totp;j++)
		{
			isnp[i*prime[j]]=true;
			if(!(i%prime[j])){mu[i*prime[j]]=0;break;}
			mu[i*prime[j]]=-mu[i];
		}
	}
}
void getfac(int n)
{
	isnp[1]=true,fac[1]=1;totp=0;
	for(int i=2;i<=n;i++)
	{
		if(!isnp[i]) prime[++totp]=i,fac[i]=2,d[i]=1;
		for(int j=1;i*prime[j]<=n&&j<=totp;j++)
		{
			isnp[i*prime[j]]=true;
			if(!(i%prime[j])){fac[i*prime[j]]=fac[i]/(d[i]+1)*(d[i]+2),d[i*prime[j]]=d[i]+1;break;}
			fac[i*prime[j]]=fac[i]*2,d[i*prime[j]]=1;
		}
	}
}
void getall(int n)
{
	isnp[1]=true,mu[1]=1,fac[1]=1;totp=0;
	for(int i=2;i<=n;i++)
	{
		if(!isnp[i]) prime[++totp]=i,phi[i]=i-1,mu[i]=1,fac[i]=2,d[i]=1;
		for(int j=1;i*prime[j]<=n&&j<=totp;j++)
		{
			isnp[i*prime[j]]=true;
			if(!(i%prime[j])){phi[i*prime[j]]=phi[i]*prime[j],mu[i*prime[j]]=0,fac[i*prime[j]]=fac[i]/(d[i]+1)*(d[i]+2),d[i*prime[j]]=d[i]+1;break;}
			phi[i*prime[j]]=phi[i]*(prime[j]-1),mu[i*prime[j]]=-mu[i],fac[i*prime[j]]=fac[i]*2,d[i*prime[j]]=1;
		}
	}
}
ll Phi(ll x)
{
	int m=sqrt(x+0.5);
	ll ret=x;
	for(int i=2;i<=m;i++)
	{
		if(x%i==0)
		{
			ret=ret/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ret=ret/x*(x-1);
	return ret;
}