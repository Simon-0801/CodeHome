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
const int maxn = 32000 + 5;

ll dp[65][maxn];
int val[65],w[65];

struct node
{
    int now,l,r;
}p[65];

map<int,int> mp;

int main() {
    int n,m,fa;
    scanf("%d%d",&n,&m);
    int cnt=0;
    rep(i,1,m){
        scanf("%d%d%d",val+i,w+i,&fa);
        if(fa==0){
            p[++cnt].now=i;
            mp[i]=cnt;
        }
        else{
            if(p[mp[fa]].l==0){
                p[mp[fa]].l=i;
            }
            else p[mp[fa]].r=i;
        }
    }
    mst(dp,0);
    dp[0][0]=0;
    val[0]=0;
    rep(i,1,cnt){
        rep(j,0,n){
            dp[i][j]=dp[i-1][j];
            if(j>=val[p[i].now]) dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            if(j>=val[p[i].now]+val[p[i].l])  dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].l])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]);
            if(j>=val[p[i].now]+val[p[i].r])  dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].r]*w[p[i].r]);
            if(j>=val[p[i].now]+val[p[i].l]+val[p[i].r])  dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].l]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]+val[p[i].r]*w[p[i].r]);
            // if(p[i].l&&p[i].r){
            //     if(j>=val[p[i].now]+val[p[i].l]+val[p[i].r]){
            //         dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].l]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]+val[p[i].r]*w[p[i].r]);
            //         dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].l])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]);
            //         dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].r]*w[p[i].r]);
            //         dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         continue;
            //     }
            //     if(val[p[i].l]>val[p[i].r]){
            //         if(j>=val[p[i].now]+val[p[i].l]){
            //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].l])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]);
            //             dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].r]*w[p[i].r]);
            //             dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         }
            //         else if(j>=val[p[i].now]+val[p[i].r]){
            //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].r]*w[p[i].r]);
            //             dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         }
            //         else{
            //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         }
            //     }
            //     else{
            //         if(j>=val[p[i].now]+val[p[i].r]){
            //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].l])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]);
            //             dp[i][j]=max(dp[i][j],dp[i-1][j-(val[p[i].now]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].r]*w[p[i].r]);
            //             dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         }
            //         else if(j>=val[p[i].now]+val[p[i].l]){
            //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].l])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]);
            //             dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         }
            //         else{
            //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //         }
            //     }
            // }
            // else if(p[i].l){
            //     if(j>=val[p[i].now]+val[p[i].l]){
            //         dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].l])]+val[p[i].now]*w[p[i].now]+val[p[i].l]*w[p[i].l]);
            //         dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //     }
            //     else{
            //         dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //     }
            // }
            // else if(p[i].r){
            //     if(j>=val[p[i].now]+val[p[i].r]){
            //         dp[i][j]=max(dp[i-1][j],dp[i-1][j-(val[p[i].now]+val[p[i].r])]+val[p[i].now]*w[p[i].now]+val[p[i].r]*w[p[i].r]);
            //         dp[i][j]=max(dp[i][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //     }
            //     else{
            //         dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            //     }
            // }
            // else{
            //     dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[p[i].now]]+val[p[i].now]*w[p[i].now]);
            // }
        }
    }
    ll ans=-1e18;
    rep(i,1,n){
        ans=max(ans,dp[cnt][i]);
    }
    printf("%lld\n",ans);
    return 0;
}