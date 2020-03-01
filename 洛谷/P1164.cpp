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

int dp[maxn];
int a[105];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",a+i);
    }
    mst(dp,0);
    dp[0]=1;
    rep(i,1,n){
        repd(j,m,a[i]){
            dp[j]+=dp[j-a[i]];
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}