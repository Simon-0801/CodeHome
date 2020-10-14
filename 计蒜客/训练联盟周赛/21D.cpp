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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

ll a[maxn];
int len[maxn];

VI sta;
int f[maxn][35];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,n) scanf("%lld",&a[i]),len[i]=0,f[i][0]=0;
        sta.clear();
        sta.push_back(0);
        a[0]=1e18;      //在栈底设置一个无穷大
        repd(i,n,1){
            while(!sta.empty()&&a[sta.back()]<=a[i]){       //单调栈
                sta.pop_back();
            }
            f[i][0]=sta.back();
            sta.push_back(i);
        }
        len[0]=0;
        repd(i,n,1)  len[i]=len[f[i][0]]+1;     //求取每个位置的上升子序列长度
        rep(j,1,30){        //预处理出f[i][k]
            f[0][j-1]=0;
            rep(i,1,n){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }
        int x,y;
        rep(q,1,m){
            scanf("%d%d",&x,&y);
            if(len[x]<y){
                printf("-1\n");
            }
            else{
                int p=0;
                y--;
                while(y){       //将y划分为2的幂次
                    if(y&1){
                        x=f[x][p];
                    }
                    p++;
                    y>>=1;
                }
                printf("%d\n",x);
            }
        }
    }
    return 0;
}