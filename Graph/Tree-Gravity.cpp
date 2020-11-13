#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=5e4+10,INF=~0U>>1;
struct edge
{	
	int to,next;
	edge(){}
	edge(int to,int next):to(to),next(next){}
}e[maxn<<1];
int pre[maxn],sz[maxn],ans[maxn],tot=0,cnt=0,n,size;
bool vis[maxn];
void add(int,int);
void dfs(int);
int main()
{
	cls(pre,-1),cls(vis,0),cls(sz,0);
	size=INF;
	scanf("%d",&n);
	for(int i=2;i<=n;i+=1)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		add(f,t),add(t,f);
	}
	dfs(1);
	sort(ans,ans+cnt);
	for(int i=0;i<cnt;i++) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}
void add(int from,int to)
{
	e[++tot]=edge(to,pre[from]);pre[from]=tot;
}
void dfs(int s)
{
	sz[s]=1;
	vis[s]=true;
	int tmp=0;
	for(int i=pre[s];~i;i=e[i].next)
	{
		int ito=e[i].to;
		if(vis[ito]) continue;
		vis[ito]=true;
		dfs(ito);
		sz[s]+=sz[ito];
		tmp=max(tmp,sz[ito]);
	}
	tmp=max(tmp,n-sz[s]);
	if(tmp<size)
	{
		cnt=0;
		ans[cnt++]=s;
		size=tmp;
	}
	else if(tmp==size) ans[cnt++]=s;
}