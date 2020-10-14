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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 200000 + 5;

ll a[maxn];

struct node
{
    ll num;
    int id;
}b[maxn];

int cmp(node x,node y){
    return x.num>y.num;
}

int cmpid(node x,node y){
    return x.id<y.id;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%lld",a+i);
        }
        sort(a+1,a+n+1);
        ll tmp;
        rep(i,1,n){
            scanf("%lld",&tmp);
            b[i].num=1ll*i*(n-i+1)*tmp;
            b[i].id=i;
        }
        sort(b+1,b+n+1,cmp);
        // rep(i,1,n){
        //     b[i].num=1ll*b[i].num*a[i];
        // }
        // sort(b+1,b+n+1,cmpid);
        ll ans=0;
        rep(i,1,n){
            ans=(ans+1ll*b[i].num%mod*a[i]%mod)%mod;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}