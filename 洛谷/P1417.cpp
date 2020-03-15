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
const int maxn = 100000 + 5;

struct node
{
    ll a,b,c;

    bool operator< (const node& nod) const{
        return c*nod.b<b*nod.c;
    }
}p[55];


ll dp[maxn];

int main() {
    int t,n;
    scanf("%d%d",&t,&n);
    rep(i,1,n){
        scanf("%lld",&p[i].a);
    }
    rep(i,1,n){
        scanf("%lld",&p[i].b);
    }
    rep(i,1,n){
        scanf("%lld",&p[i].c);
    }
    sort(p+1,p+n+1);
    // mst(dp,0xcf);
    dp[0]=0;
    rep(i,1,n){
        repd(j,t,p[i].c){
            dp[j]=max(dp[j],dp[j-p[i].c]+p[i].a-j*p[i].b);
        }
    }
    ll ans=-1e18;
    rep(i,1,t){
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}