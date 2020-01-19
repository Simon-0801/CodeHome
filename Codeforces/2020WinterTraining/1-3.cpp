#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;
const int mod=1e9+7;

int dp[maxn],dp2[maxn];

int main() {
    int n,k,d;
    scanf("%d%d%d",&n,&k,&d);
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    for(int i=1;i<=k;i++){
        dp[i]=1;
        if(i<d)  dp2[i]=1;
        else dp2[i]=0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(i-1,k);j++){
            dp[i]=(dp[i-j]+dp[i])%mod;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(i-1,k);j++){
            if(j>=d)  continue;
            dp2[i]=(dp2[i]+dp2[i-j])%mod;
        }
    }
    printf("%d\n",(mod+dp[n]-dp2[n])%mod);
    return 0;
}