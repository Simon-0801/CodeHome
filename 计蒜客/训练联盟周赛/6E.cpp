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
    ll k,l;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&k,&l);
        if(l>=2000){
            printf("-1\n");
            continue;
        }
        ll tmp=k+1999;
        ll avg=tmp/1998;
        printf("1999\n");
        printf("-1 ");
        rep(i,1,1997){
            printf("%lld ",avg);
        }
        printf("%lld\n",tmp-avg*1997);
    }
    return 0;
}