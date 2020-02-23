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
const ll mod = 998244353;
const int maxn = 2000 + 5;

ll dp[maxn][maxn];

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    mst(dp,0);
    dp[1][0]=m;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j>0)  dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(m-1))%mod;
        }
    }
    printf("%I64d\n",dp[n][k]%mod);
    return 0;
}