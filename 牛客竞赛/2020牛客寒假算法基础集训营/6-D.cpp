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

ll a[maxn],b[maxn],cnt[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    mst(cnt,0);
    sort(b+1,b+n+1);
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--){
        int pos=lower_bound(b+1,b+n+1,a[i])-b;
        if(pos>n){
            printf("0\n");
            return 0;
        } 
        cnt[i]=n-pos+1; 
    }
    ll ans=1;
    for(int i=n,j=1;i>0,j<=n;i--,j++){
        ll tmp=cnt[i]-j+1;
        if(tmp<=0){
            printf("0\n");
            return 0;
        }
        ans=(ans*tmp%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}