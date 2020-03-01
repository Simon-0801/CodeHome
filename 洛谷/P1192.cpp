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
const ll mod = 100003;
const int maxn = 100000 + 5;

int dp[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    mst(dp,0);
    dp[0]=1;
    rep(i,1,n){
        rep(l,1,k){
            if(i-l>=0)  dp[i]=(dp[i]+dp[i-l])%mod;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}