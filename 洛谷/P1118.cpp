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
const int maxn = 100000 + 5;

int c[15][15];
int n,sum;
int a[15],vis[15];

bool dfs(int id,int tsum){
    if(id>n&&tsum==sum){
        rep(i,1,n){
            printf("%d%c",a[i],i==n?'\n':' ');
        }
        return true;
    }
    if(tsum>=sum)  return false;
    rep(i,1,n){
        if(vis[i])  continue;
        vis[i]=1;
        a[id]=i;
        if(dfs(id+1,tsum+c[n-1][id-1]*i))  return true;
        vis[i]=0;
        a[id]=0;
    }
    return false;
}

int main() {
    scanf("%d%d",&n,&sum);
    c[0][0]=1;
    c[1][0]=c[1][1]=1;
    rep(i,2,n){
        c[i][0]=c[i][i]=1;
        rep(j,1,i-1){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    mst(a,0);
    mst(vis,0);
    dfs(1,0);
    return 0;
}