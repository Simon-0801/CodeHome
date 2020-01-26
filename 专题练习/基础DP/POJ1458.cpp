#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

int dp[maxn][maxn];
char a[maxn],b[maxn];

int main() {
    while(scanf("%s %s",a,b)!=EOF){
        memset(dp,0,sizeof dp);
        int n=strlen(a),m=strlen(b);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1]==b[j-1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}