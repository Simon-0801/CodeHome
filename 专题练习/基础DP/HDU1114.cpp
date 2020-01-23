#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 5;

int dp[maxn];
int p[505],w[505];

int main() {
    int t,e,f,totw,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&e,&f);
        totw=f-e;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i],&w[i]);
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=w[i];j<=totw;j++){
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
            }
        }
        if(dp[totw]==0x3f3f3f3f)  printf("This is impossible.\n");
        else  printf("The minimum amount of money in the piggy-bank is %d.\n",dp[totw]);
    }
    return 0;
}