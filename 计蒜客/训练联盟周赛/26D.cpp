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

char str[25];
string s;
map<string,int> mp;
int vis[35][35];
int dis[35][35];

int main() {
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int t;
        scanf("%d",&t);
        mp.clear();
        mst(vis,0);
        mst(dis,0x3f);
        rep(i,1,t){
            scanf("%s",str+1);
            s=str+1;
            mp[s]=1;
        }
        int n,m,u,v;
        scanf("%d%d",&n,&m);
        rep(i,1,n)  dis[i][i]=0;
        rep(i,1,m){
            scanf("%d%d%s",&u,&v,str+1);
            s=str+1;
            u++,v++;
            if(!mp.count(s)){
                dis[u][v]=1;
                dis[v][u]=1;
            }
        }
        rep(k,1,n){
            rep(i,1,n){
                rep(j,1,n){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        if(dis[1][n]!=INF){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}