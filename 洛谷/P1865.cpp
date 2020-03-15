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

int vis[maxn];
int num[maxn];

void primes(int n){
    mst(vis,0);
    mst(num,0);
    rep(i,2,n){
        if(vis[i])  continue;
        num[i]=1;
        rep(j,i,n/i)  vis[i*j]=1;
    }
}

int main() {
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    primes(m);
    num[0]=0;
    rep(i,1,m){
        num[i]=num[i-1]+num[i];
    }
    rep(i,1,n){
        scanf("%d%d",&l,&r);
        if(!(l>=1&&l<=m&&r>=1&&r<=m))  printf("Crossing the line\n");
        else{
            int ans=num[r]-num[l-1];
            printf("%d\n",ans);
        }
    }
    return 0;
}