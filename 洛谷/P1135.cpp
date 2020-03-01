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
const int maxn = 200 + 5;

int n,a,b,ans=-1;
int k[maxn];
int vis[maxn];
queue<PII> q;

void bfs(int st,int en){
    mst(vis,0);
    ans=-1;
    PII tmp(st,0);
    q.push(tmp);
    while(!q.empty()){
        PII tp=q.front();
        q.pop();
        int f=tp.first,num=tp.second;
        if(vis[f])  continue;
        vis[f]=1;
        if(f==en){
            ans=num;
            break;
        }
        if(f+k[f]>=1&&f+k[f]<=n){
            q.push(PII(f+k[f],num+1));
        }
        if(f-k[f]>=1&&f-k[f]<=n){
            q.push(PII(f-k[f],num+1));
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&a,&b);
    rep(i,1,n){
        scanf("%d",k+i);
    }
    bfs(a,b);
    printf("%d\n",ans);
    return 0;
}