#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;

int dp[maxn][maxn],num[maxn],sum[maxn];

int main() {
    int n;
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        dp[i][i]=num[i];
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n+1-len;l++){
            int r=l+len-1;
            dp[l][r]=max(dp[l+1][r]+sum[r]-sum[l]+num[l],dp[l][r-1]+sum[r-1]-sum[l-1]+num[r]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}