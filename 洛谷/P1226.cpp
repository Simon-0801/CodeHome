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
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

ll qpow(ll num,ll p,ll mod){
    // if(num==0&&p==0)  return 0;
    ll res=1;
    while(p){
        if(p&1)  res=(res*num)%mod;
        num=(num*num)%mod;
        p>>=1;
    }
    return res%mod;
}

int main() {
    ll b,p,k;
    scanf("%lld%lld%lld",&b,&p,&k);
    printf("%lld^%lld mod %lld=%lld\n",b,p,k,qpow(b,p,k));
    return 0;
}