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

ll qpow(ll num,ll p){
    ll res=1;
    while(p){
        if(p&1)  res=res*num;
        num=num*num;
        p>>=1;
    }
    return res;
}

vector<ll> v;

int main() {
    ll n;
    scanf("%lld",&n);
    ll tmp=n;
    int cnt2=0,cnt5=0;
    while(tmp%2==0){
        tmp/=2;
        cnt2++;
    }
    while(tmp%5==0){
        tmp/=5;
        cnt5++;
    }
    printf("%lld\n",1ll*(cnt2+1)*(cnt5+1));
    rep(i,0,cnt2){
        ll tt=qpow(2,i);
        rep(j,0,cnt5){
            ll ans=tt*qpow(5,j);
            v.push_back(ans);
        }
    }
    sort(v.begin(),v.end());
    for(auto &x:v){
        printf("%lld\n",x);
    }
    return 0;
}