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

int h[maxn];
int n,a,r,m;

ll solve(int H){
    ll dwn=0,up=0;
    ll res=0;
    rep(i,1,n){
        if(h[i]<H){
            dwn+=0ll+H-h[i];
        }
        else{
            up+=0ll+h[i]-H;
        }
    }
    int mn=min(a+r,m);
    if(up>dwn){
        res+=1ll*dwn*mn;
        res+=1ll*(0ll+up-dwn)*r;
    }
    else{
        res+=1ll*up*mn;
        res+=1ll*(0ll+dwn-up)*a;
    }
    return res;
}

int main() {
    scanf("%d%d%d%d",&n,&a,&r,&m);
    int l=1e9,r=0;
    rep(i,1,n){
        scanf("%d",h+i);
        l=min(l,h[i]);
        r=max(r,h[i]);
    }
    int ansh=0;
    ll ans=1e18;
    while(l<=r){
        int lmid=l+(r-l)/3;
        int rmid=r-(r-l)/3;
        ll tmp1=solve(lmid);
        ll tmp2=solve(rmid);
        if(tmp1>tmp2){
            ansh=rmid;
            ans=tmp2;
            l=lmid+1;
        }
        else{
            ansh=lmid;
            ans=tmp1;
            r=rmid-1;
        }
    }
    // printf("%d\n",ansh);
    printf("%lld\n",ans);
    return 0;
}