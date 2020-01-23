#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

char str[maxn];
ll dp[maxn];
vector<int> v;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(str[i]=='1')  v.push_back(i);
    }
    int j=0,len=v.size();
    if(len==0){
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+i;
        }
        printf("%I64d\n",dp[n]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i<v[j]-k){
            dp[i]=dp[i-1]+i;
        }
        else if(i>=v[j]-k&&i<=v[j]+k){
            dp[i]=min(dp[i-1]+i,dp[max(v[j]-k-1,0)]+v[j]);
        }
        else{
            while(j<len){
                if(i<=v[j]+k)  break;
                j++;
            }
            i--;
            if(j>=len){
                i++;
                dp[i]=dp[i-1]+i;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     dp[i]=dp[i-1]+i;
    // }
    // for(int i=1;i<=n;i++){
    //     if(str[i]=='1'){
    //         if(i+k<=n&&i-k>=1){
    //             if(dp[i+k]>=dp[i-k-1]+i){
    //                 dp[i+k]=dp[i-k-1]+i;
    //                 for(int l=i-k;l<=i+k;l++){
    //                     dp[l]=min(dp[i-k-1]+i,dp[l-1]+l);
    //                 }
    //             }
    //         }
    //         else if(i+k>n&&i-k>=1){
    //             if(dp[n]>=dp[i-k-1]+i){
    //                 dp[n]=dp[i-k-1]+i;
    //                 for(int l=i-k;l<=n;l++){
    //                     dp[l]=min(dp[i-k-1]+i,dp[l-1]+l);
    //                 }
    //             }
    //         }
    //         else if(i+k<=n&&i-k<1){
    //             if(dp[i+k]>=dp[0]+i){
    //                 dp[i+k]=dp[0]+i;
    //                 for(int l=1;l<=i+k;l++){
    //                     dp[l]=min(dp[0]+i,dp[l-1]+l);
    //                 }
    //             }
    //         }
    //         else if(i+k>n&&i-k<1){
    //             if(dp[n]>=dp[0]+i){
    //                 dp[n]=dp[0]+i;
    //                 for(int l=1;l<=n;l++){
    //                     dp[l]=min(dp[0]+i,dp[l-1]+l);
    //                 }
    //             }
    //         }
    //     }
    // }
    printf("%I64d\n",dp[n]);
    return 0;
}