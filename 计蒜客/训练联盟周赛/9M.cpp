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
const int maxn = 100000 + 5;

int h[maxn];

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    rep(i,1,n){
        scanf("%d",h+i);
    }
    int ans=0;
    rep(l,1,n){
        int r=l+1;
        while(r<=n&&h[r]-h[r-1]<=x)  r++;
        ans=max(r-l,ans);
    }
    printf("%d\n",ans);
    return 0;
}