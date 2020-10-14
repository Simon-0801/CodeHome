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
const int maxn = 100000 + 5;

char str[105];
int dp[105];

int main() {
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        ++cas;
        int c,d;
        scanf("%d%d",&c,&d);
        scanf("%s",str+1);
        printf("Day #%d\n%d %d\n%s\n",cas,c,d,str+1);
        dp[1]=0;
        rep(i,2,c){
            if(str[i]=='X')  dp[i]=INF;
            else{
                dp[i]=INF;
                rep(j,0,d){
                    if(i-j-1>=1){
                        dp[i]=min(dp[i-j-1]+1,dp[i]);
                    }
                }
            }
        }
        printf("%d\n\n",dp[c]==INF?0:dp[c]);
    }
    return 0;
}