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
const int maxn = 100 + 5;

int h[maxn];
int dpl[maxn],dpr[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&h[i]);
        dpl[i]=dpr[i]=1;
    }
    rep(i,1,n){
        rep(j,1,i-1){
            if(h[i]>h[j]){
                dpl[i]=max(dpl[i],dpl[j]+1);
            }
        }
    }
    repd(i,n,1){
        repd(j,n,i+1){
            if(h[i]>h[j]){
                dpr[i]=max(dpr[i],dpr[j]+1);
            }
        }
    }
    int ans=INF;
    rep(i,1,n){
        ans=min(ans,n-(dpl[i]+dpr[i]-1));
    }
    printf("%d\n",ans);
    return 0;
}