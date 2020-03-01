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
const int maxn = 1000 + 5;

int num[maxn][maxn],dp[maxn][maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        rep(j,1,i){
            scanf("%d",&num[i][j]);
        }
    }
    rep(i,1,n){
        dp[n][i]=num[n][i];
    }
    repd(i,n-1,1){
        rep(j,1,i){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}