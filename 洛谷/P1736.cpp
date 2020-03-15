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
const int maxn = 2500 + 5;

int mp[maxn][maxn];
int dp[maxn][maxn],up[maxn][maxn],lef[maxn][maxn],rig[maxn][maxn];

int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int ans=0;
        rep(i,1,n){
            rep(j,1,m){
                scanf("%d",&mp[i][j]);
            }
        }
        rep(i,1,n){
            rep(j,1,m){
                if(mp[i][j]){
                    up[i][j]=0;
                    lef[i][j]=0;
                }
                else{
                    up[i][j]=up[i-1][j]+1;
                    lef[i][j]=lef[i][j-1]+1;
                }
            }
            repd(j,m,1){
                if(mp[i][j])  rig[i][j]=0;
                else  rig[i][j]=rig[i][j+1]+1;
            }
        }
        rep(i,1,n){
            rep(j,1,m){
                if(mp[i][j]==0)  dp[i][j]=0;
                else{
                    int tmp=min(up[i-1][j],lef[i][j-1]);
                    tmp=min(tmp,dp[i-1][j-1]);
                    dp[i][j]=tmp+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        rep(i,1,n){
            repd(j,m,1){
                if(mp[i][j]==0)  dp[i][j]=0;
                else{
                    int tmp=min(up[i-1][j],rig[i][j+1]);
                    tmp=min(tmp,dp[i-1][j+1]);
                    dp[i][j]=tmp+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);

        // int ans1=0,ans2=0;
        // rep(i,1,n){
        //     rep(j,1,m){
        //         scanf("%d",&mp[i][j]);
        //         if(mp[i][j]){
        //             dp1[1][i][j]=dp2[1][i][j]=1;
        //             ans1=ans2=1;
        //         }
        //         else{
        //             dp1[1][i][j]=dp2[1][i][j]=0;
        //         }
        //     }
        // }
        // int minn=min(n,m);
        // rep(len,2,minn){
        //     int now=(len&1);
        //     rep(i,len,n){
        //         rep(j,len,m){
        //             if(dp1[now^1][i][j]==len-1&&dp1[now^1][i-1][j-1]==len-1&&mp[i][j-len+1]==0&&mp[i-len+1][j]==0){
        //                 dp1[now][i][j]=len;
        //                 ans1=max(len,ans1);
        //             }
        //             else dp1[now][i][j]=0;
        //         }
        //     }
        //     if(ans1<len)  break;
        // }
        // rep(len,2,minn){
        //     int now=(len&1);
        //     rep(i,len,n){
        //         rep(j,1,m-len+1){
        //             if(dp2[now^1][i][j]==len-1&&dp2[now^1][i-1][j+1]==len-1&&mp[i][j+len-1]==0&&mp[i-len+1][j]==0){
        //                 dp2[now][i][j]=len;
        //                 ans2=max(len,ans2);
        //             }
        //             else dp2[now][i][j]=0;
        //         }
        //     }
        //     if(ans2<len)  break;
        // }
        // printf("%d\n",max(ans1,ans2));
    }
    return 0;
}