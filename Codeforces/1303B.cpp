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



int main() {
    int t;
    ll n,g,b;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d%I64d",&n,&g,&b);
        ll half;
        if(n&1)  half=(n+1)/2;
        else half=n/2;
        ll times=half/(g);
        ll left=half%g;
        ll ans;
        if(left==0){
            ans=times*(g+b)-b;
        }
        else{
            ans=times*(g+b)+left;
        }
        printf("%I64d\n",max(ans,n));
    }
    return 0;
}