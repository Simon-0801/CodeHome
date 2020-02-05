#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 5000000 + 5;
const ll mod = 1e9+7;


int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans=(((m-1)*m)%mod*(2*(n-2))%mod)%mod+(((m-2)*m)%mod*(2*(n-1))%mod)%mod+(((n-1)*(n-2))%mod*(2*(m-2))%mod)%mod+(((n-2)*(n-2))%mod*(2*(m-1))%mod)%mod;
    printf("%lld\n",ans%mod);
    return 0;
}