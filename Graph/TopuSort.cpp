//%spaceskynet
#include<iostream>
#include<cstdio>
#include<cstring>
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e6+10;
struct edge
{
	int to,next;
}e[maxn];
int pre[maxn],in[maxn]={0},stack[maxn],s[maxn],top=0,num=0,tot=0,cnt=0;
void add(int,int);
bool Stack();
bool Queue();
int main()
{
	int n,m,l,r,t;
	scanf("%d",&t);
	while(t--)
	{
		num=0;
		cls(pre,-1),cls(in,0);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			add(l,r);
			in[r]++;
		}
		if(Stack()/*Queue()*/) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
void add(int from,int to)
{
	e[++tot].to=to;e[tot].next=pre[from];pre[from]=tot;
}
bool Stack()
{
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) stack[++top]=i;
	}
	while(top>0)
	{
		int cur=stack[top--];
		//next--->printf point
		s[++cnt]=cur;
		/*----------------*/
		in[cur]=-1;
		num++;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(!--in[ito]) stack[++top]=ito;
		}
	}
	return num>=n;
}
bool Queue()
{
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int cnt=q.front();q.pop();
		//next--->printf point
		s[++cnt]=cur;
		/*----------------*/
		num++;
		for(int i=pre[cur];~i;i=e[i].next)
		{
			int ito=e[i].to;
			if(!--in[ito]) q.push(ito);
		}
	}
	return num>=n;
}