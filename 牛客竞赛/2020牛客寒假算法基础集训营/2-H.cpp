#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 5;

ll num[maxn];

struct node
{
    ll sub,tmin;
}dp[maxn];


int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&num[i]);
    }
    sort(num+1,num+n+1);
    dp[k].sub=num[k]-num[1];
    dp[k].tmin=num[1];
    for(int i=k+1;i<=n;i++){
        dp[i].sub=dp[i-1].sub-num[i-1]+num[i];
        dp[i].tmin=dp[i-1].tmin;
        if(i-k>=k){
            ll tmp=dp[i-k].sub+num[i]-num[i-k+1];
            if(tmp<dp[i].sub){
                dp[i].sub=tmp;
                dp[i].tmin=num[i-k+1];
            }
        }
    }
    printf("%lld\n",dp[n].sub);
    return 0;
}