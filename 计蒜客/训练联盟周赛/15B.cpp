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
const int maxn = 5000 + 5;

ll dp[maxn][maxn];
ll a[maxn];
ll tmp[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%lld",a+i);
    }
    mst(tmp,0xcf);
    tmp[0]=0;
    rep(i,1,n){
        int mx=(i%2?(i/2+1):(i/2));
        repd(j,i-1,1){
            dp[i][j]=max(dp[i-1][j]+a[i],tmp[j-1]+a[i]);
            tmp[j]=max(tmp[j],dp[i][j]);
        }
        dp[i][i]=dp[i-1][i-1]+a[i];
        tmp[i]=max(tmp[i],dp[i][i]);
    }
    ll ans=-1e18;
    rep(i,k,n){
        ans=max(ans,dp[i][k]);
    }
    printf("%lld\n",ans);
    return 0;
}