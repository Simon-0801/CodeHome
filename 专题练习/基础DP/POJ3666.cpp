#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
const int INF = 0x3f3f3f3f;

int dp[maxn][maxn],a[maxn],b[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=len;i++){
        dp[1][i]=abs(a[1]-b[i]);
    }
    for(int i=2;i<=n;i++){
        int mmin=INF;
        for(int j=1;j<=len;j++){
            mmin=min(mmin,dp[i-1][j]);
            dp[i][j]=mmin+abs(a[i]-b[j]);
        }
    }
    int ans=INF;
    for(int i=1;i<=len;i++){
        ans=min(dp[n][i],ans);
    }
    for(int i=1;i<=len;i++){
        dp[1][i]=abs(a[1]-b[i]);
    }
    for(int i=2;i<=n;i++){
        int mmin=INF;
        for(int j=len;j>=1;j--){
            mmin=min(mmin,dp[i-1][j]);
            dp[i][j]=mmin+abs(a[i]-b[j]);
        }
    }
    for(int i=1;i<=len;i++){
        ans=min(dp[n][i],ans);
    }
    printf("%d\n",ans);
    return 0;
}

/*
    最终单调序列中的数，必然都是原数组中的值
    dp[i][j]表示枚举到第i个数，且最后一位为原数组中第j大的数，转移方程dp[i][j] = min(dp[i-1][1,2,3,....j-1]) +abs(a[i]-c[j])
    用一个变量维护min(dp[i-1][1,2,3,....j-1])
*/