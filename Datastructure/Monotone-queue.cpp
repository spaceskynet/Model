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
const int maxn=1e6+10;
int a[maxn],n,k;
int main()
{
//	fr();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	static deque<int> qMax,qMin;
	static queue<int> Max,Min;
	for(int i=1;i<=k;i++)
	{
		while(!qMax.empty()&&a[qMax.back()]<=a[i]) qMax.pop_back();
		qMax.push_back(i);
		while(!qMin.empty()&&a[qMin.back()]>=a[i]) qMin.pop_back();
		qMin.push_back(i);
	}
//	printf("%d ",a[q.front()]);
	Max.push(a[qMax.front()]),Min.push(a[qMin.front()]);
	for(int i=k+1;i<=n;i++)	
	{
		while(!qMax.empty()&&a[qMax.back()]<=a[i]) qMax.pop_back();
		if(!qMax.empty()&&qMax.front()<=i-k) qMax.pop_front();//is front() in window
		qMax.push_back(i);
		while(!qMin.empty()&&a[qMin.back()]>=a[i]) qMin.pop_back();
		if(!qMin.empty()&&qMin.front()<=i-k) qMin.pop_front();
		qMin.push_back(i);
		Max.push(a[qMax.front()]),Min.push(a[qMin.front()]);
	}
	while(!Min.empty()) printf("%d ",Min.front()),Min.pop();putchar('\n');
	while(!Max.empty()) printf("%d ",Max.front()),Max.pop();putchar('\n');
	/*---------------
	int st=0,ts=0,t=0,s=0,x;
	x=st--- --s-t-s--- --ts;
	printf("%d\n",x);
	---------------*/
//	fprintf(stderr,"%.3f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
