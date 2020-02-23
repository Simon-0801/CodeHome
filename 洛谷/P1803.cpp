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
const int maxn = 1000000 + 5;

struct node
{
    int st,en;
    bool operator< (const node&a) const{
        return en<a.en;
    }
}p[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d%d",&p[i].st,&p[i].en);
    }
    sort(p+1,p+n+1);
    int pre=1,cnt=1;
    rep(i,2,n){
        if(p[i].st<p[pre].en)  continue;
        else{
            cnt++;
            pre=i;
        }
    }
    printf("%d\n",cnt);
    return 0;
}