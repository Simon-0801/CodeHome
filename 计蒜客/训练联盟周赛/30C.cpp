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
const ll maxn = 1000000 + 5;



int main() {
    ll x,y;
    while(scanf("%lld%lld",&x,&y)!=EOF){
        ll ans = 0;
        for(ll i = 1; i < maxn; i++) {
            ll tot1 = (x - 1) / i, tot2 = y / i;
            if(tot2) ans += (tot2 - tot1) * i;
            ll k = max(maxn, tot1 + 1);
            if(tot2 >= k) {
                // if((tot2 + k) % 2 == 0) ans += (tot2 - k + 1) * ((tot2 + k) / 2);
                // else ans += (tot2 - k + 1) / 2 * (tot2 + k);
                ans+=(tot2-k+1)*(tot2+k)/2;
                //cout << ans << endl;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}