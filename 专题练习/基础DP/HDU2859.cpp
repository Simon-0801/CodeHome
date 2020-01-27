#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

int dp[maxn][maxn];
char mp[maxn][maxn];

int main() {
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%s",mp[i]+1);
        }
        int ans=1;
        for(int sz=1;sz<=n;sz++){
            for(int i=1;i<=n-sz+1;i++){
                for(int j=sz;j<=n;j++){
                    if(sz==1){
                        dp[i][j]=1;
                    }
                    else{
                        if(dp[i][j]==sz-1&&dp[i+1][j-1]==sz-1&&mp[i][j-sz+1]==mp[i+sz-1][j]){
                            dp[i][j]=sz;
                            ans=max(ans,dp[i][j]);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}