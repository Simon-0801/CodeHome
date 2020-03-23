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
const int maxn = 200000 + 5;

ll b[maxn],a[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lld",b+i);
    }
    a[1]=b[1];
    ll tmax=max(0ll,a[1]);
    rep(i,2,n){
        a[i]=b[i]+tmax;
        tmax=max(tmax,a[i]);
    }
    rep(i,1,n){
        printf("%lld%c",a[i],i==n?'\n':' ');
    }
    return 0;
}