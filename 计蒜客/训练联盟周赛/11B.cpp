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

int mp[maxn][maxn];
int dir1[7][2]={{0,0},{-1,0},{-1,-1},{0,-1},{0,1},{1,0},{1,-1}};
int dir2[7][2]={{0,0},{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}};
int h,n,m,num;
map<int,int> mpp;
VI v;

int fa[maxn*maxn],sum[maxn*maxn];


void dfs(int x,int y)
{
    num++;
    mp[x][y]=0;
    for(int k=1;k<=6;k++)
    {
        int xx,yy;
        if(x&1)
        {
            xx=x+dir1[k][0];
            yy=y+dir1[k][1];
        }
        else
        {
            xx=x+dir2[k][0];
            yy=y+dir2[k][1];
        }
        if(xx<=0||yy<=0||xx>n||yy>m)
            continue;
        if(mp[xx][yy]==0)
            continue;
        dfs(xx,yy);
    }
}

// bool check(int x,int y){
//     if(x>=1&&x<=n&&y>=1&&y<=m)  return true;
//     return false;
// }

int main() {
    char c[10];
    scanf("%d%d%d",&h,&n,&m);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%s",c);
            if(c[0]=='.')  mp[i][j]=1;
            else  mp[i][j]=0;
        }
    }
    // v.push_back(0);
    rep(i,1,n){
        rep(j,1,m){
            if(mp[i][j]==1){
                num=0;
                dfs(i,j);
                v.push_back(num);
            }
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    int cnt=v.size();
    int temp=0;
    int tem=0;
    int t=0;
    while(tem<h&&t<cnt)
    {
        temp++;
        tem+=v[t++];
    }
    printf("%d\n",temp);
    return 0;
}