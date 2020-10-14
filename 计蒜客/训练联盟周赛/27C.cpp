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
const int maxn = 5000 + 5;

int val[maxn],cnt[maxn];
int mxcnt,sumval;
ll dp[maxn][maxn];

int main() {
    int t;
    scanf("%d",&t);
    rep(cas,1,t){
        int S,n;
        scanf("%d%d",&S,&n);
        mxcnt=0;
        sumval=0;
        rep(i,1,n){
            scanf("%d%d",val+i,cnt+i);
            mxcnt=max(mxcnt,cnt[i]);
            sumval+=val[i];
        }
        mst(dp,0);
        rep(c,1,mxcnt){
            if(sumval*c<S)  continue;
            dp[c][0]=1;
            if(S%c!=0)  continue;
            rep(i,1,n){
                if(cnt[i]<c)  continue;
                repd(j,S,c*val[i]){
                    dp[c][j]+=dp[c][j-c*val[i]];
                }
            }
        }
        ll ans=0;
        rep(i,1,mxcnt){
            ans+=dp[i][S];
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}