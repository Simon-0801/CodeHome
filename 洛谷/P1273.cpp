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
const int maxn = 3000 + 5;

struct node
{
    int v,c;
};


int n,m;
vector<node> edge[maxn];
int fe[maxn];
int cnum[maxn];
int dp[maxn][maxn];

void dfsClient(int x){
    if(edge[x].size()==0){
        cnum[x]=1;
        return;
    }
    cnum[x]=0;
    for(auto &nod:edge[x]){
        dfsClient(nod.v);
        cnum[x]+=cnum[nod.v];
    }
}

void dfs(int x){
    dp[x][0]=0;
    if(edge[x].size()==0){
        dp[x][1]=fe[x-(n-m)];
        return;
    }
    for(auto &nod:edge[x]){
        dfs(nod.v);
        repd(j,cnum[x],1){
            rep(k,1,cnum[nod.v]){
                if(j-k>=0){
                    dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[nod.v][k]-nod.c);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n-m){
        int sz,v,c;
        scanf("%d",&sz);
        rep(j,1,sz){
            scanf("%d%d",&v,&c);
            node tmp;
            tmp.v=v;
            tmp.c=c;
            edge[i].push_back(tmp);
        }
    }
    rep(i,1,m){
        scanf("%d",fe+i);
    }
    dfsClient(1);
    mst(dp,0xcf);
    dfs(1);
    int ans=0;
    repd(i,cnum[1],0){
        if(dp[1][i]>=0){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}