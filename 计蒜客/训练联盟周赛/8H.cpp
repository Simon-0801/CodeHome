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
const int maxn = 100 + 5;

int num[maxn];
int LIS[maxn][maxn];
int dp[maxn][maxn];
int dpp[maxn];
vector<int> ans;

int getLIS(int l,int r){
    dpp[1]=num[l];   //初始化dp[1]
    int len=1;
    for(int i=l+1;i<=r;i++){
        int l=1,r=len,res;
        if(dpp[len]<num[i]){     //自成一组
            len++;
            dpp[len]=num[i];
            continue;
        }
        while(l<=r){        //二分查找dp数组中比p[i].y大的最小数
            int mid=(l+r)/2;
            if(dpp[mid]>=num[i])  r=mid-1,res=mid;
            else  l=mid+1;
        }
        dpp[res]=num[i];     //更新dp数组
    }
    return len;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",num+i);
        }
        rep(i,1,n){
            rep(j,i,n){
                LIS[i][j]=getLIS(i,j);
            }
        }
        ans.clear();
        rep(k,1,n){
            mst(dp,0);
            rep(len,k,n){
                rep(l,1,n+1-len){
                    int r=l+len-1;
                    if(LIS[l][r]>=k)  dp[l][r]=LIS[l][r]; 
                }
            }
            rep(len,1,n){
                rep(l,1,n+1-len){
                    int r=l+len-1;
                    rep(mid,l,r-1){
                        dp[l][r]=max(dp[l][mid]+dp[mid+1][r],dp[l][r]);
                    }
                }
            }
            ans.push_back(dp[1][n]);
        }
        int anslen=ans.size();
        rep(i,0,anslen-1){
            printf("%d%c",ans[i],i==anslen-1?'\n':' ');
        }
    }
    return 0;
}