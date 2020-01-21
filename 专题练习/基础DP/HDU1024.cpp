#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;
const int INF = 0x3f3f3f3f;

int num[maxn];
int dp[maxn],pre[maxn];

int main() {
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        int t=0,tmax=-INF;
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=m;i++){
            tmax=-INF;
            for(int j=i;j<=n;j++){
                dp[j]=max(dp[j-1],pre[j-1])+num[j];
                pre[j-1]=tmax;
                tmax=max(tmax,dp[j]);
            }
            t=1-t;
        }
        printf("%d\n",tmax);
    }
    return 0;
}