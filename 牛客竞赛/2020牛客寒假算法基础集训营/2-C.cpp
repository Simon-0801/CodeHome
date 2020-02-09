#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
const ll mod = 1e9 + 7;

ll p[maxn];
ll dp[maxn][maxn];//dp[i][j]表示前i道题中，做对j题的概率

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i]);
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=(dp[i-1][0]*(mod+1-p[i])%mod)%mod;
        for(int j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]*(mod+1-p[i])%mod+dp[i-1][j-1]*p[i])%mod;
        }
    }
    for(int i=0;i<=n;i++){
        printf("%lld%c",dp[n][i],i==n?'\n':' ');
    }
    return 0;
}