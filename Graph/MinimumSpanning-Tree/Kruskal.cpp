//UnionFind+kruskal by:spaceskynet
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
const int maxn=1e5+10,maxm=2e5+10;
struct edge
{
	int from,to,val;
	bool operator < (const edge &a)const{
		return this->val<a.val;
	}
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
	template<typename T>void Read(int count,T &x,...)
	{
		T *tmp=&x;
		while(count--) read(*tmp++);
	}
}
int n,m,fa[maxn];
int Find(int);
int main()
{
//	fr(d);
	fastIO::Read(2,n,m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		fastIO::read(e[i].from),fastIO::read(e[i].to),fastIO::read(e[i].val);
	}
	sort(e+1,e+m+1);
	int step=0;
	ll ans=0;
	for(int i=1;i<=m&&step<n-1;i++)
	{
		int fx=Find(e[i].from),fy=Find(e[i].to);
		if(fx^fy)
		{
			fa[fx]=fy;
			ans+=e[i].val;
			step++;
		}
	}
	if(step<n-1) printf("orz\n");
	else printf("%lld\n",ans);
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
int Find(int x)
{
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
