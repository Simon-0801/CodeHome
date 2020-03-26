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

ll num[maxn];

int main() {
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        rep(i,1,n+m+1){
            scanf("%lld",num+i);
        }
        ll ans=num[1];
        rep(i,2,n+1){
            ans=(ans&num[i]);
        }
        rep(i,n+2,n+m+1){
            ans=(ans|num[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}