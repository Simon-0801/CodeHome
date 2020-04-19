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
const int maxn = 150 + 5;

int len[maxn];
int vis[maxn][maxn];

PII st,en;
int f;

struct node
{
    PII po;
    int dis;
};

PII upp(PII p){
    int nx=p.first,ny=p.second;
    PII res;
    if(nx==1){
        res=p;
        return res;
    }
    if(len[nx-1]<=ny){
        res.first=nx-1;
        res.second=len[nx-1];
    }
    else{
        res.first=nx-1;
        res.second=ny;
    }
    return res;
}

PII dwn(PII p){
    int nx=p.first,ny=p.second;
    PII res;
    if(nx==f){
        res=p;
        return res;
    }
    if(len[nx+1]<=ny){
        res.first=nx+1;
        res.second=len[nx+1];
    }
    else{
        res.first=nx+1;
        res.second=ny;
    }
    return res;
}

PII lft(PII p){
    int nx=p.first,ny=p.second;
    PII res;
    if(nx==1&&ny==0){
        res=p;
        return res;
    }
    if(ny==0){
        res.first=nx-1;
        res.second=len[nx-1];
    }
    else{
        res.first=nx;
        res.second=ny-1;
    }
    return res;
}

PII rgt(PII p){
    int nx=p.first,ny=p.second;
    PII res;
    if(nx==f&&ny==len[f]){
        res=p;
        return res;
    }
    if(ny==len[nx]){
        res.first=nx+1;
        res.second=0;
    }
    else{
        res.first=nx;
        res.second=ny+1;
    }
    return res;
}

bool check(int x,int y){
    if(x>=1&&x<=f&&y>=0&&y<=len[x])  return true;
    return false;
}

int bfs(){
    queue<node> q;
    mst(vis,0);
    node tmp;
    tmp.po=st;
    tmp.dis=0;
    q.push(tmp);
    while(!q.empty()){
        node tp=q.front();
        q.pop();
        if(tp.po==en){
            return tp.dis;
        }
        PII nxt=upp(tp.po);
        if(!vis[nxt.first][nxt.second]){
            vis[nxt.first][nxt.second]=1;
            tmp.po=nxt;
            tmp.dis=tp.dis+1;
            q.push(tmp);
        }
        nxt=dwn(tp.po);
        if(!vis[nxt.first][nxt.second]){
            vis[nxt.first][nxt.second]=1;
            tmp.po=nxt;
            tmp.dis=tp.dis+1;
            q.push(tmp);
        }
        nxt=lft(tp.po);
        if(!vis[nxt.first][nxt.second]){
            vis[nxt.first][nxt.second]=1;
            tmp.po=nxt;
            tmp.dis=tp.dis+1;
            q.push(tmp);
        }
        nxt=rgt(tp.po);
        if(!vis[nxt.first][nxt.second]){
            vis[nxt.first][nxt.second]=1;
            tmp.po=nxt;
            tmp.dis=tp.dis+1;
            q.push(tmp);
        }
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&f);
        rep(i,1,f){
            scanf("%d",len+i);
        }
        int x,y;
        scanf("%d%d",&x,&y);
        st.first=x;
        st.second=y;
        scanf("%d%d",&x,&y);
        en.first=x;
        en.second=y;
        int ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}