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
const int maxn = 2000 + 5;

char mp[maxn][maxn];
int lft[maxn][maxn];
int up[maxn][maxn],dwn[maxn][maxn];
vector<int> sta;                    //单调栈

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%s",mp[i]+1);
        rep(j,1,m){
            lft[i][j]=1;            //初始化可拓展的长度为1
            up[i][j]=dwn[i][j]=i;   //初始化最远可到达的行为当前行
        }
    }
    rep(i,1,n){
        rep(j,2,m){
            if(mp[i][j]==mp[i][j-1])  lft[i][j]=lft[i][j-1]+1;  //利用左边一个位置的lft更新当前位置的lft
        }
    }
    int ans=0;
    rep(j,1,m){                 //按列遍历
        sta.clear();
        sta.push_back(0);       //预先压入第0行的高度（为0），保证栈不会空
        rep(i,1,n){             //正着扫一遍单调栈
            int tp=sta.back();
            if(lft[i][j]>lft[tp][j]){
                sta.push_back(i);
            }
            else{
                while(!sta.empty()&&lft[sta.back()][j]>=lft[i][j]){
                    sta.pop_back();
                }
                up[i][j]=sta.back()+1;
                sta.push_back(i);
            }
        }
        sta.clear();
        sta.push_back(n+1);     //预先压入第n+1行的高度（为0），保证栈不会空
        repd(i,n,1){            //反着扫一遍单调栈
            int tp=sta.back();
            if(lft[i][j]>lft[tp][j]){
                sta.push_back(i);
            }
            else{
                while(!sta.empty()&&lft[sta.back()][j]>=lft[i][j]){
                    sta.pop_back();
                }
                dwn[i][j]=sta.back()-1;
                sta.push_back(i);
            }
        }
        rep(i,1,n){
            ans=max(ans,min(lft[i][j],dwn[i][j]-up[i][j]+1));
        }
    }
    printf("%d\n",ans*ans);
    return 0;
}