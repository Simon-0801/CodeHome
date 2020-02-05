#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 5;

char str[maxn];
ll dp[maxn];

int main() {
    ll n,a,b,c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    scanf("%s",str);
    string s="1";
    s+=str;
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(i>=4&&s.substr(i-3,4)=="nico"){
            dp[i]=max(dp[i],dp[i-4]+a);
        }
        if(i>=6&&s.substr(i-5,6)=="niconi"){
            dp[i]=max(dp[i],dp[i-6]+b);
        }
        if(i>=10&&s.substr(i-9,10)=="niconiconi"){
            dp[i]=max(dp[i],dp[i-10]+c);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}