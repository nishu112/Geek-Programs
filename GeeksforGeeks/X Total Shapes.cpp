#include <bits/stdc++.h>

using namespace std;
#define 	 ll				   long long
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      vll               std::vector<long long>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define		 sc(x)			   scanf("%d",&x)
#define 	 scll(x)		   scanf("%lld",&x)
#define		 sc2(x,y)		   scanf("%d%d",&x,&y)
#define		 sc3(x,y,z)		   scanf("%d%d%d",&x,&y,&z)
#define	     pf(x)			   printf("%d ",x)
#define	     pf2(x,y)		   printf("%d %d ",x,y)
#define	     pf3(x,y,z)		   printf("%d %d %d ",x,y,z)
#define 	 pfnl()			   putchar('\n');
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define 	 rep2(i,j,n)	   for(int i = j; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define 	gc()				getchar()

#define debug(x) cerr<<"debug->"<<#x<<"::"<<x<<endl
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n"
#define MOD 1000000007

template <typename T> void scan(T &angka){
	angka=0;char input=gc();T kali=1;
	while(!(48<=input&&input<=57)){	if(input=='-')	kali=-1;input=gc();}
	while(48<=input&&input<=57)	angka=(angka<<3)+(angka<<1)+input-48,input=gc();angka*=kali;
}
char str[55][55];
bool visit[55][55];
int n,m;
void visit_X(int i,int j)
	{
	if(i<0 || i>n || j<0 || j>m || visit[i][j])	return;
	if(str[i][j]=='X' && !visit[i][j])
		{
		visit[i][j]=1;
		visit_X(i+1,j);
		visit_X(i,j+1);
		visit_X(i-1,j);
		visit_X(i,j-1);
		}
	}
int main() 
{
int t;
sc(t);
while(t--)
	{
	sc2(n,m);
	rep(i,n)	scanf("%s",str[i]);
	rep(i,n)	rep(j,m)	visit[i][j]=0;
	int count=0;
	for(int i=0;i<n;++i)
		{
		for(int j=0;str[i][j];++j)
			{
			if(str[i][j]=='X' && !visit[i][j])
				{
				++count;
				//visit[i][j]=1;
				visit_X(i,j);
				}
			}
		}
	printf("%d\n",count);
	}
return 0;
}



