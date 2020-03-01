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
const int maxn = 50 + 5;

int mp[maxn][maxn];
int dp[maxn<<1][maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%d",&mp[i][j]);
        }
    }
    mst(dp,-1);
    dp[2][1][1]=0;
    rep(step,3,n+m-1){
        rep(i,1,m-1){
            rep(j,i+1,m){
                dp[step][i][j]=max(dp[step][i][j],dp[step-1][i][j]);
                if(i-1>=1&&j-1>=1)  dp[step][i][j]=max(dp[step][i][j],dp[step-1][i-1][j-1]);
                if(i-1>=1)  dp[step][i][j]=max(dp[step][i][j],dp[step-1][i-1][j]);
                if(j-1>=1)  dp[step][i][j]=max(dp[step][i][j],dp[step-1][i][j-1]);
                if(dp[step][i][j]==-1)  continue;
                dp[step][i][j]+=mp[step-i][i]+mp[step-j][j];
            }
        }
    }
    printf("%d\n",dp[n+m-1][m-1][m]);
    return 0;
}