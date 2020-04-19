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
const int maxn = 400 + 5;

struct node{
	int nxt,w;
};

int c;
int vis[maxn*4];
ll dis[maxn*4];
vector<node> edge[maxn*4];
char str[maxn];
map<string,int> mp;

struct point{
    ll val,id;
    point(ll id,ll val):id(id),val(val) {}
    bool operator <(const point &x)const{ 
        return val>x.val;
    }
};
 
void dijkstra(int s){       //最短路采用Dijkstra
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=4*c; i++)
        dis[i]=INF;
 
    priority_queue<point> q;
    q.push(point(s,0));
    vis[s]=1;
    dis[s]=0;
    while(!q.empty()){
        ll cur=q.top().id;
        q.pop();
        vis[cur]=1;
        for(int i=0; i < edge[cur].size() ; i++){
            ll id=edge[cur][i].nxt;
            ll cost=edge[cur][i].w;
            if(!vis[id]&&dis[id]>dis[cur]+cost){
            	dis[id]=dis[cur]+cost;
            	q.push(point(id,dis[id]));
            }
        }
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int d;
        string s;
        scanf("%d",&c);
        rep(i,1,c*4)  edge[i].clear();
        mp.clear();
        rep(i,1,c){
            scanf("%s",str);
            s=str;
            mp[s]=i;
            scanf("%d",&d);
            node tmp;
            rep(j,0,3){                         //用i，i+c，i+2c，i+3c分别表示城市i中的AIR, SEA, RAIL, TRUCK四种交通方式
                rep(k,j+1,3){                   //四种交通方式两两之间连边，边的权值为切换交通方式的费用
                    tmp.nxt=i+k*c;
                    tmp.w=d;
                    edge[i+j*c].push_back(tmp);
                    tmp.nxt=i+j*c;
                    edge[i+k*c].push_back(tmp);
                }
            }
        }
        int r,u,v;
        scanf("%d",&r);
        rep(i,1,r){
            scanf("%s",str);
            s=str;
            u=mp[s];
            scanf("%s",str);
            s=str;
            v=mp[s];
            scanf("%s",str);
            scanf("%d",&d);
            node tmp;
            if(str[0]=='A'){                    //在两城市对应交通方式的点之间连边
                tmp.nxt=v;
                tmp.w=d;
                edge[u].push_back(tmp);
                tmp.nxt=u;
                edge[v].push_back(tmp);
            }
            else if(str[0]=='S'){
                tmp.nxt=v+c;
                tmp.w=d;
                edge[u+c].push_back(tmp);
                tmp.nxt=u+c;
                edge[v+c].push_back(tmp);
            }
            else if(str[0]=='R'){
                tmp.nxt=v+2*c;
                tmp.w=d;
                edge[u+2*c].push_back(tmp);
                tmp.nxt=u+2*c;
                edge[v+2*c].push_back(tmp);
            }
            else{
                tmp.nxt=v+3*c;
                tmp.w=d;
                edge[u+3*c].push_back(tmp);
                tmp.nxt=u+3*c;
                edge[v+3*c].push_back(tmp);
            }
        }
        scanf("%s",str);
        s=str;
        int st=mp[s];
        scanf("%s",str);
        s=str;
        int en=mp[s];
        ll ans=1e18;
        rep(i,0,3){                             //对起点的四种交通方式的点分别跑最短路
            dijkstra(st+i*c);                   
            rep(j,0,3){                         //取终点处四种交通方式的点的最小值
                ans=min(ans,dis[en+j*c]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}