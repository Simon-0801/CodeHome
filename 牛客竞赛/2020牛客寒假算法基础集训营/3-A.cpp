#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
const int mod=1e9+7;

char mp[maxn][maxn];
int dp[maxn][maxn];
int n,m;

bool check(int i,int j){
    if(i>=1&&i<=n&&j>=1&&j<=m)  return true;
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",mp[i]+1);
    }
    memset(dp,0,sizeof dp);
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)  continue;
            if(check(i-1,j)&&(mp[i-1][j]=='D'||mp[i-1][j]=='B')){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            }
            if(check(i,j-1)&&(mp[i][j-1]=='R'||mp[i][j-1]=='B')){
                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            }
        }
    }
    printf("%d\n",dp[n][m]%mod);
    return 0;
}