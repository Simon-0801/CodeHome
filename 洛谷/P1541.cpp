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
const int maxn = 40 + 5;

int aa[355],cnt[5];
int dp[maxn][maxn][maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n-1){
        scanf("%d",aa+i);
    }
    int tmp;
    rep(i,1,m){
        scanf("%d",&tmp);
        if(tmp==1)  cnt[1]++;
        if(tmp==2)  cnt[2]++;
        if(tmp==3)  cnt[3]++;
        if(tmp==4)  cnt[4]++;
    }
    rep(a,0,cnt[1]){
        rep(b,0,cnt[2]){
            rep(c,0,cnt[3]){
                rep(d,0,cnt[4]){
                    if(a==0&&b==0&&c==0&&d==0)  dp[a][b][c][d]=aa[0];
                    else{
                        int dis=a+b*2+c*3+d*4;
                        if(a)  dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+aa[dis]);
                        if(b)  dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+aa[dis]);
                        if(c)  dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+aa[dis]);
                        if(d)  dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+aa[dis]);
                    }
                }
            }
        }
    }
    printf("%d\n",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}