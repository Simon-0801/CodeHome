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

struct node
{
    int pos,p;
}d[maxn];

int ans,n;
int vis[maxn];

void dfs(int cnt,int pre,int cost,int tsum){
    if(cnt>n){
        ans=min(ans,cost);
        return;
    }
    if(cost>ans)  return;
    int tmp=pre;
    while(tmp<=n&&vis[tmp])  tmp++;
    if(tmp<=n){
        vis[tmp]=1;
        int nxtc=cost+tsum*(abs(d[pre].pos-d[tmp].pos));
        dfs(cnt+1,tmp,nxtc,tsum-d[tmp].p);
        vis[tmp]=0;
    }
    tmp=pre;
    while(tmp>0&&vis[tmp])  tmp--;
    if(tmp>0){
        vis[tmp]=1;
        int nxtc=cost+tsum*(abs(d[pre].pos-d[tmp].pos));
        dfs(cnt+1,tmp,nxtc,tsum-d[tmp].p);
        vis[tmp]=0;
    }
}

int main() {
    int c,sum=0;
    scanf("%d%d",&n,&c);
    rep(i,1,n){
        scanf("%d%d",&d[i].pos,&d[i].p);
        sum+=d[i].p;
    }
    ans=INF;
    vis[c]=1;
    dfs(2,c,0,sum-d[c].p);
    printf("%d\n",ans);
    return 0;
}