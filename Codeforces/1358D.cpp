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

ll sum[maxn<<1];
ll d[maxn];
ll dsum[maxn<<1];

int main() {
    int n;
    ll x;
    scanf("%d%lld",&n,&x);
    repd(i,n,1){
        scanf("%lld",d+i);
        sum[i]=1ll*(1+d[i])*d[i]/2;
    }
    rep(i,1,n){
        sum[i]=sum[i-1]+sum[i];
        dsum[i]=dsum[i-1]+d[i];
    }
    rep(i,n+1,n+n){
        dsum[i]=dsum[i-1]+d[i-n];
    }
    ll ans=0;
    rep(i,1,n){
        auto pos=lower_bound(dsum+1,dsum+n+n+1,dsum[i-1]+x)-dsum;

        if(dsum[pos]==dsum[i-1]+x){
            if(pos>n){
                ans=max(ans,sum[n]-sum[i-1]+sum[pos-n]);
            }
            else{
                ans=max(ans,sum[pos]-sum[i-1]);
            }
        }
        else{
            if(pos>n){
                ll tmp=dsum[pos]-dsum[i-1]-x;
                ans=max(ans,sum[n]-sum[i-1]+sum[pos-n]-1ll*(1+tmp)*tmp/2);
            }
            else{
                ll tmp=dsum[pos]-dsum[i-1]-x;
                ans=max(ans,sum[pos]-sum[i-1]-1ll*(1+tmp)*tmp/2);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}