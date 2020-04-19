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
const int maxn = 100000 + 5;

vector<int> g[maxn];
int vis[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,tmp;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",&k);
            g[i].clear();
            rep(j,1,k){
                scanf("%d",&tmp);
                g[i].push_back(tmp);
            }
        }
        int ansi=0,ansj=0;
        mst(vis,0);
        rep(i,1,n){
            int f=0;
            for(auto &x:g[i]){
                if(!vis[x]){
                    vis[x]=1;
                    f=1;
                    break;
                }
            }
            if(f==0){
                ansi=i;
            }
        }
        if(ansi){
            repd(i,n,1){
                if(!vis[i]){
                    ansj=i;
                    break;
                }
            }
            printf("IMPROVE\n%d %d\n",ansi,ansj);
        }
        else{
            printf("OPTIMAL\n");
        }
    }
    return 0;
}