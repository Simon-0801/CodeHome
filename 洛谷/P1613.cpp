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
const int maxn = 65 + 5;

int vis[maxn][maxn][maxn];
int dis[maxn][maxn];

int main() {
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    mst(dis,0x3f);
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        dis[u][v]=1;
        vis[u][v][0]=1;
    }
    rep(k,1,64){
        rep(x,1,n){
            rep(y,1,n){
                rep(z,1,n){
                    if(vis[x][y][k-1]&&vis[y][z][k-1]){
                        vis[x][z][k]=1;
                        dis[x][z]=1;
                    }
                }
            }
        }
    }
    rep(x,1,n){
        rep(y,1,n){
            rep(z,1,n){
                dis[y][z]=min(dis[y][z],dis[y][x]+dis[x][z]);
            }
        }
    }
    printf("%lld\n",dis[1][n]);
    return 0;
}