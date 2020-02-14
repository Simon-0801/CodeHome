#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

int depth[maxn];

int main() {
    int n,tmp,ji=0,ou=0;
    scanf("%d",&n);
    depth[1]=0;
    ou++;
    for(int i=2;i<=n;i++){
        scanf("%d",&tmp);
        depth[i]=depth[tmp]+1;
        if(depth[i]&1)  ji++;
        else  ou++;
    }
    ll ans=1ll*ji*(ji-1)+1ll*ou*(ou-1);
    printf("%lld\n",ans);
    return 0;
}