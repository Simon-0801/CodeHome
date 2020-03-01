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
const int maxn = 200 + 5;

int mp[maxn][maxn];
int dp[maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%d",&mp[i][j]);
        }
    }
    mst(dp,0xcf);
    dp[n+1][(m+1)/2]=0;
    repd(i,n,1){
        rep(j,1,m){
            dp[i][j]=max(dp[i][j],dp[i+1][j]+mp[i][j]);
            if(j-1>=1)  dp[i][j]=max(dp[i][j],dp[i+1][j-1]+mp[i][j]);
            if(j+1<=m)  dp[i][j]=max(dp[i][j],dp[i+1][j+1]+mp[i][j]);
        }
    }
    int ans=-1e9;
    rep(i,1,m){
        ans=max(ans,dp[1][i]);
    }
    printf("%d\n",ans);
    return 0;
}