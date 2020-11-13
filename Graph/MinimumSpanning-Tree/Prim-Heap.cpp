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
const int maxn=5e3+10,maxm=2e5+10,INF=~0U>>1;
struct hq
{
	int to,Dis;
	hq(){}
	hq(int to,int Dis):to(to),Dis(Dis){}
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
priority_queue<hq> q;
int dis[maxn],n,m,tot=0,pre[maxn];
bool vis[maxn];
void add(int,int,int);
void Prim_Heap(int);
int main()
{
//	fr(t);
	fastIO::read(n),fastIO::read(m);
	mem(pre,-1),mem(vis,0);
	for(int i=1,f,t,v;i<=m;i++)
	{
		fastIO::read(f),fastIO::read(t),fastIO::read(v);
		add(f,t,v),add(t,f,v);
	}
	Prim_Heap(1);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to,int val)
{
	e[++tot]=edge(to,pre[from],val);pre[from]=tot;
}
void Prim_Heap(int s)
{
	int tot=0,ans=0;
	fill(dis+1,dis+n+1,INF);
	dis[s]=0;
	q.push(hq(s,dis[s]));
	while(!q.empty())
	{
		hq Cur=q.top();q.pop();
		int cur=Cur.to,Dis=Cur.Dis;
		if(vis[cur]) continue;
		vis[cur]=true,ans+=Dis,tot++;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(vis[ito]||dis[ito]<=e[i].val) continue;
			dis[ito]=e[i].val;
			q.push(hq(ito,dis[ito]));
		}
	}
	if(tot<n) printf("orz\n");
	else printf("%d\n",ans);
}
