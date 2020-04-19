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

char str[maxn*2];
int pos[maxn*2];

int main() {
    int s;
    scanf("%s",str+1);
    scanf("%d",&s);
    int n=strlen(str+1);
    rep(i,1,n){
        str[i+n]=str[i];
    }
    int tot=0;
    rep(i,1,2*n){
        if(str[i]=='E'){
            pos[++tot]=i;
        }
    }
    ll ans=0;
    rep(i,1,n){
        auto it=lower_bound(pos+1,pos+tot+1,i);
        if(it==pos+tot+1)  break;
        int p=*it;
        if(p-i>=s)  continue;
        ans+=1ll*(i+s-1-p+1);
    }
    printf("%lld\n",ans);
    return 0;
}