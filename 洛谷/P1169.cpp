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
const int maxn = 2000 + 5;

int mp[maxn][maxn];
int lft[maxn][maxn],rgt[maxn][maxn],up[maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%d",&mp[i][j]);
            lft[i][j]=rgt[i][j]=j;
            up[i][j]=1;
        }
    }
    rep(i,1,n){
        rep(j,2,m){
            if(mp[i][j]!=mp[i][j-1]){
                lft[i][j]=lft[i][j-1];
            }
        }
        repd(j,m-1,1){
            if(mp[i][j]!=mp[i][j+1]){
                rgt[i][j]=rgt[i][j+1];
            }
        }
    }
    int ans1=0,ans2=0;
    rep(i,1,n){
        rep(j,1,m){
            if(i>1&&mp[i][j]!=mp[i-1][j]){
                lft[i][j]=max(lft[i-1][j],lft[i][j]);
                rgt[i][j]=min(rgt[i-1][j],rgt[i][j]);
                up[i][j]=up[i-1][j]+1;
            }
            int len=rgt[i][j]-lft[i][j]+1;
            int wid=up[i][j];
            int tmp=min(len,wid);
            ans1=max(ans1,tmp*tmp);
            ans2=max(ans2,len*wid);
        }
    }
    printf("%d\n%d\n",ans1,ans2);
    return 0;
}