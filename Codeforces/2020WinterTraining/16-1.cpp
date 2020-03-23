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
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll g=__gcd(n,k);
    if(g==1){
        printf("%lld\n",(n-1)*k);
    }
    else{
        printf("%lld\n",(n-g)*k+(g-1)*(k-1));
    }
    return 0;
}