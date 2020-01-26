#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

int num[maxn],dp[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        dp[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(num[j]<num[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    int tmax=0;
    for(int i=1;i<=n;i++){
        tmax=max(dp[i],tmax);
    }
    printf("%d\n",tmax);
    return 0;
}