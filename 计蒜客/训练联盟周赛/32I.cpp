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
const int maxn = 300000 + 5;

int x[maxn];
int mx[maxn];
int dp[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",x+i);
    }
    rep(i,m+1,n){
        dp[i]=dp[i-1];
        dp[i]=max(dp[i],mx[i-m]+x[i]);
        mx[i]=max(dp[i],mx[i-1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}