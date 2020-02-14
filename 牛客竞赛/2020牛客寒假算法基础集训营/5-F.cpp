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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

ll dp[maxn][2];
ll sum[maxn];
int x;

void solve(){
    mst(dp,0);
    dp[0][0]=1;
    for(int i=1;i<maxn;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
        if(i>=x)  dp[i][1]=dp[i-x][0]%mod;
    }
    sum[0]=0;
    for(int i=1;i<maxn;i++){
        sum[i]=(sum[i-1]+dp[i][0]+dp[i][1])%mod;
    }
}

int main() {
    int q,l,r;
    scanf("%d",&x);
    scanf("%d",&q);
    solve();
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%lld\n",(sum[r]-sum[l-1]+mod)%mod);
    }
    return 0;
}