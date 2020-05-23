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
const int maxn = 1000000 + 5;

char str[maxn];
int sum[maxn];
int dp[2][maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",str+1);
        sum[0]=0;
        dp[0][0]=dp[1][0]=0;
        rep(i,1,n){
            sum[i]=sum[i-1]+str[i]-'0';
        }
        rep(i,1,n){
            if(str[i]=='1'){
                dp[0][i]=1+min(dp[0][i-1],dp[1][i-1]);
                if(i<=k){
                    dp[1][i]=sum[i-1];
                }
                else{
                    dp[1][i]=min(dp[1][i-k]+sum[i-1]-sum[i-k],sum[i-1]);
                }
            }
            else{
                dp[0][i]=min(dp[0][i-1],dp[1][i-1]);
                if(i<=k){
                    dp[1][i]=1+sum[i-1];
                }
                else{
                    dp[1][i]=1+min(dp[1][i-k]+sum[i-1]-sum[i-k],sum[i-1]);
                }
            }
        }
        printf("%d\n",min(dp[0][n],dp[1][n]));
    }
    return 0;
}