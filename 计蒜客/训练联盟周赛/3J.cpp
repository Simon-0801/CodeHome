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

int p[maxn],c[maxn];
int vis[maxn];
int m;
map<int,int> mp;

void primes(int n){
    mst(vis,0);
    rep(i,2,n){
        if(vis[i])  continue;
        rep(j,i,n/i){
            vis[i*j]=1;
        }
    }
}

void divide(int n){
    m=0;
    rep(i,2,sqrt(n)){
        if(n%i==0){
            p[++m]=i;
            c[m]=0;
            while(n%i==0)  n/=i,c[m]++;
        }
    }
    if(n>1)  p[++m]=n,c[m]=1;
}

int main() {
    int n;
    scanf("%d",&n);
    primes(n);
    divide(n);
    rep(i,1,m){
        mp[p[i]]=1;
    }
    int ans=1;
    rep(i,2,n-1){
        if(!vis[i]&&!mp[i]){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}