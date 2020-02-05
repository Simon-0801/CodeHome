#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

char str[maxn];
int sum[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        if(str[i]=='1')  sum[i]=sum[i-1]+1;
        else  sum[i]=sum[i-1];
    }
    int ans=0;
    for(int i=k;i<=n;i++){
        while(i<n&&sum[i+1]==sum[i]) i++;
        int index=lower_bound(sum+1,sum+n+1,sum[i]-k)-sum;
        if(sum[index]==sum[i]-k){
            ans=max(ans,i-index);
        }
        else{
            ans=max(ans,i-index+1);
        }
        // printf("---%d  %d\n",index,ans);
    }
    sum[0]=0;
    for(int i=1;i<=n;i++){
        if(str[i]=='0')  sum[i]=sum[i-1]+1;
        else  sum[i]=sum[i-1];
    }
    for(int i=k;i<=n;i++){
        while(i<n&&sum[i+1]==sum[i]) i++;
        int index=lower_bound(sum+1,sum+n+1,sum[i]-k)-sum;
        if(sum[index]==sum[i]-k){
            ans=max(ans,i-index);
        }
        else{
            ans=max(ans,i-index+1);
        }
        // printf("---%d  %d\n",index,ans);
    }
    printf("%d\n",ans);
    return 0;
}