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

int dp[maxn][maxn];
int m[maxn],t[maxn];

int main() {
    int n,M,T;
    scanf("%d%d%d",&n,&M,&T);
    rep(i,1,n){
        scanf("%d%d",m+i,t+i);
    }
    rep(i,1,n){
        repd(j,M,m[i]){
            repd(k,T,t[i]){
                dp[j][k]=max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
            }
        }
    }
    int ans=0;
    rep(i,1,M){
        rep(j,1,T){
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}