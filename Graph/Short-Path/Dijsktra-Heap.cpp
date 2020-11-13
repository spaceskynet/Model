#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<queue>
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int maxn=5e3+10,maxm=2e4+10;
const ll INF=~0ULL>>1;
struct hq
{
	int to;
	ll Dis;
	hq(){}
	hq(int to,ll Dis):to(to),Dis(Dis){}
	bool operator < (const hq &x) const{
		return Dis>x.Dis;
	}
};
struct edge
{
	int to,next,val;
	edge(){}
	edge(int to,int next,int val):to(to),next(next),val(val){}
}e[maxm<<1];
priority_queue<hq> q;
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
int pre[maxn],tot=0,n,m,S,T;
ll dis[maxn];
bool vis[maxn];
void add(int,int,int);
void Dijsktra(int);
int main()
{
//	fr(a);
	mem(pre,-1);
	fastIO::read(n),fastIO::read(m),fastIO::read(S),fastIO::read(T);
	for(int i=1,f,t,val;i<=m;i++)
	{
		fastIO::read(f),fastIO::read(t),fastIO::read(val);
		add(f,t,val),add(t,f,val);
	}
	Dijsktra(S);
	fastIO::put(dis[T]);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to,int val)
{
	e[++tot]=edge(to,pre[from],val);pre[from]=tot;
}
void Dijsktra(int s)
{
	for(int i=0;i<=n;i++) dis[i]=INF;mem(vis,0);
	dis[s]=0,q.push(hq(s,dis[s]));
	while(!q.empty())
	{
		int cur=q.top().to;q.pop();
		if(vis[cur]) continue;vis[cur]=true;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(dis[ito]>dis[cur]+e[i].val)
			{
				dis[ito]=dis[cur]+e[i].val;
				q.push(hq(ito,dis[ito]));
			}
		}
	}
	return;
}
