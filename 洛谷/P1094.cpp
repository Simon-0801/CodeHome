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
const int maxn = 30000 + 5;

int p[maxn];

int main() {
    int w,n;
    scanf("%d",&w);
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&p[i]);
    }
    sort(p+1,p+n+1);
    int j=1,cnt=0;
    repd(i,n,1){
        if(j==i){
            j++;
            cnt++;
            continue;
        }
        if(j>i)  break;
        if(p[i]+p[j]<=w){
            j++;
            cnt++;
        }
        else  cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}