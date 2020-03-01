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
const int maxn = 100 + 5;

int mp[maxn][maxn];
int sta[maxn],sz;
int w[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%d",&mp[i][j]);
        }
    }
    rep(i,2,n){
        rep(j,1,m){
            if(!mp[i][j])  continue;
            mp[i][j]=mp[i-1][j]+1;
        }
    }
    int ans=-1;
    rep(i,1,n){
        sz=0;
        sta[sz]=0;
        mp[i][m+1]=0;
        rep(j,1,m+1){
            if(mp[i][j]>sta[sz]){
                sta[++sz]=mp[i][j];
                w[sz]=1;
                continue;
            }
            int width=0;
            while(sz&&mp[i][j]<=sta[sz]){
                width+=w[sz];
                ans=max(ans,min(sta[sz],width));
                sz--;
            }
            sta[++sz]=mp[i][j],w[sz]=width+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}