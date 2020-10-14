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

struct Point
{
    int x,y;
};

Point st,en;
int B;
int C[110];
int T;
int N;

Point p[maxn];

struct node
{
    int v,typ,cost,d;
};

vector<node> edge[maxn];
int dis[maxn][110];
int vis[maxn][110];

struct point{
    int val,id,typ,d;
    point(int id,int val,int typ,int d):id(id),val(val),typ(typ),d(d) {}
    bool operator <(const point &x)const{ 
        return val>x.val;
    }
};

void dijkstra(int s){       //最短路采用Dijkstra
    memset(vis,0,sizeof(vis));
    for(int i=0; i<=N+1; i++)
        for(int j=0;j<=B;j++)
            dis[i][j]=INF;
 
    priority_queue<point> q;
    q.push(point(s,0,0,0));
    vis[s][0]=1;
    dis[s][0]=0;
    while(!q.empty()){
        int cur=q.top().id;
        int typ=q.top().typ;
        int d=q.top().d;
        q.pop();
        vis[cur][d]=1;
        for(int i=0; i < edge[cur].size() ; i++){
            int id=edge[cur][i].v;
            int cost=edge[cur][i].cost;
            int k=edge[cur][i].typ;
            if(d+edge[cur][i].d>B)  continue;
            if(!vis[id][d+edge[cur][i].d]&&dis[id][d+edge[cur][i].d]>dis[cur][d]+cost){
            	dis[id][d+edge[cur][i].d]=dis[cur][d]+cost;
            	q.push(point(id,dis[id][d+edge[cur][i].d],k,d+edge[cur][i].d));
            }
        }
    }
}

int dist(int u,int v)
{
    return (int)(ceil(sqrt((p[u].x-p[v].x)*(p[u].x-p[v].x)+(p[u].y-p[v].y)*(p[u].y-p[v].y))));
}

int Cost(int u,int v,int l){
    return C[l]*dist(u,v);
}

int main() {
    scanf("%d%d",&st.x,&st.y);
    scanf("%d%d",&en.x,&en.y);
    scanf("%d",&B);
    scanf("%d",C);
    scanf("%d",&T);
    rep(i,1,T){
        scanf("%d",C+i);
    }
    scanf("%d",&N);
    p[0]=st;
    p[N+1]=en;
    edge[0].push_back({N+1,0,Cost(0,N+1,0),dist(0,N+1)});
    edge[N+1].push_back({0,0,Cost(0,N+1,0),dist(0,N+1)});
    rep(i,1,N){
        int l,v,tt;
        scanf("%d%d%d",&p[i].x,&p[i].y,&l);
        edge[0].push_back({i,0,Cost(0,i,0),dist(0,i)});
        edge[i].push_back({0,0,Cost(0,i,0),dist(0,i)});
        edge[N+1].push_back({i,0,Cost(N+1,i,0),dist(N+1,i)});
        edge[i].push_back({N+1,0,Cost(N+1,i,0),dist(N+1,i)});
        rep(j,1,l){
            scanf("%d%d",&v,&tt);
            v++;
            edge[i].push_back({v,tt,0,0});
            edge[v].push_back({i,tt,0,0});
        }
    }
    rep(i,1,N){
        for(auto &nod:edge[i]){
            nod.cost=Cost(i,nod.v,nod.typ);
            nod.d=dist(i,nod.v);
        }
    }
    dijkstra(0);
    int ans=INF;
    rep(i,0,B)  ans=min(ans,dis[N+1][i]);
    if(ans==INF)  ans=-1;
    printf("%d\n",ans);
    return 0;
}