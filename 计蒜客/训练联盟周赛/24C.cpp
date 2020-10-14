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

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%s",mp[i]+1);
    }
    rep(i,1,n){
        int f=0;
        rep(j,1,n){
            if(mp[i][j]=='K'){
                rep(x,-1,1){
                    rep(y,-1,1){
                        if(x==0&&y==0)  continue;
                        if(i+x>=1&&i+x<=n&&j+y>=1&&j+y<=n){
                            vis[i+x][j+y]=1;
                        }
                    }
                }
                f=1;
                break;
            }
        }
        if(f)  break;
    }
    int ans=0;
    rep(i,1,n){
        rep(j,1,n){
            if(mp[i][j]=='*'&&!vis[i][j]){
                if(i+1<=n&&j+1<=n&&mp[i+1][j+1]=='-'){
                    vis[i][j]=1;
                    if(j+2<=n)  vis[i][j+2]=1;
                    ans++;
                }
                else{
                    if(i+1<=n&&j-1>=1&&mp[i+1][j-1]=='-'){
                        vis[i][j]=1;
                        ans++;
                    }
                }
            }
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            if(mp[i][j]=='*'&&!vis[i][j]){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}