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
const int maxn = 300 + 5;

VI edge[maxn];
int score[maxn];
int sz[maxn];
int dp[maxn][maxn];
int m;

void dfssz(int x){
    sz[x]=1;
    for(auto &nod:edge[x]){
        dfssz(nod);
        sz[x]+=sz[nod];
    }
}

void dfs(int x){
    dp[x][0]=0;
    if(edge[x].size()==0){
        dp[x][1]=score[x];
        return;
    }
    for(auto &nod:edge[x]){
        dfs(nod);
        repd(i,sz[x],1){
            rep(j,1,sz[nod]){
                if(i-j>=0){
                    dp[x][i]=max(dp[x][i],dp[x][i-j]+dp[nod][j]);
                }
            }
        }
    }
    if(x!=0){
        repd(i,sz[x],1){
            dp[x][i]=dp[x][i-1]+score[x];
        }
    }
    
}

int main() {
    int n,k,s;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d%d",&k,&s);
        edge[k].push_back(i);
        score[i]=s;
    }
    dfssz(0);
    dfs(0);
    printf("%d\n",dp[0][m]);
    return 0;
}