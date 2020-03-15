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
const int maxn = 5000 + 5;

int dp[maxn],p[maxn],cnt[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",p+i);
    }
    int ans=0,sum=0;
    rep(i,1,n){
        dp[i]=1;
        rep(j,1,i-1){
            if(p[j]>p[i])  dp[i]=max(dp[i],dp[j]+1);
        }
        if(dp[i]==1)  cnt[i]=1;
        ans=max(ans,dp[i]);
    }
    rep(i,1,n){
        rep(j,1,i-1){
            if(p[j]>p[i]&&dp[i]==dp[j]+1)  cnt[i]+=cnt[j];
            if(p[j]==p[i]&&dp[j]==dp[i])  cnt[j]=0;
        }
    }
    rep(i,1,n){
        if(dp[i]==ans)  sum+=cnt[i];
    }
    printf("%d %d\n",ans,sum);
    return 0;
}