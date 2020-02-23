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
const int maxn = 2000 + 5;

ll row[maxn],col[maxn];
map<PII,ll> mp;

int main() {
    int n,m,h,x,y,z;
    scanf("%d%d%d",&n,&m,&h);
    mst(row,0);
    mst(col,0);
    while(h--){
        scanf("%d%d%d",&x,&y,&z);
        row[x]=(row[x]+1ll*z)%mod;
        col[y]=(col[y]+1ll*z)%mod;
        mp[PII(x,y)]+=1ll*z;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=(ans+(1ll*(row[i]+col[j])%mod)*(i+j)%mod)%mod;
        }
    }
    for(auto &x:mp){
        PII tmp=x.first;
        ans=(ans+mod-(1ll*(tmp.first+tmp.second)%mod*x.second)%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}