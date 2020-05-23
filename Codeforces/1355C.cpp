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
const int maxn = 100000 + 5;



int main() {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    ll ans=0;
    rep(i,max(c+1,a+b),b+c){
        ans+=1ll*(min(i-1,d)-c+1)*(min(i-b,b)-max(a,i-c)+1);
    }
    printf("%lld\n",ans);
    return 0;
}