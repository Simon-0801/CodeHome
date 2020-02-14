#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

int num[maxn];
map<int,int> mp;

int main() {
    int n;
    scanf("%d",&n);
    num[0]=0;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        num[i]=(num[i-1]^num[i]);
        mp[num[i]]++;
    }
    ll ans=0;
    for(auto &x:mp){
        ans+=1ll*x.second*(x.second-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}