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
const int maxn=1e5+10;
struct edge
{
	int to,next,val;
	edge(){}
	edge(int to,int next,int val):to(to),next(next),val(val){}
}e[maxn<<1];
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
	template<typename T>void Read(int count,T &x,...)
	{
		T *tmp=&x;
		while(count--) read(*tmp++);
	}
}
int pre[maxn],tot=0,n,S,T,ans=-1,fa[maxn];
bool vis[maxn];
void add(int,int,int);
void dfs(int,int,int);
int main()
{
//	fr(a);
	mem(pre,-1);
	fastIO::read(n);
	for(int i=1,f,t,v;i<n;i++)
	{
		fastIO::read(f),fastIO::read(t),fastIO::read(v);
		add(f,t,v),add(t,f,v);
	}
	vis[1]=true,dfs(1,0,0);
	mem(vis,0);
	vis[S]=true,T=S,dfs(S,0,0);
	printf("S:%d T:%d LongestDis:%lld\n",S,T,1ll*ans);
//	printf("%lld\n",1ll*((21+ans)*ans)/2);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void dfs(int s,int dis,int fa)
{
	if(ans<dis) ans=dis,S=s;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(ito==fa||vis[ito]) continue;
		vis[ito]=true;
		dfs(ito,dis+=e[i].val,s);
		vis[ito]=false;
		dfs(ito,dis-=e[i].val,s);
	}
}
void add(int from,int to,int val)
{
	e[++tot]=edge(to,pre[from],val);pre[from]=tot;
}
