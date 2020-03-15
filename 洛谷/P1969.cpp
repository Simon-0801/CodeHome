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
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&h[i]);
    }
    int ans=0;
    h[n+1]=0;
    rep(i,2,n+1){
        if(h[i]<h[i-1])  ans+=h[i-1]-h[i];
    }
    printf("%d\n",ans);
    return 0;
}