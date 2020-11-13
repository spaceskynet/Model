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
const int mod=1e9+7;
int fp(int,int);
int fm(int,int);
int main()
{
//	fr();
	
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
int fp(int I,int times)
{
	int ret=1;
	while(times)
	{
		if(times&1) ret=1ll*ret*I%mod;
		times>>=1,I=1ll*I*I%mod;
	}
	return ret;
}
int fm(int I,int times)
{
	int ret=0;
	if(I<times) I^=times^=I^=times;
	while(times)
	{
		if(times&1) ret=(1ll*ret+I)%mod;
		times>>=1,I=(1ll*I+I)%mod;
	}
	return ret;
}