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



int main() {
    int t;
    ll a,b,c,d;
    ll m,n,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ll g=__gcd(a*d,b*c);
        ll tmp=__gcd(g,b*d);;
        m=g/tmp;
        n=b*d/tmp;
        tmp=__gcd(a*c,g);
        x=a*c/tmp;
        y=g/tmp;
        printf("%lld/%lld %lld/%lld\n",m,n,x,y);
    }
    return 0;
}