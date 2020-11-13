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
typedef double db;
const int maxn=1e5+10,maxm=2e5+10;
typedef int INT[maxn];
struct edge
{
	int to,next;
	edge(){}
	edge(int to,int next):to(to),next(next){}
}e[maxm],E[maxn];
INT pre,low,dfn,stack,sccno,in,sz,Pre;
bool ins[maxn];
int tot=0,top=0,n,m,sccCnt=0,dfsClock=0,Tot=0;
int read();
void findScc();
void makeScc();
void add(int,int,edge*,int*,int&);
void dfs(int);
void rebuild();
int main()
{
//	fr();
	mem(pre,-1),mem(Pre,-1);
	n=read(),m=read();
	for(int i=1,f,t;i<=m;i++)
	{
		f=read(),t=read();
		add(f,t,e,pre,tot);
	}
	findScc();
	rebuild();
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
void add(int from,int to,edge *e,int pre*,int &tot)
{
	e[++tot]=edge(to,pre[from]);pre[from]=tot;
}
void findScc()
{
	dfsClock=sccCnt=0;
	mem(low,0),mem(sccno,0),mem(dfn,0),mem(ins,0),mem(stack,0),top=0;
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
}
void dfs(int s)
{
	dfn[s]=low[s]=++dfsClock;
	ins[stack[++top]=s]=true;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(!dfn[ito]) dfs(ito),low[s]=min(low[s],low[ito]);
		else if(ins[ito]) low[s]=min(dfn[ito],low[s]);
	}
	if(low[s]^dfn[s]) return;
	sccCnt++;
	while(true)
	{
		int x=stack[top--];
		ins[x]=false;
		sccno[x]=sccCnt;
		if(x==s) break;
	}
}
void rebuild()
{
	for(int cur=1;cur<=n;cur++)
	{
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(sccno[cur]^sccno[ito]) add(sccno[cur],sccno[ito],E,Pre,Tot);
		}
	}
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}