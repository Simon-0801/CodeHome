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
const int maxn = 100000 + 5;

ll a[maxn],b[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lld",a+i);
    }
    rep(i,1,n){
        scanf("%lld",b+i);
    }
    ll ans=-1;
    rep(i,1,n){
        ll tmp=1e18;
        rep(j,1,n){
            tmp=min(tmp,abs(a[i]-b[j]));
        }
        ans=max(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}