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
const int maxn = 300000 + 5;

int dp[maxn];

int main() {
    int m,s,t;
    scanf("%d%d%d",&m,&s,&t);
    dp[0]=0;
    rep(i,1,t){
        if(m>=10)  dp[i]=dp[i-1]+60,m-=10;
        else  dp[i]=dp[i-1],m+=4;
    }
    rep(i,1,t){
        if(dp[i]<dp[i-1]+17)  dp[i]=dp[i-1]+17;
        if(dp[i]>=s){
            printf("Yes\n");
            printf("%d\n",i);
            return 0;
        }
    }
    printf("No\n");
    printf("%d\n",dp[t]);
    return 0;
}