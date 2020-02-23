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

int v[6][6]={   
                {0,0,0,0,0,0},
                {0,5,-1,-2,-1,-3},
                {0,-1,5,-3,-2,-4},
                {0,-2,-3,5,-2,-2},
                {0,-1,-2,-2,5,-1},
                {0,-3,-4,-2,-1,0}
            };

char stra[maxn],strb[maxn];
int a[maxn],b[maxn];
int dp[maxn][maxn];

int main() {
    int la,lb;
    scanf("%d %s",&la,stra+1);
    mst(dp,0xcf);
    dp[0][0]=0;
    rep(i,1,la){
        if(stra[i]=='A')  a[i]=1;
        if(stra[i]=='C')  a[i]=2;
        if(stra[i]=='G')  a[i]=3;
        if(stra[i]=='T')  a[i]=4;
        dp[i][0]=dp[i-1][0]+v[a[i]][5];
    }
    scanf("%d %s",&lb,strb+1);
    rep(i,1,lb){
        if(strb[i]=='A')  b[i]=1;
        if(strb[i]=='C')  b[i]=2;
        if(strb[i]=='G')  b[i]=3;
        if(strb[i]=='T')  b[i]=4;
        dp[0][i]=dp[0][i-1]+v[5][b[i]];
    }
    rep(i,1,la){
        rep(j,1,lb){
            dp[i][j]=max(dp[i-1][j]+v[a[i]][5],dp[i][j]);
            dp[i][j]=max(dp[i][j-1]+v[5][b[j]],dp[i][j]);
            dp[i][j]=max(dp[i-1][j-1]+v[a[i]][b[j]],dp[i][j]);
        }
    }
    printf("%d\n",dp[la][lb]);
    return 0;
}