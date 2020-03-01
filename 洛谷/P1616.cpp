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
const int maxn = 100000 + 5;

int dp[maxn];
int a[10005],val[10005];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",a+i,val+i);
    }
    mst(dp,0xcf);
    dp[0]=0;
    rep(i,1,m){
        rep(j,a[i],n){
            dp[j]=max(dp[j],dp[j-a[i]]+val[i]);
        }
    }
    int ans=-1e9;
    rep(i,1,n){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}