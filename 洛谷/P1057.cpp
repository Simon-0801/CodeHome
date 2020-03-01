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
const int maxn = 30 + 5;

int n,m,ans=0;
int dp[maxn][maxn];

int dfs(int id,int cnt){
    if(cnt==m){
        if(id==1)  return dp[id][m-cnt]=1;
        else  return dp[id][m-cnt]=0;
    }
    if(dp[id][m-cnt]!=-1)  return dp[id][m-cnt];
    int tmp=id-1,ans=0;
    if(tmp<1)  tmp=n;
    ans+=dfs(tmp,cnt+1);
    tmp=id+1;
    if(tmp>n)  tmp=1;
    ans+=dfs(tmp,cnt+1);
    return dp[id][m-cnt]=ans;
    // int tmp=id-1;
    // if(tmp<1)  tmp=n;
    // dfs(tmp,cnt+1);
    // tmp=id+1;
    // if(tmp>n)  tmp=1;
    // dfs(tmp,cnt+1);
    // if((id-1)<=(m-cnt)){
    //     int tmp=id-1;
    //     if(tmp<1)  tmp=n;
    //     dfs(tmp,cnt+1);
    // }
    // if((n-id+1)<=(m-cnt)){
    //     int tmp=id+1;
    //     if(tmp>n)  tmp=1;
    //     dfs(tmp,cnt+1);
    // }
}

int main() {
    scanf("%d%d",&n,&m);
    mst(dp,-1);
    printf("%d\n",dfs(1,0));
    return 0;
}