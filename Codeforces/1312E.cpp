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
const int maxn = 500 + 5;

int dp[maxn][maxn];
int a[maxn];
int f[maxn];

int main() {
    int n;scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",a+i);
        dp[i][i]=a[i];
    }
    rep(len,2,n){
        rep(l,1,n+1-len){
            int r=l+len-1;
            rep(k,l,r-1){
                if(dp[l][k]&&dp[l][k]==dp[k+1][r]){
                    dp[l][r]=dp[l][k]+1;
                }
            }
        }
    }
    mst(f,0x3f);
    f[0]=0;
    rep(i,1,n){
        rep(j,1,i){
            if(dp[j][i]){
                f[i]=min(f[i],f[j-1]+1);
            }
        }
    }
    printf("%d\n",f[n]);
    return 0;
}