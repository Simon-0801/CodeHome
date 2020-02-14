#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

map<pair<ll,ll>,int> mp2;
map<ll,int> mp;

int main() {
    ll n,a,b,x,vx,vy;
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d%I64d",&x,&vx,&vy);
        mp[a*vx-vy]++;
        mp2[make_pair(vx,vy)]++;
    }
    ll ans=0;
    for(auto &x:mp){
        ans+=1ll*x.second*(x.second-1);
    }
    for(auto &x:mp2){
        ans-=1ll*x.second*(x.second-1);
    }
    printf("%I64d\n",ans);
    return 0;
}