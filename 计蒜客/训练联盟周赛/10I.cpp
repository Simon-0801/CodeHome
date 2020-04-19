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

struct node
{
    int v;
    ll w;

    bool operator< (const node& nod) const{
        return w>nod.w;
    }
};

vector<node> edge[maxn];

int main() {
    int n,u,v;
    ll w;
    scanf("%d",&n);
    node tmp;
    rep(i,1,n*(n-1)/2){
        scanf("%d%d%lld",&u,&v,&w);
        tmp.v=v;
        tmp.w=w;
        edge[u].push_back(tmp);
        tmp.v=u;
        edge[v].push_back(tmp);
    }
    ll ans=0;
    rep(i,1,n){
        sort(edge[i].begin(),edge[i].end());
        int len=edge[i].size();
        for(int j=0;j<len;j+=2){
            ans+=edge[i][j].w;
        }
    }
    printf("%lld\n",ans);
    return 0;
}