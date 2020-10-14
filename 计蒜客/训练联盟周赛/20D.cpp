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
const int maxn = 100000 + 5;

int d[105];
int tt[205];

int cmp(int a,int b){
    return a>b;
}

int main() {
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        ++cas;
        int c;
        scanf("%d",&c);
        rep(i,0,c-1){
            scanf("%d",d+i);
        }
        rep(i,0,4*c-1){
            scanf("%d",tt+i);
        }
        sort(d,d+c);
        sort(tt,tt+4*c,cmp);
        int ans=0;
        rep(i,0,c-1){
            ans=max(ans,d[i]+tt[i<<2]);
        }
        printf("Trip #%d: %d\n",cas,ans);
    }
    return 0;
}