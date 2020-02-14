#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;
const ll mod = 998244353;

ll num[maxn];
vector<int> v;

ll qpow(ll num,ll p){
    ll res=1;
    while(p){
        if(p&1)  res=(res*num)%mod;
        num=(num*num)%mod;
        p>>=1;
    }
    return res%mod;
}

int main() {
    // printf("%lld\n",qpow(3,3));
    int n,k;
    scanf("%d%d",&n,&k);
    num[0]=1;
    v.push_back(0);
    for(int i=1;i<=n;i++){
        scanf("%lld",&num[i]);
        if(num[i]==0)  v.push_back(i);
    }
    v.push_back(n+1);
    int sz=v.size();
    ll ans=0;
    for(int i=0;i<sz-1;i++){
        int l=v[i],r=v[i+1];
        if(r-l-1<k)  continue;
        ll tmp=1;
        for(int j=l+1;j<=l+k;j++){
            tmp=(tmp*num[j])%mod;
        }
        ans=max(ans,tmp);
        for(int j=l+2;j<=r-k;j++){
            tmp=(((tmp*qpow(num[j-1],mod-2))%mod*num[j+k-1])%mod);
            ans=max(tmp,ans);
        }
    }
    printf("%lld\n",ans);
    return 0;
}