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

struct node
{
    int t,f,h;

    bool operator< (const node& a) const {
        return t<a.t;
    }
}p[maxn];


int dp[maxn][maxn];

int main() {
    int d,g;
    scanf("%d%d",&d,&g);
    rep(i,1,g){
        scanf("%d%d%d",&p[i].t,&p[i].f,&p[i].h);
    }
    sort(p+1,p+g+1);
    mst(dp,0xcf);
    dp[0][0]=10;
    p[0].t=0;
    p[0].f=0;
    p[0].h=0;
    rep(i,1,g){
        rep(j,0,d){
            if(dp[i-1][j]!=0xcfcfcfcf&&dp[i-1][j]>=p[i].t-p[i-1].t){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+p[i].f-p[i].t+p[i-1].t);
            }
            if(dp[i-1][j-p[i].h]!=0xcfcfcfcf&&dp[i-1][j-p[i].h]>=p[i].t-p[i-1].t){
                dp[i][j]=max(dp[i][j],dp[i-1][j-p[i].h]-p[i].t+p[i-1].t);
            }
        }
        if(dp[i][d]>=0){
            printf("%d\n",p[i].t);
            return 0;
        }
    }
    int sum=0,left=10;
    rep(i,1,g){
        if(p[i].t-p[i-1].t<=left){
            sum=p[i].t;
            left+=p[i].f;
            left-=p[i].t-p[i-1].t;
        }
        else{
            sum+=left;
            printf("%d\n",sum);
            return 0;
        }
    }
    sum+=left;
    printf("%d\n",sum);
    return 0;
}