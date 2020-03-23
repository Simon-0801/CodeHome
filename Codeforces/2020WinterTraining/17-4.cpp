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
const int maxn = 5000 + 5;

char a[maxn],b[maxn];
ll dp[maxn][maxn];

int main() {
    scanf("%s",a+1);
    scanf("%s",b+1);
    int lena=strlen(a+1);
    int lenb=strlen(b+1);
    rep(i,1,lena){
        rep(j,1,lenb){
            dp[i][j]=dp[i][j-1]%mod;
            if(a[i]==b[j]){
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]+1)%mod;
            }
        }
    }
    ll ans=0;
    rep(i,1,lena)  ans=(ans+dp[i][lenb])%mod;
    printf("%lld\n",ans);
    return 0;
}