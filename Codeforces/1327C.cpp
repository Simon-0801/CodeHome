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
const int maxn = 200 + 5;

int sx[maxn],sy[maxn],fx[maxn],fy[maxn];

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,k){
        scanf("%d%d",&sx[i],&sy[i]);
    }
    rep(i,1,k){
        scanf("%d%d",&fx[i],&fy[i]);
    }
    int l=0,r=0,u=0,d=0;
    rep(i,1,k){
        if(sx[i]<fx[i]){
            d=max(d,fx[i]-sx[i]);
        }
        else{
            u=max(u,sx[i]-fx[i]);
        }
        if(sy[i]<fy[i]){
            r=max(r,fy[i]-sy[i]);
        }
        else{
            l=max(l,sy[i]-fy[i]);
        }
    }
    int mn1=min(l,r),mx1=max(l,r);
    int mn2=min(u,d),mx2=max(u,d);
    if(mn1*2+mx1+mn2*2+mx2<=2*n*m){
        if(l<r){
            rep(i,1,l)  printf("L");
            rep(i,1,l+r)  printf("");
        }
    }
    else{
        printf("-1\n");
    }
    return 0;
}