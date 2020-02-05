#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000050 + 5;

ll num[maxn];
ll ans=0;

ll getnum(ll n){
    ll cnt=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(i!=n/i)  cnt++;
        }
    }
    return cnt;
}

void solve(ll nn){
    if(nn==2){
        return;
    }
    ans++;
    solve(getnum(nn));
}

int main() {
    ll n;
    scanf("%lld",&n);
    // for(ll i=2;i<=1000050;i++){
    //     num[i]=getnum(i);
    // }
    ll tmp=getnum(n);
    ans=1;
    solve(tmp);
    printf("%lld\n",ans);
    return 0;
}