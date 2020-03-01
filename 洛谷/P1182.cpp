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

ll a[maxn];
int n,m;

bool check(ll x){
    ll sum=0,cnt=1;
    rep(i,1,n){
        if(sum+a[i]<=x)  sum+=a[i];
        else sum=a[i],cnt++;
    }
    return cnt<=m;
}

int main() {
    ll l=-1,r=0;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%lld",&a[i]);
        r+=a[i];
        l=max(l,a[i]);
    }
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}