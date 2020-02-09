#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const ll mod = 1e9+7;

ll qpow(ll num,ll p){
    if(num==1||p==0)  return 1;
    if(num==0)  return 0;
    ll ans=1;
    while(p){
        if(p&1)  ans=(ans*num)%mod;
        num=(num*num)%mod;
        p>>=1;
    }
    return ans%mod;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,d,e,f,g;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g);
        if(qpow(a,d)+qpow(b,e)+qpow(c,f)==g)  printf("Yes\n");
        else  printf("No\n");
    }

    return 0;
}