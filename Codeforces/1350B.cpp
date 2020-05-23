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

int s[maxn];
int dp[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",s+i);
            dp[i]=1;
        }
        rep(i,1,n){
            int j=2;
            while(i*j<=n){
                if(s[i]<s[i*j]){
                    dp[i*j]=max(dp[i*j],dp[i]+1);
                }
                j++;
            }
        }
        int ans=0;
        rep(i,1,n){
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}