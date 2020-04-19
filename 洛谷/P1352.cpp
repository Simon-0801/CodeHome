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
const int maxn = 6000 + 5;

int a[maxn];
VI son[maxn];
int vis[maxn];
int dp[maxn][2];

void dfs(int x){
    if(son[x].size()==0){
        dp[x][0]=0;
        dp[x][1]=a[x];
        return;
    }
    dp[x][0]=0;
    dp[x][1]=a[x];
    for(auto &tmp:son[x]){
        dfs(tmp);
        dp[x][0]+=max(dp[tmp][0],dp[tmp][1]);
        dp[x][1]+=dp[tmp][0];
    }
}

int main() {
    int n;
    int fa,s,root;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",a+i);
    }
    rep(i,1,n-1){
        scanf("%d%d",&s,&fa);
        vis[s]=1;
        son[fa].push_back(s);
    }
    rep(i,1,n){
        if(!vis[i]){
            root=i;
            break;
        }
    }
    dfs(root);
    printf("%d\n",max(dp[root][0],dp[root][1]));
    return 0;
}