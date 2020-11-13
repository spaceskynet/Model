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
int a[maxn],stack[maxn],n;
int main()
{
//	fr();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	/*---------------*/
	int top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&stack[top]>a[i]) top--;
		stack[++top]=a[i];
	}
	printf("%d\n",top);
	/*---------------*/
	int *top=stack;
	for(int i=1;i<=n;i++)
	{
		while(top>stack&&*top>a[i]) top--;
		*(++top)=a[i];
	}
	printf("%d\n",top-stack);
	/*---------------*/
	
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
