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
const int maxn = 200000 + 5;

int p[maxn],c[maxn];
int vis[maxn];
int cnt,flag,id,col;

void dfs(int x){
    if(p[p[x]]==id){
        cnt++;
        return;
    }
    if(c[p[p[x]]]!=col){
        flag=0;
    }
    cnt++;
    dfs(p[p[x]]);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",p+i);
        }
        rep(i,1,n){
            scanf("%d",c+i);
        }
        mst(vis,0);
        int ans=INF,mn=INF;
        rep(i,1,n){
            if(!vis[i]){
                cnt=0;
                flag=1;
                id=i;
                col=c[id];
                dfs(i);
                if(flag){
                    ans=1;break;
                }
                mn=min(cnt,mn);
            }
        }
        if(ans==INF){
            printf("%d\n",mn);
        }
        else{
            ans=2;
            printf("%d\n",ans);
        }
    }
    return 0;
}