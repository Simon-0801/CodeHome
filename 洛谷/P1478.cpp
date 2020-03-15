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
    int x,y;

    bool operator< (const node& a) const {
        if(y==a.y)  return x<a.x;
        return y<a.y;
    }
}p[maxn];


int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    int a,b;
    scanf("%d%d",&a,&b);
    rep(i,1,n){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p+1,p+n+1);
    int ans=0;
    rep(i,1,n){
        if(s-p[i].y>=0&&p[i].x<=a+b){
            ans++;
            s-=p[i].y;
        }
    }
    printf("%d\n",ans);
    return 0;
}