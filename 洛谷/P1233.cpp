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
const int maxn = 5000 + 5;

struct node
{
    int l,w;

    bool operator< (const node& a) const {
        if(l==a.l)  return w>a.w;
        return l>a.l;
    }
}p[maxn];

int vis[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d%d",&p[i].l,&p[i].w);
    }
    sort(p+1,p+n+1);
    int ans=0;
    int cnt=0;
    while(1){
        int j=0;
        rep(i,1,n){
            if(!vis[i]){
                j=i;
                break;
            }
        }
        if(!j)  break;
        ans++;
        int tl=p[j].l,tw=p[j].w;
        vis[j]=1;
        rep(i,j+1,n){
            if(vis[i])  continue;
            if(tl>=p[i].l&&tw>=p[i].w){
                cnt++;
                tl=p[i].l;
                tw=p[i].w;
                vis[i]=1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}