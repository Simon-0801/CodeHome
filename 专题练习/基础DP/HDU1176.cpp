#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int dp[11][maxn],num[11][maxn];

int main() {
    int n,x,t,maxtime;
    while(scanf("%d",&n)&&n){
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        maxtime=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&t);
            num[x][t]++;
            maxtime=max(t,maxtime);
        }
        for(int i=1;i<=maxtime;i++){
            if(i==1){
                for(int j=4;j<=6;j++){
                    if(j==0){
                        dp[j][i]=max(dp[j][i-1],dp[j+1][i-1])+num[j][i];
                    }
                    else if(j==10){
                        dp[j][i]=max(dp[j][i-1],dp[j-1][i-1])+num[j][i];
                    }
                    else{
                        dp[j][i]=max(dp[j][i-1],max(dp[j+1][i-1],dp[j-1][i-1]))+num[j][i];
                    }
                }
                continue;
            }
            else if(i==2){
                for(int j=3;j<=7;j++){
                    if(j==0){
                        dp[j][i]=max(dp[j][i-1],dp[j+1][i-1])+num[j][i];
                    }
                    else if(j==10){
                        dp[j][i]=max(dp[j][i-1],dp[j-1][i-1])+num[j][i];
                    }
                    else{
                        dp[j][i]=max(dp[j][i-1],max(dp[j+1][i-1],dp[j-1][i-1]))+num[j][i];
                    }
                }
                continue;
            }
            else if(i==3){
                for(int j=2;j<=8;j++){
                    if(j==0){
                        dp[j][i]=max(dp[j][i-1],dp[j+1][i-1])+num[j][i];
                    }
                    else if(j==10){
                        dp[j][i]=max(dp[j][i-1],dp[j-1][i-1])+num[j][i];
                    }
                    else{
                        dp[j][i]=max(dp[j][i-1],max(dp[j+1][i-1],dp[j-1][i-1]))+num[j][i];
                    }
                }
                continue;
            }
            else if(i==4){
                for(int j=1;j<=9;j++){
                    if(j==0){
                        dp[j][i]=max(dp[j][i-1],dp[j+1][i-1])+num[j][i];
                    }
                    else if(j==10){
                        dp[j][i]=max(dp[j][i-1],dp[j-1][i-1])+num[j][i];
                    }
                    else{
                        dp[j][i]=max(dp[j][i-1],max(dp[j+1][i-1],dp[j-1][i-1]))+num[j][i];
                    }
                }
                continue;
            }
            else{
                for(int j=0;j<11;j++){
                    if(j==0){
                        dp[j][i]=max(dp[j][i-1],dp[j+1][i-1])+num[j][i];
                    }
                    else if(j==10){
                        dp[j][i]=max(dp[j][i-1],dp[j-1][i-1])+num[j][i];
                    }
                    else{
                        dp[j][i]=max(dp[j][i-1],max(dp[j+1][i-1],dp[j-1][i-1]))+num[j][i];
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<11;i++){
            ans=max(ans,dp[i][maxtime]);
        }
        printf("%d\n",ans);
    }
    return 0;
}