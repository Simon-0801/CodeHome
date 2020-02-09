#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    ll a,b,c,x,y,z;
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld%lld",&x,&y,&z);
    ll ans=min(a,y)+min(b,z)+min(c,x);
    printf("%lld\n",ans);
    return 0;
}