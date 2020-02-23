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
const int maxn = 30 + 5;

int n;
ll score[maxn];
ll tmax[maxn][maxn];
int root[maxn][maxn];
// int index;

ll dfs(int l,int r){
    if(root[l][r]){
        return tmax[l][r];
    }
    if(l==r){
        root[l][r]=l;
        return tmax[l][l];
    }
    if(l>r){
        return 1;
    }
    rep(i,l,r){
        ll lans=dfs(l,i-1);
        ll rans=dfs(i+1,r);
        ll tans=lans*rans+score[i];
        if(tans>tmax[l][r]){
            tmax[l][r]=tans;
            root[l][r]=i;
        }
    }
    return tmax[l][r];
}

void print(int l,int r){
    if(l>r){
        return;
    }
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}

int main() {
    scanf("%d",&n);
    mst(tmax,0xcf);
    mst(root,0);
    rep(i,1,n){
        scanf("%lld",&score[i]);
        tmax[i][i]=score[i];
    }
    dfs(1,n);
    printf("%lld\n",tmax[1][n]);
    print(1,n);
    return 0;
}