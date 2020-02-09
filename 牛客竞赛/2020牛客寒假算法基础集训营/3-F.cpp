#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const ll mod=1e9+7;

ll sum[maxn];
char str[maxn];

int main() {
    ll n;
    scanf("%lld",&n);
    scanf("%s",str+1);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        if(str[i]=='1'){
            sum[++cnt]=i;
        }
    }
    ll ans=0;
    for(ll i=2;i<=cnt;i++){
        ans=(ans+(sum[i])*(i-1)%mod-sum[i-1]+mod)%mod;
        sum[i]=(sum[i-1]+sum[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}