#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

ll num[maxn],dp[maxn];

int main() {
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%lld",&num[i]);
        }
        num[0]=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(num[j]<num[i]){
                    dp[i]=max(dp[i],dp[j]+num[j]);
                }
            }
        }
        ll tmax=0;
        for(int i=1;i<=n;i++){
            tmax=max(tmax,dp[i]+num[i]);
        }
        printf("%lld\n",tmax);
    }
    return 0;
}