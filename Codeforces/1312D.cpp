#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 998244353;
const int maxn = 100000 + 5;

ll qpow(ll num,ll p){
    ll res=1;
    while(p){
        if(p&1)  res=res*num%mod;
        num=num*num%mod;
        p>>=1;
    }
    return res%mod;
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==2){
        printf("0\n");
        return 0;
    }
    ll mu=1;
    rep(i,1,n-1){
        mu=(1ll*mu%mod*i%mod)%mod;
    }
    ll zi=1;
    rep(i,m-n+2,m){
        zi=(1ll*zi%mod*i%mod)%mod;
    }
    ll ans=zi*qpow(mu,mod-2)%mod*(n-2)%mod*qpow(2,n-3)%mod;
    printf("%lld\n",ans%mod);
    return 0;
}