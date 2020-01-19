#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 500 + 5;

int a[maxn],b[maxn];
int dp[505][505] = {0};
int op[maxn][maxn];
int indexi,indexj;
vector<int> v;

int lengthOfLCIS(int *a, int n, int *b, int m) {
    int ans = 0;
    int max_dp = 0;
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            dp[i + 1][j + 1] = dp[i][j + 1];
            op[i+1][j+1]=j+1;
            if (a[i] == b[j]) {
                max_dp = 0;
                for (int k = 0 ; k < j ; ++k) {
                    if (b[j] > b[k] && max_dp <= dp[i][k + 1]) {
                        max_dp = dp[i][k + 1];
                        op[i+1][j+1]=k+1;
                    }
                }
                dp[i + 1][j + 1] = max_dp + 1;
            }
            if(dp[i+1][j+1]>ans){
                ans=dp[i+1][j+1];
                indexi=i+1;
                indexj=j+1;
            }
        }
    }
    return ans;
}

int main() {
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int len=lengthOfLCIS(a,n,b,m);
    v.push_back(b[indexj-1]);
    for(int i=1;i<=len-1;i++){
        while(indexi>=0&&op[indexi][indexj]==indexj){
            indexi--;
        }
        v.push_back(b[op[indexi][indexj]-1]);
        indexj=op[indexi][indexj];
        indexi--;
    }
    printf("%d\n",len);
    for(int i=1;i<=len;i++){
        printf("%d%c",v.back(),i==len?'\n':' ');
        v.pop_back();
    }
    return 0;
}