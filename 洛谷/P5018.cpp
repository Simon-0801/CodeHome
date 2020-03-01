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
const int maxn = 1000000 + 5;

int val[maxn];
int son[maxn][2];
int sz[maxn];

int dfs(int root){
    if(root==-1)  return 0;
    sz[root]=1;
    sz[root]+=dfs(son[root][0]);
    sz[root]+=dfs(son[root][1]);
    return sz[root];
}

bool check(int a,int b){
    if(a==-1&&b==-1)  return true;
    if(a!=-1&&b!=-1&&val[a]==val[b]&&check(son[a][0],son[b][1])&&check(son[a][1],son[b][0]))  return true;
    return false;
}

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",val+i);
    }
    rep(i,1,n){
        scanf("%d%d",&son[i][0],&son[i][1]);
    }
    int ans=-1;
    dfs(1);
    rep(i,1,n){
        if(check(son[i][0],son[i][1]))  ans=max(ans,sz[i]);
    }
    printf("%d\n",ans);
    return 0;
}