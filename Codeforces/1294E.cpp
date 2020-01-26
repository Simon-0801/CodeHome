#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;
const int INF = 0x3f3f3f3f;

vector<int> num[maxn];
int dp[maxn];

int main() {
    int n,m,tmp;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tmp);
            num[j].push_back(tmp);
        }
    }
    ll sum=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++)  dp[j]=0;
        for(int j=0;j<n;j++){
            if((num[i][j]-i+m)%m==0&&(num[i][j]-i)/m<n){
                dp[(j-(num[i][j]-i)/m+n)%n]++;
            }
        }
        int mmin=INF;
        for(int j=0;j<n;j++){
            mmin=min(mmin,n-dp[j]+j);
        }
        sum+=(ll)mmin;
    }
    printf("%I64d\n",sum);
    return 0;
}