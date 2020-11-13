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
const int maxn=1e2+10,INF=~0U>>3;
namespace fastIO
{
	template<typename T>inline void read(T &x) 
	{
		char c;x=0;int f=1;
		c=getchar();
		while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
		while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
		x*=f;
	}
}
int dis[maxn][maxn],e[maxn][maxn],n,m;
void Floyed();
int main()
{
//	fr();
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++) dis[i][j]=e[i][j]=INF;
		for(int i=1,f,t,v;i<=m;i++)
		{
			fastIO::read(f),fastIO::read(t),fastIO::read(v);
			if(e[f][t]>v) e[f][t]=e[t][f]=dis[f][t]=dis[t][f]=v;
		}
		Floyed();
	}
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void Floyed()
{
	int mi=INF;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=1;j<i;j++)
			{
				mi=min(mi,dis[i][j]+e[i][k]+e[k][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	if(mi<INF) printf("%d\n",mi);
	else puts("No solution.");
}