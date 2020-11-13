//2017-01-20
#include<cstdio>
const int maxn=1e5+10;
int x,y,z;
int pre[maxn];
int Find(int);
void conect(int,int);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if(z==1) conect(x,y);
		else
		{
			int sx=Find(x),sy=Find(y);
			if(sx==sy) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
int Find(int x)
{
	int r=x;
	while(r^pre[r]) r=pre[r];
	int i=x,j;
	while(r^pre[i]) j=pre[i],pre[i]=r,i=j;//Â·¾¶Ñ¹Ëõ
	return r;
}
int Find(int x)
{
	return pre[x]==x?x:pre[x]=Find(pre[x]);
}
void conect(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx^fy)
	{
		pre[fy]=fx;
	}
}
