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
const int maxn = 1000 + 5;

char mp[maxn][maxn];
int vis[maxn][maxn];
int dir[8][2]={{0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,1},{2,2}};

int n,m;
bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m)  return true;
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%s",mp[i]+1);
    }
    rep(i,1,n){
        rep(j,1,m){
            // if(vis[i][j])  continue;
            if(mp[i][j]=='.')  continue;
            // vis[i][j]=1;
            int f=1;
            rep(k,0,7){
                int x=i+dir[k][0],y=j+dir[k][1];
                if(check(x,y)&&mp[x][y]=='#'){
                    
                }
                else{
                    f=0;
                    break;
                }
            }
            if(f){
                rep(k,0,7){
                    int x=i+dir[k][0],y=j+dir[k][1];
                    vis[x][y]=1;
                }
            }
        }
    }
    rep(i,1,n){
        rep(j,1,m){
            if(mp[i][j]=='#'&&vis[i][j]==0){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}