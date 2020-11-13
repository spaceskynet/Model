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
const int maxn=5e3+10,INF=~0U>>1;
namespace fastIO
{
	const int size=1<<15|1,maxl=23;
	char buf[size],*l,*r;
	void getChar(char &c)
	{
		if(l==r) r=(l=buf)+fread(buf,1,size,stdin);
		c=l==r?(char)EOF:*l++;
	}
	template<typename T>inline void read(T &x) 
	{
		char c;x=0;int f=1;
		getChar(c);
		while(c>'9'||c<'0'){if(c=='-') f=-1;getChar(c);}
		while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',getChar(c);
		x*=f;
	}
	template<typename T>inline void put(T x)
	{
		if(!x){putchar('0');return;}
		if(x<0){x=-x;putchar('-');}
		static int out[maxl];
		int len=0;
		while(x){out[++len]=x%10;x/=10;}
		while(len)putchar(out[len--]+'0');
    }
}
int dis[maxn],e[maxn][maxn],n,m;
bool vis[maxn];
void Prim();
int main()
{
//	fr(a);
	fastIO::read(n),fastIO::read(m);
//	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++) e[i][j]=INF;
	mem(e,24);
	for(int i=1,f,t,v;i<=m;i++)
	{
		fastIO::read(f),fastIO::read(t),fastIO::read(v);
		if(e[f][t]>v) e[f][t]=e[t][f]=v;
	}
	Prim();
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void Prim()
{
	mem(vis,0);
//	for(int i=2;i<=n;i++) dis[i]=INF;
	mem(dis,24);
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++) if(!vis[j]&&dis[j]<dis[k]) k=j;
		vis[k]=true;
		for(int j=1;j<=n;j++) if(!vis[j]&&e[k][j]<dis[j]) dis[j]=e[k][j];
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=dis[i];
	fastIO::put(ans),putchar('\n');
}
