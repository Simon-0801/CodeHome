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
const ll mod = 1e9 + 7;
const int maxn = 1000 + 5;

int p[maxn];
int t,s;

ll getdis(ll x,ll y){
    if(x<y){
        ll tmp=1e18;
        tmp=min(tmp,y-x-1);
        tmp=min(tmp,x+1+t-y);
        return tmp;
    }
    else if(x==y){
        return 1;
    }
    else{
        ll tmp=1e18;
        tmp=min(tmp,x-y+1);
        tmp=min(tmp,t-x+y-1);
        return tmp;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&t,&s);
        rep(i,1,s){
            scanf("%d",p+i);
        }
        ll ans=0;
        rep(i,2,s){
            ans+=getdis(p[i-1],p[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}