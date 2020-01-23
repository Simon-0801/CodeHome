#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 500 + 5;

int dp[maxn][maxn],p[maxn][maxn];
int a[maxn],b[maxn];
vector<int> v;
int n,m,ans,path;

void LCIS(int a[],int n,int b[],int m){
    for(int i=1;i<=n;i++){//外层循环
        int maxlen=0,pre=0;//maxlen代表dp[i-1][k]中的最大值，pre代表当前maxlen下的前一个B序列中选出的值（记录路径）
        for(int j=1;j<=m;j++){
            //这里假设Ai和Bj不等
            dp[i][j]=dp[i-1][j];
            p[i][j]=p[i-1][j];
            if(a[i]==b[j]&&dp[i][j]<maxlen+1){//更新dp[i][j]和p[i][j]
                dp[i][j]=maxlen+1;
                p[i][j]=pre;
            }
            if(b[j]<a[i]&&dp[i-1][j]>maxlen){//更新maxlen和pre
                maxlen=dp[i-1][j];
                pre=j;
            }
        }
    }
}

void Print(int pa) {//打印路径
    if(!pa) return;
    Print(p[n][pa]);
    cout<<b[pa]<<" ";
}

int main() {
    memset(dp,0,sizeof(dp));
    memset(p,0,sizeof(p));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    LCIS(a,n,b,m);
    //选出最长路径
    for(int i=1;i<=m;i++){
        if(ans<dp[n][i]){
            ans=dp[n][i];
            path=i;
        }
    }
    printf("%d\n",ans);
    Print(path);
    return 0;
}