#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int mp[205][205];
ll dp[maxn],premax[maxn];

struct node
{
    ll t,p,val;
}b[maxn];

int cmp(node a,node b){
    return a.t<b.t;
}

int main() {
    int n,m,u,v,k;
    scanf("%d%d",&n,&m);
    memset(mp,0x3f,sizeof mp);
    for(int i=1;i<=n;i++)  mp[i][i]=0;
    while(m--){
        scanf("%d%d",&u,&v);
        mp[u][v]=mp[v][u]=1;
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%lld%lld%lld",&b[i].t,&b[i].p,&b[i].val);
    }
    sort(b+1,b+k+1,cmp);
    b[0].t=0;
    b[0].p=1;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    memset(dp,0,sizeof dp);
    ll ans=0;
    for(int i=1;i<=k;i++){
        ll tmpt=b[i].t,tmpp=b[i].p,tmpval=b[i].val;
        if(i>n){
            dp[i]=max(dp[i],premax[i-n]+tmpval);
        }
        else{
            dp[i]=-1e18;
        }
        for(int j=1;j<=n&&j<=i;j++){
            if(tmpt>=mp[b[i-j].p][tmpp]+b[i-j].t){
                dp[i]=max(dp[i-j]+tmpval,dp[i]);
            }
        }
        premax[i]=max(premax[i-1],dp[i]);
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}