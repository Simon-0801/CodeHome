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
const int maxn = 500 + 5;

int n,m;
int a[maxn][maxn];
int vis[maxn][maxn];

int dir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};

bool checkpos(int x,int y){             //判断坐标是否合法
    if(x<=n&&x>=1&&y<=m&&y>=1)  return true;
    return false;
}

struct node
{
    int x,y;
    int dis;        //从起点到达该点的步数
};

queue<node> q;

bool check(int height){
    node st;
    st.x=st.y=1;
    st.dis=0;
    while(!q.empty())  q.pop();
    mst(vis,0);
    q.push(st);
    while(!q.empty()){
        node tp=q.front();
        q.pop();
        int x=tp.x,y=tp.y;
        int dis=tp.dis;
        if(vis[x][y])  continue;
        vis[x][y]=1;
        if(a[x][y]-dis>=height){                //洞穴当前高度大于等于height才做拓展
            if(x==n&&y==m)  return true;        //终点可达
            rep(i,1,4){
                int nxtx=x+dir[i][0],nxty=y+dir[i][1];
                if(checkpos(nxtx,nxty)){
                    node nxt;
                    nxt.x=nxtx;
                    nxt.y=nxty;
                    nxt.dis=dis+1;
                    q.push(nxt);
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        rep(i,1,n)
            rep(j,1,m)
                scanf("%d",&a[i][j]);
        int l=1,r=1e9,ans=-1;                   //二分范围[1,1e9]，由于洞穴的高度必须大于0，才能通过，所以不能包括0
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){                     //如果当前高度可行，那么寻找可能的更大的可行高度
                ans=mid;
                l=mid+1;
            }
            else{                               //如果当前高度不可行，那么寻找可能的更小的可行高度
                r=mid-1;
            }
        }
        if(ans==-1)  printf("impossible\n");
        else   printf("%d\n",ans);
    }
    return 0;
}