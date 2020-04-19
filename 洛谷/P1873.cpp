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
const int maxn = 1000000 + 5;

ll h[maxn];
ll n,m;

bool check(ll num){
    ll sum=0;
    rep(i,1,n){
        if(h[i]>num){
            sum+=h[i]-num;
        }
    }
    if(sum>=m)  return true;
    else  return false;
}

int main() {
    scanf("%lld%lld",&n,&m);
    rep(i,1,n){
        scanf("%lld",h+i);
    }
    ll l=0,r=1e9;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}