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
const int maxn = 200000 + 5;

int sum[maxn];

int main() {
    int n;
    scanf("%d",&n);
    sum[0]=0;
    rep(i,1,n){
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    int premin=0,ans=-1e9;
    rep(i,1,n){
        ans=max(ans,sum[i]-premin);
        premin=min(premin,sum[i]);
    }
    printf("%d\n",ans);
    return 0;
}