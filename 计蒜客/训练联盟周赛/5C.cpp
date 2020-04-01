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

int vis[55][55];
int mpr[55][55],mpc[55][55];

int main() {
    int t;
    scanf("%d",&t);
    rep(cas,1,t){
        int n,q,col,row;
        scanf("%d%d",&n,&q);
        mst(mpc,0);
        mst(mpr,0);
        mst(vis,0);
        int ans=0;
        rep(i,1,q){
            scanf("%d%d",&row,&col);
            if(vis[row][col]){
                // printf("--%d %d\n",row,col);
                ans++;
                continue;
            }
            vis[row][col]=1;
            mpr[row][col]=mpc[row][col]=1;
            rep(i,1,n){
                if(i==row)  continue;
                if(!mpr[i][col]){
                    mpr[i][col]=1;
                    if(mpr[i][col]==1&&mpc[i][col]==1){
                        vis[i][col]=1;
                    }
                }
            }
            rep(i,1,n){
                if(i==col)  continue;
                if(!mpc[row][i]){
                    mpc[row][i]=1;
                    if(mpc[row][i]==1&&mpr[row][i]==1){
                        vis[row][i]=1;
                    }
                }
            }
        }
        printf("Strategy #%d: %d\n\n",cas,ans);
    }
    return 0;
}