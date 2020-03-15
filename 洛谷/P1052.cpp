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
const int maxn = 10000 + 5;

int a[105],pos[105];
int dp[maxn],vis[maxn];

int main() {
    int l;
    scanf("%d",&l);
    int s,t,m;
    scanf("%d%d%d",&s,&t,&m);
    rep(i,1,m){
        scanf("%d",a+i);
    }
    sort(a+1,a+m+1);
    if(s==t){
        int ans=0;
        rep(i,1,m){
            if(a[i]%s==0)  ans++;
        }
        printf("%d\n",ans);
        return 0;
    }
    a[0]=0;
    pos[0]=0;
    rep(i,1,m){
        int tmp=a[i]-a[i-1];
        if(tmp>s*t)  tmp=s*t;
        pos[i]=pos[i-1]+tmp;
        vis[pos[i]]=1;
    }
    int L=pos[m]+s*t;
    mst(dp,0x3f);
    dp[0]=0;
    rep(i,1,L){
        rep(j,s,t){
            if(i-j>=0){
                if(vis[i]){
                    dp[i]=min(dp[i],dp[i-j]+1);
                }
                else{
                    dp[i]=min(dp[i],dp[i-j]);
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    rep(i,pos[m],L){
        ans=min(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}