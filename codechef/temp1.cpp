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
int min(ll x,ll y){
	if(x>y)	return y;
	return x;
}
ll required(ll n){
	if(n<0)	return INT_MAX;
	if((n&(n-1))==0)	return 0;
	int l=log(n)/log(2);
	return min(n-(1LL<<l),(1LL<<(l+1))-n);
}
int main()
{
int t;
cin>>t;
while(t--)
	{
	int n;
	cin>>n;
	if(n==1)	{
		cout<<"2\n";
		continue;
	}
	if(n==2){
		cout<<"1\n";
		continue;
	}
	if((n&(n-1))==0)	{cout<<"1\n";continue;}
	int bits;
	
	bits=log(n)/log(2);
	ll MinSteps=INT_MAX;
	for(int i=bits;i>=0 && MinSteps!=0;--i)	{
		if((1<<i)!=(n>>1)){
			if((1<<i)<n)
			MinSteps=min(MinSteps,required(n-(1<<i)));
			else	
			MinSteps=min(MinSteps,required((1<<i)-n));
		}
	}
	cout<<MinSteps<<"\n";
	}
return 0;
}
