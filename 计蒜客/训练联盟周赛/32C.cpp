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
const int maxn = 1000 + 5;

VI edge[maxn];
ll t[maxn],p[maxn];
ll dis[maxn][maxn];
int vis[maxn][maxn];
ll troad;
int x;

struct point{
    ll time,val,id;
    point(ll time,ll id,ll val):time(time),id(id),val(val) {}
    bool operator <(const point &x)const{ 
        return val>x.val;
    }
};
 
void dijkstra(int s){       //最短路采用Dijkstra
    memset(vis,0,sizeof(vis));
    mst(dis,0x3f);
 
    priority_queue<point> q;
    q.push(point(t[s],s,p[s]));
    vis[t[s]][s]=1;
    dis[t[s]][s]=p[s];
    while(!q.empty()){
        ll cur=q.top().id;
        ll curtime=q.top().time;
        q.pop();
        vis[curtime][cur]=1;
        if(curtime==x&&cur==s)  return;
        if(curtime+t[cur]<=x&&!vis[curtime+t[cur]][cur]&&dis[curtime+t[cur]][cur]>dis[curtime][cur]+p[cur]){
            dis[curtime+t[cur]][cur]=dis[curtime][cur]+p[cur];
            q.push(point(curtime+t[cur],cur,dis[curtime+t[cur]][cur]));
        }
        for(int i=0; i < edge[cur].size() ; i++){
            ll id=edge[cur][i];
            ll cost=p[id];
            if(curtime+troad+t[id]>x)  continue;
            if(!vis[curtime+troad+t[id]][id]&&dis[curtime+troad+t[id]][id]>dis[curtime][cur]+cost){
            	dis[curtime+troad+t[id]][id]=dis[curtime][cur]+cost;
            	q.push(point(curtime+troad+t[id],id,dis[curtime+troad+t[id]][id]));
            }
        }
    }
}


int main() {
    int n,m;
    scanf("%d%d%d%lld",&x,&n,&m,&troad);
    int u,v;
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    rep(i,1,n){
        scanf("%lld%lld",t+i,p+i);
    }
    dijkstra(1);
    if(dis[x][1]==0x3f3f3f3f3f3f3f3f)  printf("It is a trap.\n");
    else  printf("%lld\n",dis[x][1]);
    return 0;
}