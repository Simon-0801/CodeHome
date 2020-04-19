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



int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans=0;
        // rep(i,1,n){
        //     if((n*n)%i==0){
        //         ll x=i,y=(n*n)/i;
        //         x+=n;
        //         y+=n;
        //         ans=max(ans,(x^y));
        //     }
        // }
        ll x=1,y=n*n;
        x+=n;
        y+=n;
        ans=(x^y);
        printf("%lld\n",ans);
    }
    return 0;
}