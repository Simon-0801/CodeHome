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


VI edge[maxn];
int dis[maxn],vis[maxn];
int n;

struct point{
    int val,id;
    point(int id,int val):id(id),val(val) {}
    bool operator <(const point &x)const{ 
        return val>x.val;
    }
};
 
void dijkstra(int s){
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dis[i]=INF;
 
    priority_queue<point> q;
    q.push(point(s,0));
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){
        int cur=q.top().id;
        q.pop();
        vis[cur]=1;
        if(cur==n)  return;
        for(int i=0; i < edge[cur].size() ; i++){
            int id=edge[cur][i];
            // int cost=gra[cur][i].w;
            if(!vis[id]&&dis[id]>dis[cur]+1){
            	dis[id]=dis[cur]+1;
            	q.push(point(id,dis[id]));
            }
        }
    }
}


int main() {
    int m,u,v;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dijkstra(1);
    printf("%d\n",dis[n]-1);
    return 0;
}