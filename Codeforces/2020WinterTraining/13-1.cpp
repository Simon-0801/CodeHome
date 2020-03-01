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

ll a[10];
ll d;

int main() {
    scanf("%lld%lld%lld%lld",&a[1],&a[2],&a[3],&d);
    sort(a+1,a+4);
    ll ans=0;
    if(a[2]-a[1]<d)  ans+=d-(a[2]-a[1]);
    if(a[3]-a[2]<d)  ans+=d-(a[3]-a[2]);
    printf("%lld\n",ans);  
    return 0;
}