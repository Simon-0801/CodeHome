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
    int p,a;
    bool operator< (const node&b) const{
        return p<b.p;
    }
}nod[maxn];


int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&nod[i].p,&nod[i].a);
    }
    sort(nod+1,nod+m+1);
    int ans=0;
    rep(i,1,m){
        int tmp=min(n,nod[i].a);
        ans+=tmp*nod[i].p;
        n-=tmp;
        if(n==0)  break;
    }
    printf("%d\n",ans);
    return 0;
}