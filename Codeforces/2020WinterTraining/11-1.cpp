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

int vis[maxn];

void primes(int n){
    int index=1;
    mst(vis,0);
    rep(i,2,n){
        if(vis[i])  continue;
        vis[i]=index;
        rep(j,i,n/i){
            vis[i*j]=index;
        }
        index++;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    primes(n);
    rep(i,2,n){
        printf("%d%c",vis[i],i==n?'\n':' ');
    }
    return 0;
}