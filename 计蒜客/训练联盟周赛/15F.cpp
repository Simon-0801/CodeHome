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

struct node
{
    ll x;
    double z;

    bool operator< (const node& a) const{
        return x<a.x;
    }
}p[maxn];


int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lld%lf",&p[i].x,&p[i].z);
    }
    sort(p+1,p+1+n);
    double ans=0;
    rep(i,2,n){
        double tmp=abs(p[i].z-p[i-1].z);
        double tt=abs(p[i].x-p[i-1].x);
        ans=max(ans,tmp/tt);
    }
    printf("%.8lf\n",ans);
    return 0;
}