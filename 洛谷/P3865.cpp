#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 200000 + 5;

int a[maxn];

int logn[maxn];
int st[maxn][60];
int n,m;

void init(){
    logn[1]=0;
    logn[2]=1;
    rep(i,3,maxn-5){
        logn[i]=logn[i/2]+1;
    }
}

void pre(){
    rep(i,1,n)  st[i][0]=a[i];
    rep(j,1,17){
        rep(i,1,n){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main() {
    n=read(),m=read();
    // scanf("%d%d",&n,&m);
    rep(i,1,n){
        a[i]=read();
        // scanf("%d",a+i);
    }
    init();
    pre();
    int l,r,lg;
    while(m--){
        l=read(),r=read();
        // scanf("%d%d",&l,&r);
        lg=logn[(r-l+1)];
        printf("%d\n",max(st[l][lg],st[r-(1<<lg)+1][lg]));
    }
    return 0;
}