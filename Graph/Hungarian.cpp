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
const int maxn=2e3+10,maxm=1e6+10;
struct edge
{
	int to,next;
	edge(){}
	edge(int to,int next):to(to),next(next){}
}e[maxm];
namespace fastIO
{
	const int size=1<<15|1;
	char buf[size],*l,*r;
	void getChar(char &c)
	{
		if(l==r) r=(l=buf)+fread(buf,1,size,stdin);
		c=l==r?(char)EOF:*l++;
	}
	template<typename T>void read(T &x)
	{
		x=0;int f=1;
		char c;getChar(c);
		while(c<'0'||c>'9'){if(c=='-') f=-1;getChar(c);}
		while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',getChar(c);//c<='9' !"="
		x*=f;
	}
}
int match[maxn],pre[maxn],tot=0,n,m,k;
bool vis[maxn];
void add(int,int);
void Hungarian();
bool dfs(int);
int main()
{
//	fr();
	fastIO::read(n),fastIO::read(m),fastIO::read(k);
	mem(pre,-1),mem(match,0);
	for(int i=1,f,t;i<=k;i++)
	{
		fastIO::read(f),fastIO::read(t);
		if(f>n||t>m) continue;
		add(f,t);
	}
	Hungarian();
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to)
{
	e[++tot]=edge(to,pre[from]);pre[from]=tot;
}
void Hungarian()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		mem(vis,0);
		ans+=dfs(i);
	}
	printf("%d\n",ans);
}
bool dfs(int s)
{
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(vis[ito]) continue;
		vis[ito]=true;
		if(!match[ito]||dfs(match[ito])){match[ito]=s;return true;}
	}
	return false;
}