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

int head[maxn];
int vis[maxn];//在BFS中，标记当前节点是否已经用过 
int dis[maxn];//记录最长距离（即节点的深度）  
 
int n,m,ans;
 
int sum;//记录最长路径的长度 
int lst;//记录最长路径的终点节点 
 
struct node{

    int u,v,w;
    int next;

}edge[maxn];
 
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
                if(sum<dis[edge[i].v]){//用该节点的深度去更新最长路径的值 
                    sum=dis[edge[i].v];
                    lst=edge[i].v;
                } 
            }
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m=n-1;
        getmap();

        //两次bfs找到树的直径
        bfs(1);
        bfs(lst);
        printf("%d\n",n-1-sum);//树的直径以外的边都是割边
    }
    return 0;
}