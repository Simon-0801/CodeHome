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

ll dp[maxn][2];

// ll qpow(ll num,ll p){
//     ll res=1;
//     while(p){
//         if(p&1)  res=(res*num)%mod;
//         num=(num*num)%mod;
//         p>>=1;
//     }
//     return res%mod;
// }   

int main() {
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        if(n==0){
            printf("1\n");
            continue;
        }
        ll sum0=1,sum1=1;
        dp[1][0]=dp[1][1]=1;
        rep(i,2,n){
            if(i<=k){
                dp[i][1]=sum0%mod;
                dp[i][0]=sum1%mod;
            }
            else{
                dp[i][0]=sum1%mod;
                dp[i][1]=sum0%mod;
                sum0=(sum0-dp[i-k][0]+mod)%mod;
                sum1=(sum1-dp[i-k][1]+mod)%mod;
            }
            sum0=(sum0+dp[i][0])%mod;
            sum1=(sum1+dp[i][1])%mod;
        }
        printf("%lld\n",(sum0+sum1)%mod);
    }
    return 0;
}