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
const int maxn = 200000 + 5;

int tag[maxn];
VI team;
VI path;

int head[maxn];
int vis[maxn];//在BFS中，标记当前节点是否已经用过 
int dis[maxn];//记录最长距离（即节点的深度）  
 
int n,m,k,ans;
 
int sum;//记录最长路径的长度 
int lst;//记录最长路径的终点节点 
 
struct node{
 
    int u,v,w;
    int next;
 
}edge[maxn<<2];
 
void add(int u,int v,int w){//向邻接表中加边 
 
    edge[ans].u=u;
    edge[ans].v=v;
    edge[ans].w=w;
    edge[ans].next=head[u];
    head[u]=ans++;
}
 
void getmap(){
 
    int i,j;
    int a,b,c;
    ans=0;
    memset(head,-1,sizeof(head));
 
    while(m--){
 
        scanf("%d%d",&a,&b);
        add(a,b,1);
        add(b,a,1);
    }
}
 
void bfs(int beg){
 
    queue<int> q;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int i,j;
    while(!q.empty())
        q.pop();
    lst=beg;//终点初始化为起点 
    sum=0;
    vis[beg]=1;
    q.push(beg);
    int top;
    while(!q.empty()){
        top=q.front();
        q.pop();
        for(i=head[top];i!=-1;i=edge[i].next){
            if(!vis[edge[i].v]){
                dis[edge[i].v]=dis[top]+edge[i].w;//更新节点深度 
                vis[edge[i].v]=1;
                q.push(edge[i].v);
                if(tag[edge[i].v]&&sum<dis[edge[i].v]){//用该节点的深度去更新最长路径的值 
                    sum=dis[edge[i].v];
                    lst=edge[i].v;
                } 
            }
        }
    }
}

bool dfs(int x,int fa){
    if(x==lst){
        path.push_back(x);
        return true;
    }
    int i;
    path.push_back(x);
    for(i=head[x];i!=-1;i=edge[i].next){
        if(edge[i].v==fa)  continue;
        bool flag=dfs(edge[i].v,x);
        if(flag)  break;
    }
    if(i==-1){
        path.pop_back();
        return false;
    }
    return true;
}

// bool dfs1(int x,int fa){

// }

int main() {
    scanf("%d%d",&n,&k);
    m=n-1;
    getmap();
    int tmp;
    mst(tag,0);
    rep(i,1,k){
        scanf("%d",&tmp);
        team.push_back(tmp);
        tag[tmp]=1;
    }
    if(k==1){
        printf("YES\n%d\n",team[0]);
        return 0;
    }
    bfs(team[0]);
    int st=lst,en,len;
    bfs(lst);
    en=lst;
    len=dis[lst];
    if(len&1){
        printf("NO\n");
        return 0;
    }
    dfs(st,0);
    int sz=path.size();
    int mid=sz/2;
    bfs(path[mid]);
    int f=1;
    rep(i,0,k-2){
        if(dis[team[i]]!=dis[team[i+1]]){
            f=0;
            break;
        }
    }
    if(f)  printf("YES\n%d\n",path[mid]);
    else  printf("NO\n");
    return 0;
}