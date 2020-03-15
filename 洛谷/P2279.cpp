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
const int maxn = 1000 + 5;

vector<int> son[maxn];
int dp[maxn][5];

void dfs(int now){
    if(son[now].size()==0){
        dp[now][3]=dp[now][4]=0;
        dp[now][0]=dp[now][1]=dp[now][2]=1;
        return;
    }
    for(auto &x:son[now]){
        dfs(x);
    }
    for(auto &x:son[now]){
        dp[now][0]+=dp[x][4];
    }
    dp[now][0]++;
    int tmp=INF,sz=son[now].size();
    rep(i,0,sz-1){
        int sum=0;
        rep(j,0,sz-1){
            if(i==j)  continue;
            sum+=dp[son[now][j]][3];
        }
        sum+=dp[son[now][i]][0];
        tmp=min(tmp,sum);
    }
    dp[now][1]=min(tmp,dp[now][0]);
    tmp=INF;
    rep(i,0,sz-1){
        int sum=0;
        rep(j,0,sz-1){
            if(i==j)  continue;
            sum+=dp[son[now][j]][2];
        }
        sum+=dp[son[now][i]][1];
        tmp=min(tmp,sum);
    }
    dp[now][2]=min(tmp,dp[now][1]);
    for(auto &x:son[now]){
        dp[now][3]+=dp[x][2];
    }
    dp[now][3]=min(dp[now][3],dp[now][2]);
    for(auto &x:son[now]){
        dp[now][4]+=dp[x][3];
    }
    dp[now][4]=min(dp[now][4],dp[now][3]);
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,fa;
    scanf("%d",&n);
    rep(i,2,n){
        scanf("%d",&fa);
        son[fa].push_back(i);
    }
    dfs(1);
    printf("%d\n",dp[1][2]);
    return 0;
}