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
const int maxn = 800 + 5;

int dp[2][18][maxn][maxn];
int mp[maxn][maxn];
int n,m,k;
ll ans=0;

void solve(){
    rep(i,1,n){
        rep(j,1,m){
            int tmp=mp[i][j];
            dp[0][tmp%(k+1)][i][j]++;
            rep(l,0,k){
                if(i>1){
                    dp[0][l][i][j]=(dp[0][l][i][j]+dp[1][(l-tmp+k+1)%(k+1)][i-1][j])%mod;
                    dp[1][l][i][j]=(dp[1][l][i][j]+dp[0][(l+tmp+k+1)%(k+1)][i-1][j])%mod;
                }
                if(j>1){
                    dp[0][l][i][j]=(dp[0][l][i][j]+dp[1][(l-tmp+k+1)%(k+1)][i][j-1])%mod;
                    dp[1][l][i][j]=(dp[1][l][i][j]+dp[0][(l+tmp+k+1)%(k+1)][i][j-1])%mod;
                }
            //     dp[0][l][i][j]=(dp[0][l][i][j]+dp[1][(l-tmp+k+1)%(k+1)][i][j-1]+dp[1][(l-tmp+k+1)%(k+1)][i-1][j])%mod;
            //     dp[1][l][i][j]=(dp[1][l][i][j]+dp[0][(l-tmp+k+1)%(k+1)][i][j-1]+dp[0][(l-tmp+k+1)%(k+1)][i-1][j])%mod;
            }
            ans=(ans+1ll*dp[1][0][i][j])%mod;
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%d",&mp[i][j]);
        }
    }
    mst(dp,0);
    solve();
    printf("%lld\n",ans);
    return 0;   
}