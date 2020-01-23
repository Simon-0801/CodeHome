#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;

int one[maxn],two[maxn];
int dp[maxn];

int main() {
    int n,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&one[i]);
        }
        for(int i=1;i<k;i++){
            scanf("%d",&two[i]);
        }
        dp[0]=0;
        for(int i=1;i<=k;i++){
            if(i==1){
                dp[i]=dp[i-1]+one[i];
                continue;
            }
            dp[i]=min(dp[i-1]+one[i],dp[i-2]+two[i-1]);
        }
        int h,m,s;
        h=8+dp[k]/3600;
        m=(dp[k]-(dp[k]/3600)*3600)/60;
        s=dp[k]%60;
        if(h>12){
            h-=12;
            printf("%02d:%02d:%02d pm\n",h,m,s);
        }
        else{
            printf("%02d:%02d:%02d am\n",h,m,s);
        }
    }
    return 0;
}