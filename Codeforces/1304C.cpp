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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100 + 5;

ll t[maxn],l[maxn],h[maxn];

int main() {
    int q,n;
    ll m;
    scanf("%d",&q);
    while(q--){
        scanf("%d%I64d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%I64d%I64d%I64d",&t[i],&l[i],&h[i]);
        }
        t[0]=0;
        l[0]=m;
        h[0]=m;
        ll prel=m,preh=m;
        int flag=1;
        for(int i=1;i<=n;i++){
            ll tmp=t[i]-t[i-1];
            ll nowl=prel-tmp;
            ll nowh=preh+tmp;
            ll tmpl=max(nowl,l[i]);
            ll tmph=min(nowh,h[i]);
            if(tmpl>tmph){
                flag=0;
                break;
            }
            prel=tmpl;
            preh=tmph;
        }
        if(flag)  printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}