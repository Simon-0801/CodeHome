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
const int maxn = 10000 + 5;

struct node
{
    int p,t;
    
    bool operator< (const node& a) const {
        return p>a.p;
    }
}ta[maxn];

int dp[maxn],cnt[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    mst(cnt,0);
    mst(dp,0);
    rep(i,1,k){
        scanf("%d%d",&ta[i].p,&ta[i].t);
        cnt[ta[i].p]++;
    }
    sort(ta+1,ta+k+1);
    int l=1;
    repd(i,n,1){
        if(cnt[i]==0)  dp[i]=dp[i+1]+1;
        else{
            rep(j,1,cnt[i]){
                dp[i]=max(dp[i],dp[i+ta[l].t]);
                l++;
            }
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}