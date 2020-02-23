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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

map<ll,int> mp;

int main() {
    ll n,p,k,num,ans=0;
    scanf("%lld%lld%lld",&n,&p,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&num);
        ll tmp=(num*num%p*num%p*num%p-k*num%p+p)%p;
        ans+=mp[tmp];
        mp[tmp]++;
    }
    printf("%lld\n",ans);
    return 0;
}