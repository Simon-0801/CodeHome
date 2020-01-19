#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int a[maxn];
int dp[maxn];

int main() {
    int n,tmax=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]>=a[i-1])  dp[i]=dp[i-1]+1;
    }
    for(int i=1;i<=n;i++){
        tmax=max(tmax,dp[i]);
    }
    printf("%d\n",tmax);
    return 0;
}