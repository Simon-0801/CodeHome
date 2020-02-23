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
const int maxn = (1<<15) + 2;

double dp[maxn][16];
int n;

struct point
{
    double x,y;
}p[18];

double dist(point a,point b){
    double tmp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(tmp);
}

struct node
{
    int state,id;
    double dis;
};

queue<node> q;

void solve(){
    dp[0][0]=0;
    rep(i,1,n){
        dp[(1<<(i-1))][i]=dist(p[0],p[i]);
    }
    rep(state,1,(1<<n)-1){
        rep(id,1,n){
            if(((1<<(id-1))&state)==0)  continue;
            if(state==(1<<(id-1)))  continue;
            rep(i,1,n){
                if(i==id||((1<<(i-1))&state==0))  continue;
                dp[state][id]=min(dp[state][id],dp[state-(1<<(id-1))][i]+dist(p[i],p[id]));
            }
        }
    }
    // while(!q.empty()){
    //     node tp=q.front();
    //     q.pop();
    //     int state=tp.state,id=tp.id;
    //     double dis=tp.dis;
    //     if(dp[state][id]==0){
    //         dp[state][id]=dis;
    //     }
    //     else{
    //         dp[state][id]=min(dis,dp[state][id]);
    //     }
    //     node nxt;
    //     rep(i,0,n-1){
    //         if(((1<<i)&state)==0){
    //             nxt.state=(state|(1<<i));
    //             nxt.id=i+1;
    //             nxt.dis=dis+dist(p[i+1],p[id]);
    //             q.push(nxt);
    //         }
    //     }
    // }
}

int main() {
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    p[0].x=0;
    p[0].y=0;
    mst(dp,127);
    solve();
    double ans=1e18;
    rep(i,1,n){
        ans=min(ans,dp[(1<<n)-1][i]);
    }
    printf("%.2lf\n",ans);
    // mst(dp,-1);
    return 0;
}